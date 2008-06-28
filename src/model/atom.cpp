/*
	*** Model atom functions
	*** src/model/atom.cpp
	Copyright T. Youngs 2007,2008

	This file is part of Aten.

	Aten is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Aten is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Aten.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "model/model.h"
#include "classes/atom.h"
#include "classes/undostate.h"
#include "base/elements.h"
#include "base/master.h"

// Return the start of the atom list
Atom *Model::atoms()
{
	return atoms_.first();
}

// Return the number of atoms in the model
int Model::nAtoms()
{
	return atoms_.nItems();
}

// Add atom
Atom *Model::addAtom(short int newel, Vec3<double> pos)
{
	msg.enter("Model::addAtom");
	Atom *newatom = atoms_.add();
	newatom->setElement(newel);
	newatom->setId(atoms_.nItems() - 1);
	newatom->r() = pos;
	mass_ += elements.atomicMass(newel);
	calculateDensity();
	logChange(Change::StructureLog);
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::AtomEvent,newatom);
	}
	msg.exit("Model::addAtom");
	return newatom;
}

// Add atom copy
Atom *Model::addCopy(Atom *source)
{
	msg.enter("Model::addCopy");
	Atom *newatom = atoms_.add();
	newatom->copy(source);
	newatom->setId(atoms_.nItems() - 1);
	logChange(Change::StructureLog);
	mass_ += elements.atomicMass(newatom->element());
	calculateDensity();
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::AtomEvent,newatom);
	}
	msg.exit("Model::addCopy");
	return newatom;
}

// Add atom copy at specified position in list
Atom *Model::addCopy(Atom *afterthis, Atom *source)
{
	msg.enter("Model::addCopy");
	Atom *newatom = atoms_.insert(afterthis);
	//printf("Adding copy after... %li %li\n",afterthis,source);
	newatom->copy(source);
	renumberAtoms( (afterthis != NULL ? afterthis->prev : NULL) );
	logChange(Change::StructureLog);
	mass_ += elements.atomicMass(newatom->element());
	calculateDensity();
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::AtomEvent,newatom);
	}
	msg.exit("Model::addCopy");
	return newatom;
}

// Remove atom
void Model::removeAtom(Atom *xatom)
{
	msg.enter("Model::removeAtom");
	// Delete a specific atom (passed as xatom)
	mass_ -= elements.atomicMass(xatom->element());
	if (mass_ < 0.0) mass_ = 0.0;
	calculateDensity();
	// Renumber the ids of all atoms in the list after this one
	for (Atom *i = xatom->next; i != NULL; i = i->next) i->decreaseId();
	if (xatom->isSelected()) deselectAtom(xatom);
	logChange(Change::StructureLog);
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(-Change::AtomEvent,xatom);
	}
	atoms_.remove(xatom);
	msg.exit("Model::removeAtom");
}

// Delete Atom
void Model::deleteAtom(Atom *xatom)
{
	msg.enter("Model::deleteAtom");
	// The atom may be present in other, unassociated lists (e.g. measurements), so we must
	// also check those lists for this atom and remove it.
	if (xatom == NULL) msg.print("No atom to delete.\n");
	else
	{
		// Remove measurements
		removeMeasurements(xatom);
		// Delete All Bonds To Specific Atom
		Refitem<Bond,int> *bref = xatom->bonds();
		while (bref != NULL)
		{
			// Need to detach the bond from both atoms involved
			Bond *b = bref->item;
			Atom *j = b->partner(xatom);
			unbondAtoms(xatom,j,b);
			bref = xatom->bonds();
		}
		// Finally, delete the atom
		removeAtom(xatom);
	}
	msg.exit("Model::deleteAtom");
}

// Transmute atom
void Model::transmuteAtom(Atom *i, short int el)
{
	msg.enter("Model::transmuteAtom");
	if (i == NULL) msg.print("No atom to transmute.\n");
	else
	{
		short int oldel = i->element();
		if (oldel != el)
		{
			mass_ -= elements.atomicMass(i);
			i->setElement(el);
			mass_ += elements.atomicMass(i);
			calculateDensity();
			logChange(Change::StructureLog);
			// Add the change to the undo state (if there is one)
			if (recordingState_ != NULL)
			{
				Change *newchange = recordingState_->addChange();
				newchange->set(Change::TransmuteEvent,i->id(),oldel,el);
			}
		}
	}
	msg.exit("Model::transmuteAtom");
}

// Return (and autocreate if necessary) the static atoms array
Atom **Model::atomArray()
{
	return atoms_.array();
}

// Clear atoms
void Model::clearAtoms()
{
	msg.enter("Model::clearAtoms");
	Atom *i = atoms_.first();
	while (i != NULL)
	{
		deleteAtom(i);
		i = atoms_.first();
	}
	msg.exit("Model::clearAtoms");
}

// Find atom
Atom *Model::findAtom(int id)
{
	// Find an atom according to its internal id (useful when atom ids may have been set differently by import filters)
	Atom *i;
	for (i = atoms_.first(); i != NULL; i = i->next) if (id == i->id()) break;
	return i;
}

// Find atom by tempi
Atom *Model::findAtomByTempi(int tempi)
{
	// Find an atom according to its tempi value
	for (Atom *i = atoms_.first(); i != NULL; i = i->next) if (i->tempi == tempi) return i;
	return NULL;
}

// Return the list index of the specified atom
int Model::atomIndex(Atom *i)
{
	return atoms_.indexOf(i);
}

// Renumber Atoms
void Model::renumberAtoms(Atom *from)
{
	msg.enter("Model::renumberAtoms");
	static int count;
	static Atom *i;
	if (from == NULL)
	{
		count = 0;
		i = atoms_.first();
	}
	else
	{
		count = from->id();
		i = from->next;
	}
	for (i = i; i != NULL; i = i->next)
	{
		i->setId(count);
		count ++;
	}
	msg.exit("Model::renumberAtoms");
}

// Return atom 'n' in the model
Atom *Model::atom(int n)
{
	msg.enter("Model::atom");
	// Check range first
	if ((n < 0) || (n >= atoms_.nItems()))
	{
		msg.print("Atom id '%i' is out of range for model '%s'.\n", n+1, name_.get());
		msg.exit("Model::atom");
		return NULL;
	}
	msg.exit("Model::atom");
	return atoms_[n];
}

// Reset forces on all atoms
void Model::zeroForces()
{
	msg.enter("Model::zeroForces");
	for (Atom *i = atoms_.first(); i != NULL; i = i->next) i->f().zero();
	msg.exit("Model::zeroForces");
}

// Reset forces on all fixed atoms
void Model::zeroForcesFixed()
{
	msg.enter("Model::zeroForcesFixed");
	for (Atom *i = atoms_.first(); i != NULL; i = i->next) if (i->hasFixedPosition()) i->f().zero();
	msg.exit("Model::zeroForcesFixed");
}

// Set visibility of specified atom
void Model::setHidden(Atom *i, bool hidden)
{
	i->setHidden(hidden);
	logChange(Change::VisualLog);
}

// Normalise forces
void Model::normaliseForces(double norm)
{
	// 'Normalise' the forces in linecfg such that the largest force is equal to the maximum cartesian step size
	msg.enter("Model::normaliseForces");
	double maxfrc;
	static Vec3<double> f;
	Atom **modelatoms = atomArray();
	int i;
	// Find the largest force
	maxfrc = 0.0;
	for (i=0; i<atoms_.nItems(); i++)
	{
		f = modelatoms[i]->f();
		if (fabs(f.x) > maxfrc) maxfrc = fabs(f.x);
		if (fabs(f.y) > maxfrc) maxfrc = fabs(f.y);
		if (fabs(f.z) > maxfrc) maxfrc = fabs(f.z);
	}
	// Normalise with respect to this force
	maxfrc *= norm;
	for (i=0; i<atoms_.nItems(); i++) modelatoms[i]->f() /= maxfrc;
	msg.exit("Model::normaliseForces");
}

// Move specified atom (channel for undo/redo)
void Model::translateAtom(Atom *target, Vec3<double> delta)
{
	target->r() += delta;
	logChange(Change::CoordinateLog);
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::TranslateEvent,target->id());
		newchange->set(Change::TranslateEvent,&delta);
	}
}

// Position specified atom (channel for undo/redo)
void Model::positionAtom(Atom *target, Vec3<double> newr)
{
	static Vec3<double> delta;
	delta = newr - target->r();
	target->r() = newr;
	logChange(Change::CoordinateLog);
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::TranslateEvent,target->id());
		newchange->set(Change::TranslateEvent,&delta);
	}
}

// Set charge of specified atom
void Model::chargeAtom(Atom *target, double q)
{
	double oldcharge = target->charge();
	target->setCharge(q);
	logChange(Change::CoordinateLog);
	// Add the change to the undo state (if there is one)
	if (recordingState_ != NULL)
	{
		Change *newchange = recordingState_->addChange();
		newchange->set(Change::ChargeEvent, target->id());
		newchange->set(Change::ChargeEvent, oldcharge, q);
	}
}


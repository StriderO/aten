/*
	*** Atom Commands
	*** src/nucommand/atom.cpp
	Copyright T. Youngs 2007-2009

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

#include "nucommand/commands.h"
#include "parser/commandnode.h"
#include "model/model.h"
#include "base/elements.h"

// Set atom style for current selection
bool NuCommand::function_AtomStyle(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	Atom::DrawStyle ds = Atom::drawStyle(c->argc(0));
	if (ds == Atom::nDrawStyles) return FALSE;
	if (c->hasArg(1))
	{
		Atom *i = obj.rs->atom(c->argi(1)-1);
		if (i == NULL) return FALSE;
		obj.rs->beginUndoState("Style individual atom");
		obj.rs->styleAtom(i, ds);
		obj.rs->endUndoState();
	}
	else
	{
		obj.rs->beginUndoState("Style atom selection");
		obj.rs->styleSelection(ds);
		obj.rs->endUndoState();
	}
	rv.reset();
	return TRUE;
}

// Retrieve atom info ('getatom <id> [var]')
bool NuCommand::function_GetAtom(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	Atom *i = obj.rs->atom(c->argi(0)-1);
	if (i == NULL) return FALSE;
	// Set atom information
	obj.i = i;
	rv.set(NuVTypes::AtomData, i);
	return TRUE;
}

// Hide current atom selection
bool NuCommand::function_Hide(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	obj.rs->selectionSetHidden(TRUE);
	rv.reset();
	return TRUE;
}

// Set current atom charge
bool NuCommand::function_SetCharge(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->setCharge(c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom coordinates
bool NuCommand::function_SetCoords(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(3)) obj.i = obj.rs->atom(c->argi(3) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.rs->positionAtom(obj.i, c->arg3d(0));
	rv.reset();
	return TRUE;
}

// Set current atom element
bool NuCommand::function_SetElement(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->setElement(elements().findAlpha(c->argc(0)));
	rv.reset();
	return TRUE;
}

// Set current atom forces
bool NuCommand::function_SetForces(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(3)) obj.i = obj.rs->atom(c->argi(3) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->f() = c->arg3d(0);
	rv.reset();
	return TRUE;
}

// Set current atom x force
bool NuCommand::function_SetFX(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->f().set(0,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom y force
bool NuCommand::function_SetFY(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->f().set(1,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom z force
bool NuCommand::function_SetFZ(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->f().set(2,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom ID
bool NuCommand::function_SetId(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->setId(c->argi(0));
	rv.reset();
	return TRUE;
}

// Set current atom x coordinate
bool NuCommand::function_SetRX(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->r().set(0,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom y coordinate
bool NuCommand::function_SetRY(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->r().set(1,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom z coordinate
bool NuCommand::function_SetRZ(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->r().set(2,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom velocities
bool NuCommand::function_SetVelocities(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(3)) obj.i = obj.rs->atom(c->argi(3) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->v() = c->arg3d(0);
	rv.reset();
	return TRUE;
}

// Set current atom x velocity
bool NuCommand::function_SetVX(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->v().set(0,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom y velocity
bool NuCommand::function_SetVY(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->v().set(1,c->argd(0));
	rv.reset();
	return TRUE;
}

// Set current atom z velocity
bool NuCommand::function_SetVZ(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	if (c->hasArg(1)) obj.i = obj.rs->atom(c->argi(1) - 1);
	if (obj.notifyNull(Bundle::AtomPointer)) return FALSE;
	obj.i->v().set(2,c->argd(0));
	rv.reset();
	return TRUE;
}

// Show current atom selection
bool NuCommand::function_Show(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	obj.rs->selectionSetHidden(FALSE);
	rv.reset();
	return TRUE;
}

// Show all atoms
bool NuCommand::function_ShowAll(NuCommandNode *c, Bundle &obj, NuReturnValue &rv)
{
	if (obj.notifyNull(Bundle::ModelPointer)) return FALSE;
	for (Atom *i = obj.rs->atoms(); i != NULL; i = i->next) obj.rs->setHidden(i,FALSE);
	rv.reset();
	return TRUE;
}
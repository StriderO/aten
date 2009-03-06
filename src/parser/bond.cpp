/*
	*** Bond Variable
	*** src/parser/bond.cpp
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

#include "parser/bond.h"
#include "parser/stepnode.h"
#include "base/bond.h"
#include "base/constants.h"
#include "base/elements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constructor
BondVariable::BondVariable(Bond *ptr, bool constant) : bondData_(ptr)
{
	// Private variables
	returnType_ = NuVTypes::BondData;
	readOnly_ = constant;
}

// Destructor
BondVariable::~BondVariable()
{
}

/*
// Set / Get
*/

// Set value of variable
bool BondVariable::set(NuReturnValue &rv)
{
	if (readOnly_)
	{
		msg.print("A constant value (in this case a bond&) cannot be assigned to.\n");
		return FALSE;
	}
	bool success;
	bondData_ = rv.asPointer(NuVTypes::BondData, success);
	return success;
}

// Reset variable
void BondVariable::reset()
{
	bondData_ = NULL;
}

// Return value of node
bool BondVariable::execute(NuReturnValue &rv)
{
	// If this vector is a constant, read the three stored expressions to recreate it
	rv.set(NuVTypes::BondData, bondData_);
	return TRUE;
}

// Print node contents
void BondVariable::nodePrint(int offset, const char *prefix)
{
	// Construct tabbed offset
	char *tab;
	tab = new char[offset+32];
	tab[0] = '\0';
	for (int n=0; n<offset-1; n++) strcat(tab,"\t");
	if (offset > 1) strcat(tab,"   |--> ");
	strcat(tab,prefix);
	// Output node data
	if (readOnly_) printf("[C]%s%li (bond) (constant value)\n", tab, bondData_);
	else printf("[V]%s%li (bond) (variable, name=%s)\n", tab, bondData_, name_.get());
	delete[] tab;
}

/*
// Accessors
*/

// Accessor data
Accessor BondVariable::accessorData[BondVariable::nAccessors] = {
	{ "i",		NuVTypes::AtomData,	 FALSE, TRUE },
	{ "j",		NuVTypes::AtomData,	 FALSE, TRUE },
	{ "order",	NuVTypes::RealData,	 FALSE, TRUE },
	{ "type",	NuVTypes::CharacterData, FALSE, TRUE }
};

// Search variable access list for provided accessor (call private static function)
StepNode *BondVariable::findAccessor(const char *s)
{
	return BondVariable::accessorSearch(s);
}

// Private static function to search accessors
StepNode *BondVariable::accessorSearch(const char *s)
{
	msg.enter("BondVariable::accessorSearch");
	StepNode *result = NULL;
	int i = 0;
	for (i = 0; i < nAccessors; i++) if (strcmp(accessorData[i].name,s) == 0) break;
	if (i == nAccessors)
	{
		msg.print("Error: Type 'bond&' has no member named '%s'.\n", s);
		msg.exit("BondVariable::accessorSearch");
		return NULL;
	}
	// Create a suitable AccessNode to return...
	printf("Accessor match = %i\n", i);
	result = new StepNode(i, NuVTypes::BondData, accessorData[i].returnType, accessorData[i].isReadOnly);
	msg.exit("BondVariable::accessorSearch");
	return result;
}

// Retrieve desired value
bool BondVariable::retrieveAccessor(int i, NuReturnValue &rv, bool hasArrayIndex, int arrayIndex)
{
	msg.enter("BondVariable::retrieveAccessor");
	// Cast 'i' into Accessors enum value
	if ((i < 0) || (i >= nAccessors))
	{
		printf("Internal Error: Accessor id %i is out of range for Bond type.\n");
		msg.exit("BondVariable::retrieveAccessor");
		return FALSE;
	}
	Accessors acc = (Accessors) i;
	// Check for correct lack/presence of array index given
	if (!accessorData[i].isArray)
	{
		if (hasArrayIndex) msg.print("Warning: Irrelevent array index provided for member '%s'.\n", accessorData[i].name);
	}
	else if (!hasArrayIndex)
	{
		msg.print("Error: No array index provided for member '%s'.\n", accessorData[i].name);
		msg.exit("BondVariable::retrieveAccessor");
		return FALSE;
	}
	// Get current data from ReturnValue
	bool result = TRUE;
	Bond *ptr= (Bond*) rv.asPointer(NuVTypes::BondData, result);
	if (result) switch (acc)
	{
		case (BondVariable::I):
			rv.set(NuVTypes::AtomData, ptr->atomI());
			break;
		case (BondVariable::J):
			rv.set(NuVTypes::AtomData, ptr->atomJ());
			break;
		case (BondVariable::Order):
			rv.set(ptr->order());
			break;
		case (BondVariable::Type):
			rv.set(Bond::bondType(ptr->type()));
			break;
		default:
			printf("Internal Error: Access to member '%s' has not been defined in BondVariable.\n", accessorData[i].name);
			result = FALSE;
			break;
	}
	msg.exit("BondVariable::retrieveAccessor");
	return result;
}

/*
// Set specified data
bool BondVariable::set(void *classptr, AccessStep *step, Variable *srcvar)
{
	msg.enter("BondVariable::set");
	bool result = TRUE;
	// Cast pointer into Bond*
	Bond *i = (Bond*) classptr;
	if (i == NULL) printf("Warning - NULL Bond pointer passed to BondVariable::set.\n");
// 	printf("Enumerated ID supplied to BondVariable is %i.\n", vid);
	// Check range of supplied vid
	int vid = step->variableId();
	if ((vid < 0) || (vid > BondVariable::nAccessors))
	{
		printf("Unknown enumeration %i given to BondVariable::set.\n", vid);
		msg.exit("BondVariable::set");
		return FALSE;
	}
	// Check read-only status
	if (accessorPointers[vid]->readOnly())
	{
		msg.print("Member '%s' of 'bond' type is read-only.\n", accessorPointers[vid]->name());
		msg.exit("BondVariable::set");
		return FALSE;
	}
	// Get arrayindex (if there is one) and check that we needed it in the first place
	int index;
	if (!checkIndex(index, step, accessorPointers[vid]))
	{
		msg.exit("BondVariable::set");
		return FALSE;
	}
	// Set value based on enumerated id
	switch (vid)
	{
		default:
			printf("BondVariable::set doesn't know how to use member '%s'.\n", accessorPointers[vid]->name());
			result = FALSE;
			break;
	}
	msg.exit("BondVariable::set");
	return result;
}
*/

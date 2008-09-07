/*
	*** Integer Variable
	*** src/variables/integer.cpp
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

#include "variables/integer.h"
#include "base/sysfunc.h"
#include "base/constants.h"
#include "base/messenger.h"
#include <stdio.h>
#include <stdlib.h>

// Constructor
IntegerVariable::IntegerVariable()
{
	// Private variables
	dataType_ = VTypes::IntegerData;
	integerData_ = 0;
	integerArrayData_ = NULL;
	arraySize_ = -1;
}

/*
// Set / Get
*/

// Set value of variable (char)
bool IntegerVariable::set(const char *s, int index)
{
	return set( atoi(s) );
}

// Set value of variable (int)
bool IntegerVariable::set(int i, int index)
{
	// Check read/write status
	if (readOnly_)
	{
		msg.print("Variable '%s' is read-only.\n", name_.get());
		return FALSE;
	}
	bool outofbounds = FALSE;
	// Check array index given
	if (index == -1)
	{
		if (arraySize_ != -1)
		{
			msg.print("No array index given to array '%s'.\n", name_.get());
			return FALSE;
		}
		integerData_ = i;
	}
	else
	{
		if (arraySize_ == -1)
		{
			msg.print("Array index given to variable '%s'.\n", name_.get());
			return FALSE;
		}
		if ((index > arraySize_) || (index < 1))
		{
			msg.print("Array index %i is out of bounds for array '%s'.\n", index, name_.get());
			return FALSE;
		}
		else integerArrayData_[index-1] = i;
	}
	return TRUE;
}

// Set value of variable (double)
bool IntegerVariable::set(double d, int index)
{
	return set( (int) d);
}

// Set value of variable (pointer)
bool IntegerVariable::set(void *ptr, VTypes::DataType type, int index)
{
	printf("An Integer variable cannot be set from a pointer.\n");
	return FALSE;
}

// Get value of variable as character string
const char *IntegerVariable::asCharacter(int index)
{
	return itoa(asInteger(index));
}

// Get value of variable as integer
int IntegerVariable::asInteger(int index)
{
	// Check array index given
	if (index == -1)
	{
		if (arraySize_ != -1)
		{
			msg.print("No array index given to array '%s'.\n", name_.get());
			return FALSE;
		}
		return integerData_;
	}
	else
	{
		if (arraySize_ == -1)
		{
			msg.print("Array index given to variable '%s'.\n", name_.get());
			return FALSE;
		}
		if ((index > arraySize_) || (index < 1))
		{
			msg.print("Array index %i is out of bounds for array '%s'.\n", index, name_.get());
			return FALSE;
		}
		return integerArrayData_[index-1];
	}
}

// Get value of variable as double
double IntegerVariable::asDouble(int index)
{
	return (double) asInteger(index);
}

// Get value of variable as float
float IntegerVariable::asFloat(int index)
{
	return (float) asInteger(index);
}

// Get value of variable as a boolean
bool IntegerVariable::asBool(int index)
{
	return (asInteger(index) < 1 ? FALSE : TRUE);
}

// Get value of variable as pointer of specified type
void *IntegerVariable::asPointer(VTypes::DataType type, int index)
{
	printf("An Integer variable cannot be returned as a pointer.\n");
	return NULL;
}

// Step variable
bool IntegerVariable::step(int delta, int index)
{
	// Check array index given
	if (index == -1)
	{
		if (arraySize_ != -1)
		{
			msg.print("No array index given to array '%s'.\n", name_.get());
			return FALSE;
		}
		integerData_ += delta;
	}
	else
	{
		if (arraySize_ == -1)
		{
			msg.print("Array index given to variable '%s'.\n", name_.get());
			return FALSE;
		}
		if ((index > arraySize_) || (index < 1))
		{
			msg.print("Array index %i is out of bounds for array '%s'.\n", index, name_.get());
			return FALSE;
		}
		integerArrayData_[index-1] += delta;
	}
	return TRUE;
}

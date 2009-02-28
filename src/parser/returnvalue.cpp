/*
	*** Tree Return Value
	*** src/parser/treevalue.cpp
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

#include "parser/returnvalue.h"
#include "base/messenger.h"
#include "base/sysfunc.h"
#include <stdio.h>
#include <stdlib.h>

// Constructor
NuReturnValue::NuReturnValue()
{
	// Private variables
	type_ = NuVTypes::NoData;
}

// Operator =
void NuReturnValue::operator=(NuReturnValue &source)
{
	// Copy datatype of source
	type_ = source.type_;
	// To reduce unnecessary object creation/destruction, only copy the contents that corresponds to the type_
	switch (type_)
	{
		case (NuVTypes::NoData):
			break;
		case (NuVTypes::IntegerData):
			valueI_ = source.valueI_;
			break;
		case (NuVTypes::RealData):
			valueR_ = source.valueR_;
			break;
		case (NuVTypes::CharacterData):
			valueC_ = source.valueC_;
			break;
		default:
			printf("NuReturnValue::operator= - unrecognised variable type.\n");
			break;
	}
}

// Return type of the stored data
NuVTypes::DataType NuReturnValue::type()
{
	return type_;
}

// Reset data
void NuReturnValue::reset()
{
	type_ = NuVTypes::NoData;
}

// Print info on data contents
void NuReturnValue::info()
{
	printf("This returnvalue contains data of type '%s':", NuVTypes::dataType(type_));
	switch (type_)
	{
		case (NuVTypes::NoData):
			printf("<nothing>\n");
			break;
		case (NuVTypes::IntegerData):
			printf("%i\n",valueI_);
			break;
		case (NuVTypes::RealData):
			printf("%f\n",valueR_);
			break;
		case (NuVTypes::CharacterData):
			printf("%s\n",valueC_.get());
			break;
		default:
			printf("<Don't know how to print this data type>\n");
			break;
	}
}

/*
// Set
*/

// Set from integer value
void NuReturnValue::set(int i)
{
	type_ = NuVTypes::IntegerData;
	valueI_ = i;
}

// Set from double value
void NuReturnValue::set(double d)
{
	type_ = NuVTypes::RealData;
	valueR_ = d;
}

// Set from character value
void NuReturnValue::set(const char *s)
{
	type_ = NuVTypes::CharacterData;
	valueC_ = s;
}

/*
// Get
*/

// Return as integer value
int NuReturnValue::asInteger()
{
	switch (type_)
	{
		case (NuVTypes::NoData):
			printf("Internal error: No data in ReturnValue to return as an integer!\n");
			return 0;
			break;
		case (NuVTypes::IntegerData):
			return valueI_;
			break;
		case (NuVTypes::RealData):
			return (int)valueR_;
			break;
		case (NuVTypes::CharacterData):
			return atoi(valueC_.get());
			break;
		default:
			printf("NuReturnValue::asInteger() doesn't recognise this type.\n");
			break;
	}
	return 0;
}

// Return as real value
double NuReturnValue::asReal()
{
	switch (type_)
	{
		case (NuVTypes::NoData):
			printf("Internal error: No data in ReturnValue to return as a real!\n");
			return 0;
			break;
		case (NuVTypes::IntegerData):
			return (double)valueI_;
			break;
		case (NuVTypes::RealData):
			return valueR_;
			break;
		case (NuVTypes::CharacterData):
			return atof(valueC_.get());
			break;
		default:
			printf("NuReturnValue::asInteger() doesn't recognise this type.\n");
			break;
	}
	return 0;
}

// Return as character value
const char *NuReturnValue::asCharacter()
{
	switch (type_)
	{
		case (NuVTypes::NoData):
			printf("Internal error: No data in ReturnValue to return as a character!\n");
			return "_NULL_";
			break;
		case (NuVTypes::IntegerData):
			return itoa(valueI_);
			break;
		case (NuVTypes::RealData):
			return ftoa(valueR_);
			break;
		case (NuVTypes::CharacterData):
			return valueC_.get();
			break;
		default:
			printf("NuReturnValue::asInteger() doesn't recognise this type.\n");
			break;
	}
	return 0;
}
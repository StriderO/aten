/*
	*** Double Variable and Array
	*** src/parser/double.h
	Copyright T. Youngs 2007-2018

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

#ifndef ATEN_DOUBLEVARIABLE_H
#define ATEN_DOUBLEVARIABLE_H

#include "parser/variable.h"
#include "parser/accessor.h"
#include "base/namespace.h"

ATEN_BEGIN_NAMESPACE

// Double Variable
class DoubleVariable : public Variable
{
	public:
	// Constructor / Destructor
	DoubleVariable(double d = 0.0, bool constant = false);
	~DoubleVariable();

	/*
	 * Set / Get
	 */
	public:
	// Return value of node
	bool execute(ReturnValue& rv);
	// Set from returnvalue node
	bool set(ReturnValue& rv);
	// Set from double data
	bool setFromDouble(double d);
	// Reset node
	void reset();

	/*
	 * Variable Data
	 */
	private:
	// Real data
	double doubleData_;
	// Print node contents
	void nodePrint(int offset, const char* prefix = "");
};

// Double Array Variable
class DoubleArrayVariable : public ArrayVariable
{
	public:
	// Constructor / Destructor
	DoubleArrayVariable(TreeNode* sizeexpr, bool constant = false);
	~DoubleArrayVariable();

	/*
	 * Set / Get
	 */
	public:
	// Return value of node
	bool execute(ReturnValue& rv);
	// Return value of node as array
	bool executeAsArray(ReturnValue& rv, int arrayIndex);
	// Set from returnvalue node
	bool set(ReturnValue& rv);
	// Set from returnvalue node as array
	bool setAsArray(ReturnValue& rv, int arrayIndex);
	// Reset variable
	void reset();

	/*
	 * Variable Data
	 */
	private:
	// Real data
	double* doubleArrayData_;
	// Print node contents
	void nodePrint(int offset, const char* prefix);

	public:
	// Return array pointer
	double* arrayData();

	/*
	 * Inherited Virtuals
	 */
	public:
	// Initialise node (take over from Variable::initialise())
	bool initialise();
};

ATEN_END_NAMESPACE

#endif

/*
	*** UndoState
	*** src/classes/undostate.h
	Copyright T. Youngs 2007,2008

	This file is part of Aten.

	Aten is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Aten is distributed in the hope that it will be useful,
	but WITHOUE ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Aten.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ATEN_UNDOSTATE_H
#define ATEN_UNDOSTATE_H

#include "classes/undoevent.h"
#include "classes/dnchar.h"
#include "classes/log.h"
#include "templates/list.h"
#include "templates/vector3.h"
#include "templates/matrix3.h"

// Forward declarations
class Model;
class Atom;

// UndoState (series of UndoEvents)
class UndoState
{
	public:
	// Constructor
	UndoState();
	// List pointers
	UndoState *prev, *next;

	/*
	// Changelist
	*/
	private:
	// List of atomic changes for this level
	List<UndoEvent> events_;
	// Short text describing the change
	Dnchar description_;
	// Logs at start of state
	Log startLogs_;
	// Logs at end of state
	Log endLogs_;

	public:
	// Add event to state
	void addEvent(UndoEvent *ue);
	// Return number of changes in list
	int nChanges();
	// Set logs at start of state
	void setStartLogs(Log source);
	// Get structure log point at start of state
	int startLog(Log::LogType log);
	// Set logs at end of state
	void setEndLogs(Log source);
	// Get structure log point at end of state
	int endLog(Log::LogType log);
	// Check difference between Change::StructureLog and Change::CoordinateLog between start/end points
	bool doLogsDiffer();
	// Set the text associated with the current undo state
	void setDescription(const char *s);
	// Return the current text associated with the state
	const char *description();
	// Undo the changes specified in the state
	void undo(Model *m);
	// Redo the changes specified in the state
	void redo(Model *m);
	// Print changes captured in state
	void print();
};

#endif

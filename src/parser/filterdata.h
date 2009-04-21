/*
	*** Filter Data
	*** src/parser/filterdata.h
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

#ifndef ATEN_FILTERDATA_H
#define ATEN_FILTERDATA_H

#include <iostream>
#include "parser/returnvalue.h"
#include "parser/variable.h"
#include "nucommand/commands.h"
#include "templates/namemap.h"
#include "templates/list.h"
#include "templates/reflist.h"
#include "base/dnchar.h"
#include "base/elements.h"
#include "base/lineparser.h"

// FilterData
class FilterData
{
	public:
	// Constructor / Destructor
	FilterData();
	~FilterData();
	// Filter Types
	enum FilterType { ModelImport, TrajectoryImport, ExpressionImport, GridImport, ModelExport, TrajectoryExport, ExpressionExport, GridExport, nFilterTypes };
	static const char *filterType(FilterType ft);
	static FilterType filterType(const char *s, bool quiet = FALSE);
	// Filter commands
	enum FilterOption { ExactOption, ExtensionOption, GlobOption, IdOption, NameOption, NicknameOption, SearchOption, TypeOption, WithinOption, ZMapOption, nFilterOptions };
	static FilterOption filterOption(const char *s);
	static const char *filterOption(FilterOption fo);


	/*
	// Properties
	*/
	private:
	// Filter ID
	int id_;
	// Type of data the filter describes
	FilterType type_;
	// Long name of the filter
	Dnchar name_;
	// Nickname for the filter
	Dnchar nickname_;
	// File extension(s)
	List<Dnchar> extensions_;
	// Number of lines to search when looking for any of the searchStrings_
	int nLinesToSearch_;
	// List of identifying search strings
	List<Dnchar> searchStrings_;
	// File filter glob (for gui)
	Dnchar glob_;
	// Partner filter
	Tree *partner_;
	// Filter description
	Dnchar description_;
	// Filename alias list
	List<Dnchar> exactNames_;
	// Whether the file has an associated extension
	bool hasExtension_;
	// Whether separate zmapping has been defined
	bool hasZmapping_;
	// Type of element mapping to use
	ElementMap::ZMapType zMapType_;
	// Pointer to trajectory header read/write routine (for trajectory filters)
	Tree *headerFunction_;
	// Pointer to trajectory frame read/write routine (for trajectory filters)
	Tree *frameFunction_;


	/*
	// Set
	*/
	public:
	// Set option by name
	bool setOption(Dnchar *name, TreeNode *value);
	// Set the type of filter
	void setType(FilterType ft);
	// Set the partner filter
	void setPartner(Tree *partner);
	// Set trajectory header function
	void setTrajectoryHeaderFunction(Tree *func);
	// Set trajectory frame function
	void setTrajectoryFrameFunction(Tree *func);


	/*
	// Get
	*/
	public:
	// Return the ID of the filter
	int id();
	// Return the descriptive name of the filter
	const char *name();
	// Return the short nickname of the filter
	const char *nickname();
	// Return the first file extension
	Dnchar *extensions();
	// Return the first alias
	Dnchar *exactNames();
	// Return the number of identifying strings defined
	int nIdStrings();
	// Return the number of lines to search for the identifying strings
	int nLinesToSearch();
	// Return the first identifying search string
	Dnchar *searchStrings();
	// Return whether filter has an extension
	bool hasExtension();
	// Return the partner filter
	Tree *partner();
	// Return the file filter
	const char *glob();
	// Return the type of filter
	FilterType type();
	// Return the long description of the filter (including glob)
	const char *description();
	// Return trajectory header function
	Tree *trajectoryHeaderFunction();
	// Return trajectory frame function
	Tree *trajectoryFrameFunction();
};

#endif

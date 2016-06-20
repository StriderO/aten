/*
        *** Common functions for XYZ plugins
        *** src/plugins/io_xyz/common.h
        Copyright T. Youngs 2016-2016

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

#ifndef ATEN_XYZFILEPLUGINCOMMON_H
#define ATEN_XYZFILEPLUGINCOMMON_H

#include "base/kvmap.h"

ATEN_BEGIN_NAMESPACE

// Forward Declarations
class Model;
class FileParser;

// XYZ Plugin Common Functions
class XYZFilePluginCommon
{
	public:
	// Read single XYZ model from file
	static bool readXYZModel(FilePluginInterface* interface, FileParser& parser, Model* targetModel);
	// Skip single XYZ model in file
	static bool skipXYZModel(FilePluginInterface* interface, FileParser& parser);
	// Write single XYZ model to file
	static bool writeXYZModel(FilePluginInterface* interface, FileParser& parser, Model* sourceModel);
};

ATEN_END_NAMESPACE

#endif

/*
	*** Disorder command functions
	*** src/command/disorder.cpp
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

#include "command/commands.h"
#include "base/master.h"
#include "base/messenger.h"
#include "model/model.h"
#include "methods/mc.h"

// Performs MC insertion ('disorder <ncycles>')
int CommandData::function_CA_DISORDER(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	msg.print("Performing disordered build for model '%s'\n", obj.m->name());
	mc.setNCycles(c->argi(0));
	mc.disorder(obj.m);
	return CR_SUCCESS;
}

// Print current component list ('listcomponents')
int CommandData::function_CA_LISTCOMPONENTS(Command *&c, Bundle &obj)
{
	msg.print("Current component specification:\n");
	Vec3<double> v1, v2;
	char s[150];
	msg.print("                                                      Centre                   Size\n");
	msg.print("Model        nMols  I D T R Z    Region         X       Y       Z       X       Y       Z     Overlap\n");
	for (Model *m = master.models(); m != NULL; m = m->next)
	{
		v1 = m->area.centre();
		v2 = m->area.size();
		sprintf(s,"%-10s  %5i  %s %s %s %s %s  %-12s %7.3f %7.3f %7.3f %7.3f %7.3f %7.3f %3s\n",
			m->name(),m->nRequested(),
			(m->isMoveAllowed(MonteCarlo::Insert) ? "+" : " "),
			(m->isMoveAllowed(MonteCarlo::Delete) ? "+" : " "),
			(m->isMoveAllowed(MonteCarlo::Translate) ? "+" : " "),
			(m->isMoveAllowed(MonteCarlo::Rotate) ? "+" : " "),
			(m->isMoveAllowed(MonteCarlo::ZMatrix) ? "+" : " "),
			ComponentRegion::regionShape(m->area.shape()),
			v1.x, v1.y, v1.z, v2.x, v2.y, v2.z,
			(m->area.allowOverlap() ? "Yes" : "No"));
		msg.print(s);
	}
	return CR_SUCCESS;
}

// Set region centre to position ('regioncentre <x y z>')
int CommandData::function_CA_REGIONCENTRE(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	obj.m->area.setCentre(c->arg3d(0));
	return CR_SUCCESS;
}

// Set geometry of region ('regiongeometry <x y z> [l]')
int CommandData::function_CA_REGIONGEOMETRY(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	obj.m->area.setSize(c->arg3d(0));
	if (!c->hasArg(3)) obj.m->area.setLength(c->argd(3));
	return CR_SUCCESS;
}

// Set overlap flag for the current model ('regionoverlaps true|false')
int CommandData::function_CA_REGIONOVERLAPS(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	obj.m->area.setAllowOverlap(c->argb(0));
	return CR_SUCCESS;
}

// Set shape for region ('regionshape <shape>')
int CommandData::function_CA_REGIONSHAPE(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	ComponentRegion::RegionShape rs = ComponentRegion::regionShape(c->argc(0));
	if (rs != ComponentRegion::nRegionShapes) obj.m->area.setShape(rs);
	return CR_SUCCESS;
}

// Set number of requested molecules ('nmols <n>')
int CommandData::function_CA_NMOLS(Command *&c, Bundle &obj)
{
	if (obj.notifyNull(BP_MODEL)) return CR_FAIL;
	obj.m->setNRequested(c->argi(0));
	return CR_SUCCESS;
}

// Set vdw radius scaling for method ('vdwscale <scale>')
int CommandData::function_CA_VDWSCALE(Command *&c, Bundle &obj)
{
	mc.setVdwScale(c->argd(0));
	return CR_SUCCESS;
}

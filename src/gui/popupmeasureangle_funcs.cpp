/*
	*** Popup Widget - Measure Angle Functions
	*** src/gui/popupmeasureangle_funcs.cpp
	Copyright T. Youngs 2007-2015

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

#include "gui/popupmeasureangle.h"
#include "main/aten.h"
#include "gui/mainwindow.h"
#include "parser/commandnode.h"
#include "base/namespace.h"

ATEN_USING_NAMESPACE

// Constructor
MeasureAnglePopup::MeasureAnglePopup(AtenWindow& parent, TMenuButton* buttonParent) : TMenuButtonPopupWidget(buttonParent), parent_(parent)
{
	// Set up interface
	ui.setupUi(this);
}

// Show popup, updating any controls as necessary beforehand
void MeasureAnglePopup::popup()
{
	show();
}

/*
 * Widget Functions
 */

void MeasureAnglePopup::on_SelectionButton_clicked(bool checked)
{
	// Run command
	CommandNode::run(Commands::MeasureSelected, "i", 3);

	// Update display
	parent_.updateWidgets(AtenWindow::CanvasTarget);

	// Hide popup
	hide();
}


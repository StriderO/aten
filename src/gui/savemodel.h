/*
	*** Save Model Dialog
	*** src/gui/savemodel.h
	Copyright T. Youngs 2007-2016

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

#ifndef ATEN_SAVEMODELDIALOG_H
#define ATEN_SAVEMODELDIALOG_H

#include "gui/ui_savemodel.h"
#include "plugins/interfaces.h"
#include "base/namespace.h"

// Forward Declarations (Qt)
/* none */

ATEN_BEGIN_NAMESPACE

// Forward Declarations (Aten)
/* none */

ATEN_END_NAMESPACE

ATEN_USING_NAMESPACE

// Save Model Dialog
class AtenSaveModel : public QDialog
{
	// All Qt declarations derived from QObject must include this macro
	Q_OBJECT

	public:
	// Constructor
	AtenSaveModel(QWidget* parent, QDir startingDirectory, const RefList< FilePluginInterface, int >& filePlugins);
	// Main form declaration
	Ui::SaveModelDialog ui;


	/*
	 * Data
	 */
	private:
	// Reference to plugin list to use for this file dialog
	const RefList<FilePluginInterface,int>& filePlugins_;
	// PluginStore logpoint at which plugins were added to the file selector
	int pluginsLogPoint_;


	/*
	 * Widget Functions
	 */
	private slots:
	void on_SaveButton_clicked(bool checked);
	void on_CancelButton_clicked(bool checked);

	public:
	// Execute dialog
	bool execute(int currentPluginsLogPoint, QString currentFileName = QString(), FilePluginInterface* plugin = NULL);
	// Return selected filename
	QString selectedFilename();
	// Return selected file plugin
	FilePluginInterface* selectedPlugin();
	// Return map of standard options from dialog
	KVMap standardOptions();
};

#endif

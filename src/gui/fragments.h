/*
	*** Fragment Library Dock Widget
	*** src/gui/fragment.h
	Copyright T. Youngs 2007-2011

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

#ifndef ATEN_FRAGMENTWIDGET_H
#define ATEN_FRAGMENTWIDGET_H

#include "gui/ui_fragments.h"
#include "base/dnchar.h"

// Forward declarations
class Model;
class Fragment;
class TTreeWidgetItem;

// Atom list
class FragmentsWidget : public QDockWidget
{
	// All Qt declarations derived from QObject must include this macro
	Q_OBJECT

	/*
	// Window Functions
	*/
	public:
	void showWidget();
	void refresh();
	private slots:
	void on_FragmentTree_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
	void on_FragmentTree_doubleClicked(const QModelIndex &index);
	void on_FragmentTable_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);
	void on_FragmentTable_doubleClicked(const QModelIndex &index);
	void on_FragmentFilterEdit_textChanged(const QString &text);
	void on_FragmentShowAllButton_clicked(bool checked);
	void on_ViewAsListCheck_clicked(bool checked);
	void on_ViewAsGridCheck_clicked(bool checked);
	protected:
	void closeEvent(QCloseEvent *event);

	/*
	// Local variables
	*/
	private:
	// Current drawing fragment
	Fragment *currentFragment_;
	// Text string to filter fragments by
	Dnchar filterText_;
	// Index of bond to orient along on target atom
	int bondId_;

	public:
	// Increment bond id value
	void increaseBondId();
	// Return bondId (as reference so it can be reset by associated Fragment routines)
	int &bondId();
	// Return current drawing fragment
	Fragment *currentFragment();
	

	/*
	// Dialog
	*/
	public:
	// Constructor / Destructor
	FragmentsWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	// Main form declaration
	Ui::FragmentsWidget ui;
};

#endif
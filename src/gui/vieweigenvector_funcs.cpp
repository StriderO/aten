/*
	*** Qt GUI: View Eigenvector dialog functions
	*** src/gui/vieweigenvector_funcs.cpp
	Copyright T. Youngs 2007-2010

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

#include "main/aten.h"
#include "gui/vieweigenvector.h"
#include "gui/mainwindow.h"
#include "base/messenger.h"
#include "base/sysfunc.h"
#include "model/model.h"

// Constructor
AtenViewEigenvector::AtenViewEigenvector(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent,flags)
{
	ui.setupUi(this);
}

// Destructor
AtenViewEigenvector::~AtenViewEigenvector()
{
}

void AtenViewEigenvector::showWindow(Model *m, int id)
{
	// Update contents
	ui.EigenvectorTable->clear();
	ui.EigenvectorTable->setHorizontalHeaderLabels(QStringList() << "Atom" << "Shell" << "Type" << "Coefficient" );
	// Check model pointer and eigenvector ID specified
	if (m == NULL) return;
	if ((id < 0) || (id >= m->nEigenvectors()))
	{
		printf("Eigenvector id %i is out of range for model\n", id);
		return;
	}
	// Determine row count
	int row = 0, shell = 0, n;
	BasisShell *bas;
	BasisPrimitive *prim;
	ui.EigenvectorTable->setRowCount(m->nCartesianBasisFunctions());
	// Loop over basis shells and their primitives....
	QTableWidgetItem *tabitem;
	Dnchar text;
	row = 0;
	Eigenvector *evec = m->eigenvector(id); 
	double *eigenvec = evec->eigenvector();
	for (bas = m->basisShells(); bas != NULL; bas = bas->next)
	{
		++shell;
		// Cycle over primitives
		for (n = 0; n < bas->nCartesianFunctions(); ++n)
		{
			// Atom column
			tabitem = new QTableWidgetItem();
			text.print("%i (%s)\n", bas->atomId()+1, m->atom(bas->atomId()) != NULL ? elements().symbol(m->atom(bas->atomId())) : "NULL");
			tabitem->setText(text.get());
			ui.EigenvectorTable->setItem(row, AtenViewEigenvector::AtomColumn, tabitem);
			// Add in shell data
			tabitem = new QTableWidgetItem();
			tabitem->setText(itoa(shell));
			ui.EigenvectorTable->setItem(row, AtenViewEigenvector::ShellColumn, tabitem);
			tabitem = new QTableWidgetItem();
			tabitem->setText(bas->cartesianFunctionName(n));
			ui.EigenvectorTable->setItem(row, AtenViewEigenvector::TypeColumn, tabitem);
			tabitem = new QTableWidgetItem();
			tabitem->setText(ftoa(eigenvec[row]));
			ui.EigenvectorTable->setItem(row, AtenViewEigenvector::CoefficientColumn, tabitem);
			row++;
		}
	}
	// Resize columns
	for (n=0; n<AtenViewEigenvector::nColumns; ++n) ui.EigenvectorTable->resizeColumnToContents(n);
	show();
}

void AtenViewEigenvector::dialogFinished(int result)
{
	accept();
}

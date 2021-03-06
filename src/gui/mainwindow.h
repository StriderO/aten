/*
	*** Main Window
	*** src/gui/mainwindow.h
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

#ifndef ATEN_MAINWINDOW_H
#define ATEN_MAINWINDOW_H

#include <QtWidgets/QButtonGroup>
#include <QSettings>
#include <QMenu>
#include "base/atom.h"
#include "base/prefs.h"
#include "methods/partitioningscheme.h"
#include "gui/ui_mainwindow.h"
#include "gui/ui_prefs.h"
#include "gui/useractions.h"
#include "gui/disorderwizard.h"
#include "gui/exportfilm.h"
#include "gui/exportimage.h"
#include "gui/openexpression.h"
#include "gui/opengrid.h"
#include "gui/openmodel.h"
#include "gui/opentrajectory.h"
#include "gui/progress.h"
#include "gui/saveexpression.h"
#include "gui/savemodel.h"
#include "gui/zmatrix.h"
#include "templates/reflist.h"
#include "base/glyph.h"
#include "base/namespace.h"

// Forward Declarations
class AtenPrefs;
class AtenForcefieldEditor;
class GlyphsWidget;
class VibrationsWidget;

ATEN_BEGIN_NAMESPACE

// Forward Declarations (Aten)
class Tree;
class Aten;

ATEN_END_NAMESPACE

ATEN_USING_NAMESPACE

class AtenWindow : public QMainWindow
{
	// All Qt declarations must include this macro
	Q_OBJECT

	public:
	// Constructor / Destructor
	AtenWindow(Aten& aten);
	~AtenWindow();
	// Main form declaration
	Ui::AtenWindow ui;

	protected:
	void closeEvent(QCloseEvent* event);
	void resizeEvent(QResizeEvent* event);


	/*
	 * Aten Reference
	 */
	private:
	// Aten reference
	Aten& aten_;

	public:
	// Return reference to Aten
	Aten& aten();


	/*
	 * Update Functions
	 */
	public:
	// Update Targets 
	enum UpdateTarget { DefaultTarget = 0, AtomsTableTarget = 1, ModelsListTarget = 2, StatusBarTarget = 4, BuildPanelTarget = 8, CalculatePanelTarget = 16, CellPanelTarget = 32, ForcefieldsPanelTarget = 64, GlyphsTarget = 128, GridsPanelTarget = 256, SelectionPanelTarget = 512, SelectPanelTarget = 1024, TrajectoryPanelTarget = 2048, TransformPanelTarget = 4096, ToolsPanelTarget = 8192, VibrationsTarget = 16384,   DummyTarget = 32768, AllTargets = 65535 };

	private:
	// Whether window is currently refreshing
	bool refreshing_;
	// Whether window has been shown
	bool shown_;

	private:
	// Refresh main window
	void updateMainWindow();

	public:
	// Initial update and show
	void initialUpdateAndShow();
	// Return whether main window has been shown
	bool shown();

	public slots:
	// Refreshes specified (or all) dock widgets
	void updateWidgets(int targets = AtenWindow::DefaultTarget);


	/*
	 * Window Functions
	 */
	public:
	// Set interactivity (to full or zero), except for main view camera changes
	void setInteractive(bool interactive);

	public slots:
	// Toggle panel visibility
	void togglePanelVisibilty();


	/*
	 * File Dialogs
	 */
	private:
	// Expression import dialog
	AtenOpenExpression openExpressionDialog_;
	// Grid import dialog
	AtenOpenGrid openGridDialog_;
	// Model import dialog
	AtenOpenModel openModelDialog_;
	// Trajectory import dialog
	AtenOpenTrajectory openTrajectoryDialog_;
	// Model export dialog
	AtenSaveModel saveModelDialog_;
	// Expression export dialog
	AtenSaveExpression saveExpressionDialog_;

	public:
	// Return model export dialog
	AtenSaveModel& saveModelDialog();
	// Return expression export dialog
	AtenSaveExpression& saveExpressionDialog();


	/*
	 * Context Menu
	 */
	private:
	// Context menu
	QMenu contextMenu_;
	// Atom under mouse when context menu was called
	Atom* contextAtom_;

	private:
	// Create actions for glyph creation in context menu
	QAction* createGlyphActions[Glyph::nGlyphTypes];

	private:
	// Create context menu and setup actions
	void createContextMenu();

	private slots:
	void contextMenuSetAtomStyle(bool checked);
	void contextMenuSetAtomLabel(bool checked);
	void contextMenuProbeAtom(bool checked);
	void contextMenuSetViewOrigin(bool checked);
	void contextMenuCreateFragment(bool checked);
	void contextMenuSelectElement(bool checked);
	void contextMenuSelectSimilar(bool checked);
	void contextMenuSelectFragment(bool checked);
	void contextMenuTypeSetName(bool checked);
	void contextMenuReMap(bool checked);
	void contextMenuColourChanged(QColor colour);
	void createGlyph();

	public:
	// Call the atom context menu
	void callContextMenu(Atom* atomUnderMouse, int x, int y);


	/*
	 * Home Panel
	 */
	private:
	// Update home panel
	void updateHomePanel(Model* sourceModel);

	private slots:
	// File
	void on_HomeFileNewButton_clicked(bool checked);
	void on_HomeFileOpenButton_clicked(bool checked);
	void on_HomeFileSaveButton_clicked(bool checked);
	void on_HomeFileSaveAsButton_clicked(bool checked);
	void on_HomeFileCloseButton_clicked(bool checked);
	void on_HomeFileImageButton_clicked(bool checked);
	void on_HomeFileFilmButton_clicked(bool checked);
	// Edit
	void on_HomeEditCopyButton_clicked(bool checked);
	void on_HomeEditCutButton_clicked(bool checked);
	void on_HomeEditPasteButton_clicked(bool checked);
	void on_HomeEditDeleteButton_clicked(bool checked);
	void on_HomeEditUndoButton_clicked(bool checked);
	void on_HomeEditRedoButton_clicked(bool checked);
	// Appearance
	void on_HomeAppearanceLineButton_clicked(bool checked);
	void on_HomeAppearanceTubeButton_clicked(bool checked);
	void on_HomeAppearanceSphereButton_clicked(bool checked);
	void on_HomeAppearanceScaledButton_clicked(bool checked);
	void on_HomeAppearanceOwnStyleButton_clicked(bool checked);
	void on_HomeAppearanceElementButton_clicked(bool checked);
	void on_HomeAppearanceChargeButton_clicked(bool checked);
	void on_HomeAppearanceForceButton_clicked(bool checked);
	void on_HomeAppearanceVelocityButton_clicked(bool checked);
	void on_HomeAppearanceBondsButton_clicked(bool checked);
	void on_HomeAppearanceOwnColourButton_clicked(bool checked);
	void on_HomeAppearancePerspectiveButton_clicked(bool checked);
	void on_HomeAppearanceShowAllButton_clicked(bool checked);
	// View
	void on_HomeViewResetButton_clicked(bool checked);
	void on_HomeViewGetButton_clicked(bool checked);
	void on_HomeViewSetButton_clicked(bool checked);
	void on_HomeViewHBondsButton_clicked(bool checked);
	void on_HomeViewCorrectGridsButton_clicked(bool checked);
	void on_HomeViewLockButton_clicked(bool checked);


	/*
	 * Build Panel
	 */
	private:
	// Update build panel
	void updateBuildPanel(Model* sourceModel);

	private slots:
	// Select
	void on_BuildSelectAtomsButton_clicked(bool checked);
	void on_BuildSelectBoundButton_clicked(bool checked);
	void on_BuildSelectElementButton_clicked(bool checked);
	// Draw
	void on_BuildDrawDrawButton_clicked(bool checked);
	void on_BuildDrawFragmentButton_clicked(bool checked);
	void on_BuildDrawDeleteButton_clicked(bool checked);
	void on_BuildDrawTransmuteButton_clicked(bool checked);
	void on_BuildDrawAddHButton_clicked(bool checked);
	void on_BuildDrawGrowButton_clicked(bool checked);
	// Elements
	// Bonding
	void on_BuildBondingRebondButton_clicked(bool checked);
	void on_BuildBondingAugmentButton_clicked(bool checked);
	void on_BuildBondingClearButton_clicked(bool checked);

	public:
	// Return currently-selected build element
	int currentBuildElement();


	/*
	 * Cell Panel
	 */
	private:
	// Update cell panel
	void updateCellPanel(Model* sourceModel);

	private slots:
	// Define
	void on_CellDefinePeriodicButton_clicked(bool checked);
	// Transform
	void on_CellTransformReplicateButton_clicked(bool checked);
	void on_CellTransformScaleButton_clicked(bool checked);
	// Miller
	void on_CellMillerShowButton_clicked(bool checked);
	void on_CellMillerHSpin_valueChanged(int value);
	void on_CellMillerKSpin_valueChanged(int value);
	void on_CellMillerLSpin_valueChanged(int value);
	void on_CellMillerSelectButton_clicked(bool checked);
	// Fold
	void on_CellFoldAtomsButton_clicked(bool checked);
	void on_CellFoldMoleculesButton_clicked(bool checked);


	/*
	 * Calculate Panel
	 */
	private:
	// Update calculate panel
	void updateCalculatePanel(Model* sourceModel);

	private slots:
	// Measure
	void on_CalculateMeasureDistanceButton_clicked(bool checked);
	void on_CalculateMeasureAngleButton_clicked(bool checked);
	void on_CalculateMeasureTorsionButton_clicked(bool checked);
	void on_CalculateMeasureClearButton_clicked(bool checked);
	void on_CalculateMeasureListButton_clicked(bool checked);
	// Charge
	void on_CalculateChargeTotalButton_clicked(bool checked);
	void on_CalculateChargeAverageButton_clicked(bool checked);
	// Geometry
	void on_CalculateGeometryCentreButton_clicked(bool checked);


	/*
	 * Transform Panel
	 */
	private:
	// Update transform panel
	void updateTransformPanel(Model* sourceModel);

	private slots:
	// Geometry
	void on_TransformGeometryDistanceButton_clicked(bool checked);
	void on_TransformGeometryAngleButton_clicked(bool checked);
	void on_TransformGeometryTorsionButton_clicked(bool checked);
	// Position
	void on_TransformPositionCentreButton_clicked(bool checked);
	void on_TransformPositionRepositionButton_clicked(bool checked);
	void on_TransformPositionZeroButton_clicked(bool checked);
	// Transform
	void on_TransformTransformRotateButton_clicked(bool checked);
	void on_TransformTransformMultiplyButton_clicked(bool checked);
	void on_TransformTransformConvertButton_clicked(bool checked);


	/*
	 * Grids Panel
	 */
	private:
	// Update grid panel
	void updateGridsPanel(Model* sourceModel);
	// Update current grid information
	void updateGridInformation(Grid* sourceGrid);

	private slots:
	// Manage
	void on_GridsManageOpenButton_clicked(bool checked);
	void on_GridsManageRemoveButton_clicked(bool checked);
	void on_GridsList_currentRowChanged(int row);
	void on_GridsList_itemChanged(QListWidgetItem* item);
	void gridsListContextMenuRequested(const QPoint& point);
	void recreateGridsForView();
	// Primary Surface
	void on_GridsPrimaryLowerCutoffSpin_valueChanged(double value);
	void on_GridsPrimaryUpperCutoffSpin_valueChanged(double value);
	void on_GridsPrimaryColourButton_popupChanged();
	// Secondary Surface
	void on_GridsSecondaryActiveButton_clicked(bool checked);
	void on_GridsSecondaryLowerCutoffSpin_valueChanged(double value);
	void on_GridsSecondaryUpperCutoffSpin_valueChanged(double value);
	void on_GridsSecondaryColourButton_popupChanged();
	// Options
	void on_GridsOptionsOutlineButton_clicked(bool checked);
	void on_GridsOptionsPeriodicButton_clicked(bool checked);


	/*
	 * Trajectory Panel
	 */
	private:
	// Trajectory timer id (if any)
	int trajectoryTimerId_;

	private:
	// Update trajectory panel
	void updateTrajectoryPanel(Model* sourceModel);
	// Stop trajectory playback
	void stopTrajectoryPlayback();

	private slots:
	// Source
	void on_TrajectoryManageOpenButton_clicked(bool checked);
	void on_TrajectoryManageRemoveButton_clicked(bool checked);
	void on_TrajectoryManageFramesButton_clicked(bool checked);
	// Control
	void on_TrajectoryControlFirstButton_clicked(bool checked);
	void on_TrajectoryControlPreviousButton_clicked(bool checked);
	void on_TrajectoryControlPlayButton_clicked(bool checked);
	void on_TrajectoryControlNextButton_clicked(bool checked);
	void on_TrajectoryControlLastButton_clicked(bool checked);
	void on_TrajectoryControlFrameSpin_valueChanged(int value);
	void on_TrajectoryControlFrameSlider_valueChanged(int position);
	// Style
	void on_TrajectoryStyleInheritButton_clicked(bool checked);
	void on_TrajectoryStylePropagateButton_clicked(bool checked);
	void on_TrajectoryStylePromoteButton_clicked(bool checked);


	/*
	 * Forcefields Panel
	 */
	private:
	// Update forcefields panel
	void updateForcefieldsPanel(Model* sourceModel);

	private slots:
	// Manage
	void on_ForcefieldsList_currentRowChanged(int row);
	void on_ForcefieldsManageOpenButton_clicked(bool checked);
	void on_ForcefieldsManageRemoveButton_clicked(bool checked);
	void on_ForcefieldsManageEditButton_clicked(bool checked);
	void on_ForcefieldsManageAssignButton_clicked(bool checked);
	// Calculate
	void on_ForcefieldsCalculateMinimiseButton_clicked(bool checked);
	void on_ForcefieldsCalculateEnergyButton_clicked(bool checked);
	void on_ForcefieldsCalculateForcesButton_clicked(bool checked);
	// Patterns
	void on_ForcefieldsPatternsCreateButton_clicked(bool checked);
	void on_ForcefieldsPatternsClearButton_clicked(bool checked);
	void on_ForcefieldsPatternsListButton_clicked(bool checked);
	void on_ForcefieldsPatternsDefaultButton_clicked(bool checked);
	// Expression
	void on_ForcefieldsExpressionTypeButton_clicked(bool checked);
	void on_ForcefieldsExpressionDescribeButton_clicked(bool checked);
	void on_ForcefieldsExpressionSaveButton_clicked(bool checked);
	void on_ForcefieldsExpressionRemoveButton_clicked(bool checked);


	/*
	 * Select Panel
	 */
	private:
	// Update select panel
	void updateSelectPanel(Model* sourceModel);
	// Enum for selection auto target type
	enum SelectTargetType { AutoSelectType, RangeSelectType, NETASelectType, LoopSelectType, NameSelectType, nSelectTargetTypes };
	// Last auto-determined selection type
	SelectTargetType lastSelectionType_;

	private slots:
	// Basic
	void on_SelectBasicAllButton_clicked(bool checked);
	void on_SelectBasicNoneButton_clicked(bool checked);
	void on_SelectBasicInvertButton_clicked(bool checked);
	void on_SelectBasicExpandButton_clicked(bool checked);
	// Intelligent Select
	void on_SelectIntelligentTargetCombo_currentTextChanged(const QString& text);
	void on_SelectIntelligentTypeCombo_currentIndexChanged(int index);
	void on_SelectIntelligentAddButton_clicked(bool checked);
	void on_SelectIntelligentRemoveButton_clicked(bool checked);


	/*
	 * Selection Panel
	 */
	private:
	// Update selection panel
	void updateSelectionPanel(Model* sourceModel);

	private slots:
	// Appearance
	void on_SelectionAppearanceStyleButton_clicked(bool checked);
	void on_SelectionAppearanceColourButton_clicked(bool checked);
	void on_SelectionAppearanceResetToElementButton_clicked(bool checked);
	void on_SelectionAppearanceHideButton_clicked(bool checked);
	// Label
	void on_SelectionLabelIDButton_clicked(bool checked);
	void on_SelectionLabelElementButton_clicked(bool checked);
	void on_SelectionLabelChargeButton_clicked(bool checked);
	void on_SelectionLabelTypeButton_clicked(bool checked);
	void on_SelectionLabelEquivalentButton_clicked(bool checked);
	void on_SelectionLabelClearButton_clicked(bool checked);
	// Position
	void on_SelectionPositionFixButton_clicked(bool checked);
	void on_SelectionPositionFreeButton_clicked(bool checked);
	void on_SelectionPositionSetViewOriginButton_clicked(bool checked);


	/*
	 * Tools Panel
	 */
	private:
	// Update tools panel
	void updateToolsPanel(Model* sourceModel);

	private slots:
	// Scripts
	void on_ToolsScriptsOpenButton_clicked(bool checked);
	void on_ToolsScriptsRemoveButton_clicked(bool checked);
	void on_ToolsScriptsReloadButton_clicked(bool checked);
	void on_ToolsScriptsRunButton_clicked(bool checked);
	// Atoms
	void on_ToolsAtomsReorderButton_clicked(bool checked);
	void on_ToolsAtomsZMatrixButton_clicked(bool checked);
	// Disorder
	void on_ToolsDisorderCreateButton_clicked(bool checked);
	// Surface
	void on_ToolsSurfaceTerminateButton_clicked(bool checked);


	/*
	 * Models List
	 */
	private slots:
	void modelsListContextMenuRequested(const QPoint& point);
	void on_ModelsListToggleButton_clicked(bool checked);
	void on_ModelsList_itemSelectionChanged();
	void on_ModelsPreviousButton_clicked(bool checked);
	void on_ModelsNextButton_clicked(bool checked);

	public:
	// Refresh models list
	void updateModelsList();
	// Close specified model, saving first if requested
	bool closeModel(Model* m);
	// Save before close
	bool saveBeforeClose();


	/*
	 * Atoms Table
	 */
	public:
	// Table Columns
	enum AtomTableItem { AtomIdItem, AtomElementItem, AtomTypeItem, AtomXItem, AtomYItem, AtomZItem, AtomQItem, nAtomItems };

	private:
	// Custom item delegates for each column
	QAbstractItemDelegate* atomsTableItemDelegates_[AtenWindow::nAtomItems];
	// Log points of model info displayed in list
	int atomsTableStructurePoint_, atomsTableSelectionPoint_;
	// Whether the current view is by pattern
	bool atomsTableViewingByPattern_;
	// Array of currently-visible items
	bool atomsTableVisibleItems_[nAtomItems];
	// List of currently-visible atom data
	QList<int> atomsTableDisplayItems_;
	// Last model displayed in list
	Model* atomsTableLastModel_;
	// Current root atom id of model (ID displayed in row 1)
	int atomsTableCurrentRootId_;
	// Whether the widget should refresh when it is next shown
	bool atomsTableShouldRefresh_;
	// Number of rows displayed in AtomTable
	int atomsTableMaxRows_;
	// RefList of currently-displayed atoms
	RefList<Atom,int> atomsTableItems_;
	// Last clicked and 'moved over' Atom
	Atom* atomsTablePrevClicked_, *atomsTableLastClicked_, *atomsTableLastHovered_;

	private:
	void atomsTableRecalculateRowSize();
	void atomsTableUpdateRow(int row);
	void atomsTableUpdateDisplayItems();
	void atomsTableUpdateSelection();
	Atom* atomsTableAtomInRow(int row);
	void atomsTableToggleItem(Atom* i);

	private slots:
	void on_AtomsTableToggleButton_clicked(bool checked);
	void on_AtomsTableScrollBar_valueChanged(int value);
	void on_AtomsShiftUpButton_clicked(bool checked);
	void on_AtomsShiftDownButton_clicked(bool checked);
	void on_AtomsMoveToStartButton_clicked(bool checked);
	void on_AtomsMoveToEndButton_clicked(bool checked);
	void on_AtomsViewElementCheck_clicked(bool checked);
	void on_AtomsViewIdCheck_clicked(bool checked);
	void on_AtomsViewTypeCheck_clicked(bool checked);
	void on_AtomsViewXCheck_clicked(bool checked);
	void on_AtomsViewYCheck_clicked(bool checked);
	void on_AtomsViewZCheck_clicked(bool checked);
	void on_AtomsViewChargeCheck_clicked(bool checked);

	public slots:
	void atomsTableMousePressEvent(QMouseEvent* event);
	void atomsTableMouseReleaseEvent(QMouseEvent* event);
	void atomsTableMouseMoveEvent(QMouseEvent* event);
	void atomsTableMouseWheelEvent(QWheelEvent* event);
	void atomsTableMouseDoubleClickEvent(QMouseEvent* event);
	void atomsTableItemChanged(QTableWidgetItem* item);

	public:
	// Refresh atoms table
	void updateAtomsTable(Model* sourceModel);


	/*
	 * Quick Command Box
	 */
	private slots:
	void on_QuickCommandToggleButton_clicked(bool checked);
	void quickCommandRun();	


	/*
	 * Messages Control
	 */
	public:
	// Types of message display
	enum MessageDisplay { FullMessages, MessagesOverScene, MessagesUnderScene, NoMessages };
	// Current message display type
	MessageDisplay messageDisplay_;

	private slots:
	void on_MessagesCycleButton_clicked(bool checked);
	void on_MessagesCopyButton_clicked(bool checked);
	void on_MessagesClearButton_clicked(bool checked);
	void on_MessagesFontIncreaseButton_clicked(bool checked);
	void on_MessagesFontDecreaseButton_clicked(bool checked);
	void on_MessagesScroll_valueChanged(int value);

	public:
	// Return current message display style
	MessageDisplay messageDisplay();
	// Update messages widgets
	void updateMessagesWidgets();
	// Return current position of messages scrollbar
	int messagesScrollPosition();
	// Scroll messages by one step
	void scrollMessages(bool up);


	/*
	 * Local Widgets and Routines
	 */
	private:
	// Text labels for model information and UI messages in status bar
	QLabel* cellInfoLabel_, *massLabel_, *densityLabel_, *selectionLabel_, *modelLabel_, *atomsLabel_, *messageLabel_;

	protected:
	// Timer event
	void timerEvent(QTimerEvent* event);

	public:
	// Set message label text
	void setMessageLabel(QString message);


	/*
	 * Settings
	 */
	private:
	// Load settings
	void loadSettings();
	// Save settings
	void saveSettings();


	/*
	 * Wizards and Dialogs
	 */
	public:
	// Glyphs dock widget
	GlyphsWidget *glyphsWidget;
	// Vibrations dock widget
	VibrationsWidget *vibrationsWidget;
	// Disorder wizard
	DisorderWizard disorderWizard_;
	// Export Film dialog
	AtenExportFilm exportFilmDialog_;
	// Export Image dialog
	AtenExportImage exportImageDialog_;
	// Progress Indicator
	AtenProgress progressDialog_;
	// ZMatrix Editor
	AtenZMatrix zMatrixDialog_;


	/*
	 * Interactive Modes
	 */
	private:
	// Active interaction mode of the main canvas
	UserAction::Action activeMode_;
	// Selected interaction mode (from GUI)
	UserAction::Action selectedMode_;
	// Current drawing depth for certain tools
	double currentDrawDepth_;
	// Current build geometry
	Atom::AtomGeometry buildGeometry_;
	// Whether we are selecting atoms and placing them in the pickedAtoms_ list	
	bool pickEnabled_;
	// User action before picking mode was entered
	UserAction::Action actionBeforePick_;
	// List of picked atoms
	RefList<Atom,int> pickedAtoms_;
	// Atom that was clicked at the start of a mouse press event
	Atom* clickedAtom_;
	// RefList of selected atoms and their positions so manipulations may be un-done
	RefList< Atom,Vec3<double> > oldPositions_;
	// Whether to accept editing actions (i.e. anything other than view manipulation)
	bool editable_;

	public:
	// Begin an action on the model
	void beginMode(Prefs::MouseButton button, bool* keyModifiers);
	// End an action on the model
	void endMode(Prefs::MouseButton button, bool* keyModifiers);
	// Set the active mode to the current user mode
	void useSelectedMode();
	// Sets the currently selected interact mode
	void setSelectedMode(UserAction::Action ua);
	// Sets the currently selected interact mode, and corrects source button checked status
	void setSelectedMode(UserAction::Action ua, bool buttonChecked);
	// Return the currently selected mode
	UserAction::Action selectedMode() const;
	// Return the currently active mode
	UserAction::Action activeMode() const;
	// Set current build geometry
	void setBuildGeometry(Atom::AtomGeometry ag);
	// Return current build geometry
	Atom::AtomGeometry buildGeometry() const;
	// Current drawing depth for certain tools
	double currentDrawDepth();
	// Notify that an atom was clicked
	void atomClicked(Atom* atom);
	// Return the last clicked atom
	Atom* clickedAtom();
	// Return start of picked atom list
	RefListItem<Atom,int>* pickedAtoms();
	// RefList of selected atoms and their positions so manipulations may be un-done
	RefList< Atom,Vec3<double> >& oldPositions();


	/*
	 * Image Generation
	 */
	public:
	// Bitmap formats
	enum BitmapFormat { BitmapBMP, BitmapPG, BitmapPNG, BitmapPPM, BitmapXBM, BitmapX11, nBitmapFormats };
	static BitmapFormat bitmapFormat(QString s, bool reportError = false);
	static BitmapFormat bitmapFormatFromFilter(const char* s);
	static const char* bitmapFormatFilter(BitmapFormat bf);
	static const char* bitmapFormatExtension(BitmapFormat bf);

	public:
	// Return current width of main view context
	int contextWidth();
	// Return current height of main view context
	int contextHeight();
	// Return image of current view
	QPixmap scenePixmap(int width, int height, bool transparent);
	// Return pixmap of specified model
	QPixmap modelPixmap(Model* model, QSize pixmapSize);

	public slots:
	// Save automatically-named image of current scene
	void snapshotCurrentView();


	/*
	 * Film Generation
	 */
	private:
	// Cleanup film export files
	void cleanupFilmExport(QStringList images, QString imagesFile);

	public:
	// Export film
	bool exportFilm();
};

#endif

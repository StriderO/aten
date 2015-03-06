/*
	*** Model Rendering
	*** src/gui/viewer_model.cpp
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

#include "gui/viewer.uih"
#include "base/forcefieldatom.h"
#include "model/model.h"
#include "base/pattern.h"
#include "base/sysfunc.h"
#include "main/aten.h"

// ATEN2 TODO This will be moved to Model...
// Render primitive in specified colour
void Viewer::renderPrimitive(Viewer::TriangleObject obj, Primitive& primitive, Vec4<GLfloat>& colour, Matrix& transform, GLenum fillMode, GLfloat lineWidth)
{
        if (!activePrimitiveLists_[obj]) return;

	// Add primitive info to solid objects list
	PrimitiveInfo *pi = solidPrimitives_[obj].add();
	pi->set(&primitive, colour, transform, fillMode, lineWidth);	// ATEN2 TODO Store reference rather than pointer to Primitive
}

// Add text primitive for rendering later
void Viewer::renderTextPrimitive(int x, int y, const char *text, QChar addChar, bool rightalign)
{
	printf("Text rendering in 2D is broken.\n");
//         textPrimitives_.add(x, contextHeight_-y, text, addChar, rightalign);  ATEN2 TODO
}

// Search for primitive associated to specified Grid pointer
GridPrimitive *Viewer::findGridPrimitive(Grid *g)
{
        GridPrimitive *gp = NULL;
        for (gp = gridPrimitives_.first(); gp != NULL; gp = (GridPrimitive*) gp->next) if (gp->source() == g) break;
        return gp;
}

// Remove grid primitive from list (if it exists)
void Viewer::removeGridPrimitive(Grid *g)
{
        GridPrimitive *gp = NULL;
        for (gp = gridPrimitives_.first(); gp != NULL; gp = (GridPrimitive*) gp->next) if (gp->source() == g) break;
        if (gp != NULL) gridPrimitives_.remove(gp);
}

// Render bond
void Viewer::renderBond(Viewer::TriangleObject basicList, Viewer::TriangleObject selectionList, Matrix A, Vec3<double> vij, Atom* i, Prefs::DrawStyle style_i, Vec4<GLfloat>& colour_i, double radius_i, Atom* j, Prefs::DrawStyle style_j, Vec4<GLfloat>& colour_j, double radius_j, Bond::BondType bt, double selscale, Bond* b, bool transparentSel)
{
	double dvisible, selvisible, factor, rij, phi;
	Vec3<double> ri, rj, localx, localy, localz, stickpos, dx, normz;
	GLfloat alpha_i, alpha_j;
	int lineList, baseLineList = (basicList == Viewer::BasicObject ? NormalLineObject : NormalGuiLineObject);
	Matrix B;

	// Store copies of alpha values
	alpha_i = colour_i[3];
	alpha_j = colour_j[3];
	
	localz = vij;
	rij = localz.magAndNormalise();
	
	// If bond is not visible, don't bother drawing it...
	dvisible = 0.5 * (rij - radius_i - radius_j);
	if (dvisible < 0.0) return;
	selvisible = 0.5 * (rij - selscale*radius_i - selscale*radius_j);

	// Determine bond plane rotation if a multiple bond
	if (((bt == Bond::Double) || (bt == Bond::Triple)) && (b != NULL))
	{
		// Desired z-axis is already known ( = vijn) so get normalised copy
		normz = localz / rij;
		
		// X axis is bond plane vector...
		localx = i->findBondPlane(j,b,normz,TRUE);

		// Generate Y-axis from cross-product of z and x axes
		localy = localx * normz;
		localy.normalise();
		A[0] = localx.x;
		A[1] = localx.y;
		A[2] = localx.z;
		A[4] = localy.x;
		A[5] = localy.y;
		A[6] = localy.z;
		A[8] = localz.x;
		A[9] = localz.y;
		A[10] = localz.z;
	}
	else
	{
		// Calculate dot product with vector {0,0,1}
		phi = DEGRAD * acos(localz.z);
		
		// Special case where the bond is exactly along Z already
		if (phi > 179.99) A.applyRotationX(phi);
		else if (phi >= 0.01) A.applyRotationAxis(-vij.y, vij.x, 0.0, phi, TRUE);
	}
	
	// We can perform an initial translation to the 'edge' of atom i, and scale to visible bond length
	B = A;
	A.applyTranslationZ(radius_i);
	A.applyScalingZ(dvisible);
	// Move matrix B to be centred on atom j
	B.addTranslation(j->r() - i->r());
	B.applyTranslationZ(-radius_j);
	B.applyScalingZ(-dvisible);
	
	// Draw first bond half
	switch (style_i)
	{
		case (Prefs::StickStyle):
			if ((!rebuildSticks_) && (baseLineList == 0)) break;
			// First vertex is at 0,0,0 (i.e. translation elements of A). Second is vij * (0,0,1)
			stickpos = A * Vec3<double>(0.0,0.0,1.0);
			// Determine how many sticks to draw (bond multiplicity : aromatic still counts as one bond)
			lineList = baseLineList + (i->isSelected() ? 1 : 0);
			switch (bt)
			{
				case (Bond::Double):
					dx = A.rotateVector(prefs.atomStyleRadius(Prefs::StickStyle)*0.5,0.0,0.0);
					linePrimitives_[lineList].defineVertex(A[12]+dx.x, A[13]+dx.y, A[14]+dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x+dx.x, stickpos.y+dx.y, stickpos.z+dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(A[12]-dx.x, A[13]-dx.y, A[14]-dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x-dx.x, stickpos.y-dx.y, stickpos.z-dx.z, 0.0,0.0,1.0, colour_i);
					break;
				case (Bond::Triple):
					dx = A.rotateVector(prefs.atomStyleRadius(Prefs::StickStyle),0.0,0.0);
					linePrimitives_[lineList].defineVertex(A[12], A[13], A[14], 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x, stickpos.y, stickpos.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(A[12]+dx.x, A[13]+dx.y, A[14]+dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x+dx.x, stickpos.y+dx.y, stickpos.z+dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(A[12]-dx.x, A[13]-dx.y, A[14]-dx.z, 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x-dx.x, stickpos.y-dx.y, stickpos.z-dx.z, 0.0,0.0,1.0, colour_i);
					break;
				default:
					linePrimitives_[lineList].defineVertex(A[12], A[13], A[14], 0.0,0.0,1.0, colour_i);
					linePrimitives_[lineList].defineVertex(stickpos.x, stickpos.y, stickpos.z, 0.0,0.0,1.0, colour_i);
					break;
			}
			break;
		case (Prefs::TubeStyle):
			renderPrimitive(basicList, primitives_[primitiveSet_].bond(style_i, bt), colour_i, A);
			if (i->isSelected() && (selvisible > 0.0))
			{
				if (transparentSel)
				{
					colour_i.w = 0.5f;
					renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_i, bt), colour_i, A);
					colour_i.w = alpha_i;
				}
				else renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_i, bt), colour_i, A, GL_LINE);
			}
			break;
		case (Prefs::SphereStyle):
		case (Prefs::ScaledStyle):
			renderPrimitive(basicList, primitives_[primitiveSet_].bond(style_i, bt), colour_i, A);
			if (i->isSelected() && (selvisible > 0.0))
			{
				// Move to edge of selected atom and apply selection bond scaling
				A.applyTranslationZ((selscale*radius_i-radius_i) / dvisible);
				A.applyScalingZ(selvisible/dvisible);
				if (transparentSel)
				{
					colour_i.w = 0.5f;
					renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_i, bt), colour_i, A);
					colour_i.w = alpha_i;
				}
				else renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_i, bt), colour_i, A, GL_LINE);
			}
			break;
	}
	
	// Draw second bond half
	switch (style_j)
	{
		case (Prefs::StickStyle):
			if ((!rebuildSticks_) && (baseLineList == 0)) break;
			// First vertex is *still* at 0,0,0 (i.e. translation elements of A). Second is vij * (0,0,1)
			stickpos = B * Vec3<double>(0.0,0.0,1.0);
			lineList = baseLineList + (j->isSelected() ? 1 : 0);
			switch (bt)
			{
				case (Bond::Double):
					dx = B.rotateVector(prefs.atomStyleRadius(Prefs::StickStyle)*0.5,0.0,0.0);
					linePrimitives_[lineList].defineVertex(B[12]+dx.x, B[13]+dx.y, B[14]+dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x+dx.x, stickpos.y+dx.y, stickpos.z+dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(B[12]-dx.x, B[13]-dx.y, B[14]-dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x-dx.x, stickpos.y-dx.y, stickpos.z-dx.z, 0.0,0.0,1.0, colour_j);
					break;
				case (Bond::Triple):
					dx = B.rotateVector(prefs.atomStyleRadius(Prefs::StickStyle),0.0,0.0);
					linePrimitives_[lineList].defineVertex(B[12], B[13], B[14], 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x, stickpos.y, stickpos.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(B[12]+dx.x, B[13]+dx.y, B[14]+dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x+dx.x, stickpos.y+dx.y, stickpos.z+dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(B[12]-dx.x, B[13]-dx.y, B[14]-dx.z, 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x-dx.x, stickpos.y-dx.y, stickpos.z-dx.z, 0.0,0.0,1.0, colour_j);
					break;
				default:
					linePrimitives_[lineList].defineVertex(B[12], B[13], B[14], 0.0,0.0,1.0, colour_j);
					linePrimitives_[lineList].defineVertex(stickpos.x, stickpos.y, stickpos.z, 0.0,0.0,1.0, colour_j);
					break;
			}
			break;
		case (Prefs::TubeStyle):
			renderPrimitive(basicList, primitives_[primitiveSet_].bond(style_j, bt), colour_j, B);
			if (j->isSelected())
			{
				B.applyTranslationZ((selscale*radius_j-radius_j) / dvisible);
				if (transparentSel)
				{
					colour_j.w = 0.5f;
					renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_j, bt), colour_j, B);
					colour_j.w = alpha_j;
				}
				else renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_j, bt), colour_j, B, GL_LINE);
			}
			break;
		case (Prefs::SphereStyle):
		case (Prefs::ScaledStyle):
			renderPrimitive(basicList, primitives_[primitiveSet_].bond(style_j, bt), colour_j, B);
			if (j->isSelected() && (selvisible > 0.0))
			{
				B.applyTranslationZ((selscale*radius_j-radius_j) / dvisible);
				B.applyScalingZ(selvisible / dvisible);
				if (transparentSel)
				{
					colour_j.w = 0.5f;
					renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_j, bt), colour_j, B);
					colour_j.w = alpha_j;
				}
				else renderPrimitive(selectionList, primitives_[primitiveSet_].selectedBond(style_j, bt), colour_j, B, GL_LINE);
			}
			break;
	}
}

// Render full Model
void Viewer::renderModel(Model* source, bool currentModel, bool renderType)
{
	Messenger::enter("Viewer::renderModel");
	GLfloat colour[4];

	// Valid pointer passed?
	if (source == NULL)
	{
		Messenger::exit("Viewer::renderModel");
		return;
	}
	Messenger::print(Messenger::Verbose, " --> RENDERING BEGIN : source model pointer = %p, renderpoint = %d\n", source, source->changeLog.log(Log::Total));

	// Set initial transformation matrix, including any translation occurring from cell...
	modelTransformationMatrix_ = source->modelViewMatrix();
	modelTransformationMatrix_.applyTranslation(source->cell()->centre());
	
	// Set target matrix mode and reset it, and set colour mode
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Grab model-specific viewport
	GLint* vp = source->viewportMatrix();

	// Render rotation globe in small viewport in lower right-hand corner
	if (prefs.viewRotationGlobe())
	{
		int n = prefs.globeSize();
		if (aten_->nVisibleModels() > 2) n /= 2;
		glViewport(vp[0]+vp[2]-n,vp[1],n,n);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		Matrix A = modelTransformationMatrix_;
		A.removeTranslationAndScaling();
		A[14] = -1.2;
		glMultMatrixd(A.matrix());
		prefs.copyColour(Prefs::GlobeColour, colour);
		glColor4fv(colour);
		primitives_[primitiveSet_].rotationGlobe().sendToGL();
	}

	// Prepare for model rendering
	glViewport(vp[0], vp[1], vp[2], vp[3]);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(source->modelProjectionMatrix().matrix());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Clear the necessary triangle lists (i.e. only those for which the content may have changed)
	// By default, regenerate all lists (the case if the source model pointer has changed)
	
	int n;
	for (n=0; n<Viewer::nTriangleObjects; ++n) activePrimitiveLists_[n] = TRUE;
	if ((lastSource_ == source) && (!clearListsFlag_))
	{
		// Check model logs against logs stored when the lists were last generated
		bool redobasic = !lastLog_.isSame(Log::Coordinates,source->changeLog);
		if (!redobasic) redobasic = !lastLog_.isSame(Log::Structure,source->changeLog);

		// If the model style has changed, need to rerender both basic and selection lists. Otherwise, depends on other logs
		if (redobasic || (!lastLog_.isSame(Log::Style,source->changeLog)))
		{
			activePrimitiveLists_[Viewer::BasicObject] = TRUE;
			activePrimitiveLists_[Viewer::AtomSelectionObject] = TRUE;
		}
		else
		{
			activePrimitiveLists_[Viewer::BasicObject] = FALSE;
			activePrimitiveLists_[Viewer::AtomSelectionObject] = !lastLog_.isSame(Log::Selection, source->changeLog);
		}
		
		// Stick style primitives
		if (redobasic || (!lastLog_.isSame(Log::Style,source->changeLog)) || (!lastLog_.isSame(Log::Selection,source->changeLog)))
		{
			linePrimitives_[Viewer::NormalLineObject].forgetAll();
			linePrimitives_[Viewer::SelectedLineObject].forgetAll();
			rebuildSticks_ = TRUE;
		}
		else rebuildSticks_ = FALSE;
		
		// Glyphs must be redone on basic change (since they may follow atom coordinates
		if (redobasic || !lastLog_.isSame(Log::Glyphs, source->changeLog)) activePrimitiveLists_[Viewer::GlyphObject]  = TRUE;
		else activePrimitiveLists_[Viewer::GlyphObject]  = FALSE;
		
		// Grids only depend on their own log
		if (!lastLog_.isSame(Log::Grids, source->changeLog)) activePrimitiveLists_[Viewer::GridObject] = TRUE;
	}
	else
	{
		linePrimitives_[Viewer::NormalLineObject].forgetAll();
		linePrimitives_[Viewer::SelectedLineObject].forgetAll();
		rebuildSticks_ = TRUE;
	}

	// Always clear GUI line primitives
	linePrimitives_[Viewer::NormalGuiLineObject].forgetAll();
	linePrimitives_[Viewer::SelectedGuiLineObject].forgetAll();
	
	// Clear flagged lists
	for (n=0; n<Viewer::nTriangleObjects; ++n) if (activePrimitiveLists_[n])
	{
		solidPrimitives_[n].clear();
	}
	
	// Extra lists to clear for Glyphs
	if (activePrimitiveLists_[Viewer::GlyphObject])
	{
		glyphTriangles_[Viewer::SolidTriangle].forgetAll();
		glyphTriangles_[Viewer::WireTriangle].forgetAll();
		glyphLines_.forgetAll();
	}
	
	// Always draw unit cell, regardless of list status
	renderCell(source);
	
	// Draw main model (atoms, bonds, etc.)
	Matrix offset;
	for (int x = -source->repeatCellsNegative(0); x <= source->repeatCellsPositive(0); ++x)
	{
		for (int y = -source->repeatCellsNegative(1); y <= source->repeatCellsPositive(1); ++y)
		{
			for (int z = -source->repeatCellsNegative(2); z <= source->repeatCellsPositive(2); ++z)
			{
				offset.setIdentity();
				offset.addTranslation(source->cell()->axes() * Vec3<double>(x,y,z));
				
				if (activePrimitiveLists_[Viewer::BasicObject] || activePrimitiveLists_[Viewer::AtomSelectionObject]) renderAtomsAndBonds(source, offset);
			}
		}
	}

	// Draw model glyphs
	if (activePrimitiveLists_[Viewer::GlyphObject]) renderGlyphs(source);
	renderTextGlyphs(source);

	// Draw model grids
	if (activePrimitiveLists_[Viewer::GridObject]) renderGrids(source);
	renderGridText(source);
	
	lastSource_ = source;
	lastLog_ = source->changeLog;
	
	// Render additional data for active model
	if (renderType && currentModel)
	{
		// Render embellishments for current UserAction
		renderUserActions(source);

		// Render extras arising from open tool windows (current model only)
// 		renderWindowExtras(source);	// ATEN2 TODO
	}

	// If the stick primitives were regenerated, need to create a new instance (after popping the old one)
	if (rebuildSticks_) for (n = 0; n<Viewer::nLineObjects; ++n)
	{
		linePrimitives_[n].popInstance(context(), extensionsStack_.last());
		linePrimitives_[n].pushInstance(context(), extensionsStack_.last());
	}
	else for (n = NormalGuiLineObject; n<Viewer::nLineObjects; ++n)
	{
		linePrimitives_[n].popInstance(context(), extensionsStack_.last());
		linePrimitives_[n].pushInstance(context(), extensionsStack_.last());
	}

	// All 3D primitive objects have now been filtered, so sort and send to GL
	// ATEN2 TODO Send all primitives to display

	// Render overlays
	renderModelOverlays(source);

	// Reset the clear lists flag
	clearListsFlag_ = FALSE;

	Messenger::exit("Viewer::renderModel");
}

// Render basic model information (atoms, bonds, labels, and glyphs)
void Viewer::renderAtomsAndBonds(Model* source, Matrix baseTransform, bool isFragment)
{
	Messenger::enter("Viewer::renderAtomsAndBonds");
	Vec4<GLfloat> colour_i, colour_j, penColour;
	GLfloat alpha_i;
	int id_i, labels, m, n, el_j;
	Dnchar text;
	double selscale, radius_i, radius_j, phi, mag, best, delta;
	double aradius[Prefs::nDrawStyles];
	Atom *i, *j, *k, *l, **atoms;
	Vec3<double> pos, v, ijk, r1, r2, r3, r4;
	Vec4<double> screenr;
	Matrix atomTransform, A, B;
	Refitem<Bond,int>* rb;
	Refitem<Atom,int>* ra;
	Prefs::DrawStyle style_i, style_j, globalstyle;
	Prefs::ColouringScheme scheme;
	ForcefieldAtom *ffa;
	
	// Set target lists based on whether this is a fragment
	Viewer::TriangleObject basicList = (isFragment ? GuiObject : BasicObject);
	Viewer::TriangleObject selectionList = (isFragment ? GuiObject : AtomSelectionObject);
	int baseLineList = (isFragment ? NormalGuiLineObject : NormalLineObject);
	
	// Grab global style values and atom radii
	scheme = prefs.colourScheme();
	globalstyle = prefs.renderStyle();
	selscale = prefs.selectionScale();
	for (n=0; n<Prefs::nDrawStyles; ++n) aradius[n] = prefs.atomStyleRadius( (Prefs::DrawStyle) n);
	bool transparentSel = prefs.transparentSelectionStyle();
	prefs.copyColour(Prefs::TextColour, penColour);
	
	// Atoms and Bonds
	atoms = source->atomArray();
	for (n = 0; n<source->nAtoms(); ++n)
	{
		// Get atom pointer
		i = atoms[n];
		
		// Skip hidden atoms
		if (i->isHidden()) continue;
		
		// Grab atom coordinate - we'll need it a lot
		pos = i->r();

		// Move to local atom position
		atomTransform = baseTransform;
		atomTransform.applyTranslation(pos.x, pos.y, pos.z);
		
		// Select colour
		if (i->isPositionFixed()) prefs.copyColour(Prefs::FixedAtomColour, colour_i);
		else switch (scheme)
		{
			case (Prefs::ElementScheme):
				Elements().copyColour(i->element(), colour_i);
				break;
			case (Prefs::ChargeScheme):
				prefs.colourScale[0].colour(i->charge(), colour_i);
				break;
			case (Prefs::VelocityScheme):
				prefs.colourScale[1].colour(i->v().magnitude(), colour_i);
				break;
			case (Prefs::ForceScheme):
				prefs.colourScale[2].colour(i->f().magnitude(), colour_i);
				break;
			case (Prefs::CustomScheme):
				i->copyColour(colour_i);
				break;
			default:
				break;
		}
		// Store copy of alpha value
		alpha_i = colour_i[3];
		
		// Get atom style and render associated object
		style_i = (globalstyle == Prefs::IndividualStyle ? i->style() : globalstyle);
		
		if (style_i == Prefs::StickStyle)
		{
			// Only need to draw something if the atom has no bonds
			if (i->nBonds() == 0)
			{
				if (i->isSelected()) linePrimitives_[baseLineList+1].plotCross(0.5, atomTransform, colour_i);
				else linePrimitives_[baseLineList].plotCross(0.5, atomTransform, colour_i);
			}
		}
		else
		{
			radius_i = aradius[style_i];
			if (style_i == Prefs::ScaledStyle) radius_i *= Elements().el[i->element()].atomicRadius;
			A = atomTransform;
			A.applyScaling(radius_i,radius_i,radius_i);
			renderPrimitive(basicList, primitives_[primitiveSet_].atom(), colour_i, A);
			if (i->isSelected())
			{
				if (transparentSel)
				{
					colour_i.w = 0.5f;
					renderPrimitive(selectionList, primitives_[primitiveSet_].selectedAtom(), colour_i, A);
					colour_i.w = alpha_i;
				}
				else renderPrimitive(selectionList, primitives_[primitiveSet_].selectedAtom(), penColour, A, GL_LINE);
			}
		}

		// Bonds
		// Grab some useful values from atom i
		id_i = i->id();
		if (style_i <= Prefs::TubeStyle) radius_i = 0.0;
		else if (style_i == Prefs::ScaledStyle) radius_i = prefs.styleRadius(Prefs::ScaledStyle, i->element()) - scaledAtomAdjustments_[i->element()];
		else radius_i = prefs.styleRadius(style_i, i->element()) - sphereAtomAdjustment_;
		
		for (rb = i->bonds(); rb != NULL; rb = rb->next)
		{
			j = rb->item->partner(i);
			if (id_i > j->id()) continue;
			
			// Grab colour of second atom
			if (j->isPositionFixed()) prefs.copyColour(Prefs::FixedAtomColour, colour_j);
			else switch (scheme)
			{
				case (Prefs::ElementScheme):
					Elements().copyColour(j->element(), colour_j);
					break;
				case (Prefs::ChargeScheme):
					prefs.colourScale[0].colour(j->charge(), colour_j);
					break;
				case (Prefs::VelocityScheme):
					prefs.colourScale[1].colour(j->v().magnitude(), colour_j);
					break;
				case (Prefs::ForceScheme):
					prefs.colourScale[2].colour(j->f().magnitude(), colour_j);
					break;
				case (Prefs::CustomScheme):
					j->copyColour(colour_j);
					break;
				default:
					break;
			}
			
			// Get atom style and radius
			style_j = (globalstyle == Prefs::IndividualStyle ? j->style() : globalstyle);
			if (style_j <= Prefs::TubeStyle) radius_j = 0.0;
			else if (style_j == Prefs::ScaledStyle) radius_j = prefs.styleRadius(Prefs::ScaledStyle, j->element()) - scaledAtomAdjustments_[j->element()];
			else radius_j = prefs.styleRadius(style_j, j->element()) - sphereAtomAdjustment_;
			
			// Calculate vector i->j
			v = source->cell()->mimVector(i, j);
			
			// Render bond
			renderBond(basicList, selectionList, atomTransform, v, i, style_i, colour_i, radius_i, j, style_j, colour_j, radius_j, rb->item->type(), selscale, rb->item, transparentSel);
		}
		
	}
	
	// Aromatic rings (needs valid pattern description)
	if (source->arePatternsValid())
	{
		prefs.copyColour(Prefs::AromaticRingColour, colour_i);

		atoms = source->atomArray();
		for (Pattern *p = source->patterns(); p != NULL; p = p->next)
		{
			// Continue if no rings present in pattern
			if (p->rings() == NULL) continue;

			// Cycle over rings
			for (Ring *r = p->rings(); r != NULL; r = r->next)
			{
				if (r->type() != Ring::AromaticRing) continue;
				
				// Loop over pattern molecules
				id_i = 0;
				for (m=0; m<p->nMolecules(); ++m)
				{
					// Determine ring centroid
					ra = r->atoms();
					i = atoms[id_i+ra->item->id()];
					r1 = i->r();
					pos = r1;
					for (ra = ra->next; ra != NULL; ra = ra->next)
					{
						j = atoms[id_i+ra->item->id()];
						pos += source->cell()->mim(j->r(), r1);
					}
					pos /= r->nAtoms();

					// Determine average vector magnitude of ring atoms and y-axis vector (closest 90deg vector)
					mag = 0.0;
					r1 -= pos;
					r1.normalise();
					best = PI/2.0;
					r2.zero();
					radius_i = 0.0;
					
					for (ra = r->atoms(); ra != NULL; ra = ra->next)
					{
						// Grab atom pointer and get minimum image vector with centroid 'v'
						i = atoms[id_i+ra->item->id()];
						if (prefs.styleRadius(i->style(), i->element()) > radius_i) radius_i = prefs.styleRadius(i->style(), i->element());
						v = source->cell()->mimVector(pos, i->r());
						// Accumulate magnitude
						mag += v.magnitude();
						v.normalise();
						phi = fabs(PI/2.0 - acos(r1.dp(v)));
						if (phi < best)
						{
							r2 = v;
							best = phi;
						}
					}

					// Finalise values and create z-vector from cross product
					r2.orthogonalise(r1);
					r2.normalise();
					r3 = r1*r2;
					mag /= r->nAtoms();
					mag -= radius_i*0.9;
					mag *= 0.75;
					// Construct transformation matrix
					atomTransform = baseTransform;
					atomTransform.applyTranslation(pos.x, pos.y, pos.z);
					A.setColumn(0, r1*mag, 0.0);
					A.setColumn(1, r2*mag, 0.0);
					A.setColumn(2, r3*mag, 0.0);
					A.setColumn(3, 0.0, 0.0, 0.0, 1.0);
					atomTransform *= A;

					// Render ring
					if (prefs.renderDashedAromatics())
					{
						if (globalstyle == Prefs::StickStyle) renderPrimitive(basicList, primitives_[primitiveSet_].segmentedLineRing(), colour_i, atomTransform);
						else renderPrimitive(basicList, primitives_[primitiveSet_].segmentedTubeRing(), colour_i, atomTransform);
					}
					else
					{
						if (globalstyle == Prefs::StickStyle) renderPrimitive(basicList, primitives_[primitiveSet_].lineRing(), colour_i, atomTransform);
						else renderPrimitive(basicList, primitives_[primitiveSet_].tubeRing(), colour_i, atomTransform);
					}

					id_i += p->nAtoms();
				}
			}
		}
	}
	
	// Hydrogen bonds
	if (prefs.drawHydrogenBonds())
	{
		double dotradius = prefs.hydrogenBondDotRadius();
		atoms = source->atomArray();
		prefs.copyColour(Prefs::HydrogenBondColour, colour_i);
		for (n = 0; n<source->nAtoms(); ++n)
		{
			// Get atom pointer
			i = atoms[n];
			
			// Skip hidden atoms
			if (i->isHidden()) continue;
			
			// Skip non-hydrogen atoms (i.e. 'i' is *always* the hydrogen atom)
			if (i->element() != 1) continue;
			
			// Get bond partner of the hydrogen atom (if there isn't on, skip it)
			if (i->nBonds() != 1) continue;
			k = i->bonds()->item->partner(i);

			// Grab atom coordinate and style
			pos = i->r();
			style_i = (globalstyle == Prefs::IndividualStyle ? i->style() : globalstyle);
			if (style_i <= Prefs::TubeStyle) radius_i = 0.0;
			else if (style_i == Prefs::ScaledStyle) radius_i = prefs.styleRadius(Prefs::ScaledStyle, i->element()) - scaledAtomAdjustments_[i->element()];
			else radius_i = prefs.styleRadius(style_i, i->element()) - sphereAtomAdjustment_;
			
			// Loop over other atoms
			for (m = 0; m<source->nAtoms(); ++m)
			{
				j = atoms[m];

				// Skip hidden atoms
				if (j->isHidden()) continue;
				
				// Is i bound to j?
				if (i->findBond(j) != NULL) continue;
				
				// Element check
				el_j = j->element();
				if ((el_j != 7) && (el_j != 8) && (el_j != 8) && (Elements().group(el_j) != 17)) continue;
				
				// Get (any) bond partner of atom j
				l = j->nBonds() == 0 ? NULL : j->bonds()->item->partner(j);

				// Apply the rules as given in:
				// "Satisfying Hydrogen-Bonding Potential in Proteins"
				// I. K. McDonald and J. M. Thornton, J. Mol. Biol. 238, 777793 (1994)

				// Rule 1 - Distance D-A is less than 3.9 Angstroms
				if (source->cell()->distance(k,j) > 3.9) continue;
				
				// Rule 2 - Distance H-A is less than 2.5 Angstroms
				v = source->cell()->mimVector(i,j);
				mag = v.magnitude();
				if (mag > 2.5) continue;
				
				// Rule 3 - Angle D-H-A is greater than 90 degrees
				if (source->cell()->angle(k,i,j) <= 90.0) continue;
				
				// Rule 4 - Angle A'-A-D is greater than 90 degrees (only if atom j has a bond partner)
				if ((l != NULL) && (source->cell()->angle(k,j,l) <= 90.0)) continue;
				
				// Rule 5 - Angle A'-A-H is greater than 90 degrees (only if atom j has a bond partner)
				if ((l != NULL) && (source->cell()->angle(i,j,l) <= 90.0)) continue;
				
				// If we get here then its a hydrogen bond.
				// First, determine the 'drawable' region between the two atoms i,j
				// Adjust for atom radii in current style
				style_j = (globalstyle == Prefs::IndividualStyle ? j->style() : globalstyle);
				if (style_j <= Prefs::TubeStyle) radius_j = 0.0;
				else if (style_j == Prefs::ScaledStyle) radius_j = prefs.styleRadius(Prefs::ScaledStyle, j->element()) - scaledAtomAdjustments_[j->element()];
				else radius_j = prefs.styleRadius(style_j, j->element()) - sphereAtomAdjustment_;
				// Get normalised i-j vector
				r1 = v;
				r1.normalise();
				// Adjust starting position of drawing to the very closest point we will allow (where i and first dot would touch)
				pos += r1 * (radius_i + dotradius);
				// Adjust magnitude to be the available space between the two atoms
				mag -= (radius_i + radius_j + 2.0*dotradius);
				if (mag < 0.0) continue;
				
				// Determine spacing between dots (may be negative if there isn't enough room)
				delta = (mag - 6.0*dotradius) < 0.0 ? -1.0 : mag / 4.0;
				
				// The matrix 'atomtransform' will only contain the translation. Scaling will be applied to its copy in 'A'
				atomTransform = baseTransform;
				atomTransform.applyTranslation(pos);
				
				// H-bond dot 1
				if (delta > 0.0) atomTransform.applyTranslation(r1*delta);
				A = atomTransform;
				A.applyScaling(dotradius, dotradius, dotradius);
				renderPrimitive(basicList, primitives_[primitiveSet_].sphere(), colour_i, A);
				
				// H-bond dot 2
				if (delta > 0.0) atomTransform.applyTranslation(r1*delta);
				else atomTransform.applyTranslation(r1*mag*0.5);
				A = atomTransform;
				A.applyScaling(dotradius, dotradius, dotradius);
				renderPrimitive(basicList, primitives_[primitiveSet_].sphere(), colour_i, A);
				
				// H-bond dot 3
				if (delta > 0.0) atomTransform.applyTranslation(r1*delta);
				else atomTransform.applyTranslation(r1*mag*0.5);
				A = atomTransform;
				A.applyScaling(dotradius, dotradius, dotradius);
				renderPrimitive(basicList, primitives_[primitiveSet_].sphere(), colour_i, A);
			}
		}
	}
	Messenger::exit("Viewer::renderAtomsAndBonds");
}

// Render model cell
void Viewer::renderCell(Model* source)
{
	if (source->cell()->type() == UnitCell::NoCell) return;
	Messenger::enter("Viewer::renderCell");
	
	// Copy colour for cell
	GLfloat colour[4];
	prefs.copyColour(Prefs::UnitCellColour, colour);
	glColor4fv(colour);
	
	// Reset current view matrix and apply the cell's axes matrix
	glLoadIdentity();
	Matrix A = source->modelViewMatrix() * source->cell()->axes();
	glMultMatrixd(A.matrix());
	
	// Draw a wire cube for the cell
	primitives_[primitiveSet_].wireCube().sendToGL();

	// Copy colour for axes, move to llh corner, and draw them
	prefs.copyColour(Prefs::UnitCellAxesColour, colour);
	glColor4fv(colour);
	glTranslated(-0.5, -0.5, -0.5);
	Vec3<double> v = source->cell()->lengths();
	glScaled(1.0 / v.x, 1.0 / v.y, 1.0 / v.z);
	primitives_[primitiveSet_].cellAxes().sendToGL();

	Messenger::exit("Viewer::renderCell");
}

// Render grids
void Viewer::renderGrids(Model* source)
{
	Messenger::enter("Viewer::renderGrids");
	Matrix A;
	GLenum style;
	Vec4<GLfloat> colour, textColour;
	
	// Copy text colour
	prefs.copyColour(Prefs::TextColour, textColour);
	
	// Cycle over grids stored in current model
	for (Grid *g = source->grids(); g != NULL; g = g->next)
	{
		// Check visibility
		if (!g->isVisible()) continue;

		// Does a GridPrimitive already exist?
		GridPrimitive* gp = findGridPrimitive(g);

		// If the GridPrimitive exists and is 'in date', no need to regenerate it...
		if ((gp == NULL) || g->shouldRerender())
		{
			// Generate new GridPrimitive if required
			if (gp == NULL)
			{
				gp = gridPrimitives_.add();
				gp->setSource(g);
			}
			if (g->type() == Grid::RegularXYZData) gp->createSurfaceMarchingCubes();
			else if (g->type() == Grid::FreeXYZData)
			{
				// Construct the Delaunay triangulization of the surface
				// 				DelaunaySurface D(g);
			}
			else gp->createSurface2D();
			g->updateRenderPoint();
			
			// Construct axes?
			gp->createAxes();
		}
		
		// Grid primitive now exists (or has been updated) so create transformation and render it
		A.setIdentity();
		A.applyTranslation(g->origin());
		A.multiplyRotation(g->axes());
		if (g->style() == Grid::TriangleSurface) style = GL_LINE;
		else if (g->style() == Grid::SolidSurface) style = GL_FILL;
		else style = GL_POINT;
		if (g->useColourScale()) renderPrimitive(Viewer::GridObject, gp->primaryPrimitive(), colour, A, style);
		else
		{
			g->copyPrimaryColour(colour);
			renderPrimitive(Viewer::GridObject, gp->primaryPrimitive(), colour, A, style);
		}
		if (g->useSecondary())
		{
			if (g->useColourScale()) renderPrimitive(Viewer::GridObject, gp->secondaryPrimitive(), colour, A, style);
			else
			{
				g->copySecondaryColour(colour);
				renderPrimitive(Viewer::GridObject, gp->secondaryPrimitive(), colour, A, style);
			}
		}

		// Render axes?
		colour.set(0.0, 0.0, 0.0, 1.0);
		for (int n=0; n<3; ++n) if (g->isAxisVisible(n)) renderPrimitive(Viewer::GridObject, gp->axisLinePrimitive(n), colour, A, GL_LINE);

		// Render volume outline
		if (g->outlineVolume())
		{
			A.columnMultiply(0, g->nXYZ().x);
			A.columnMultiply(1, g->nXYZ().y);
			A.columnMultiply(2, g->nXYZ().z);
			renderPrimitive(Viewer::GridObject, primitives_[primitiveSet_].originCube(), textColour, A, GL_LINE, 1.0);
		}

	}
	Messenger::exit("Viewer::renderGrids");
}

// Render text for grids
void Viewer::renderGridText(Model* source)
{
	Messenger::enter("Viewer::renderGridText");
	// Cycle over grids stored in current model
	for (Grid *g = source->grids(); g != NULL; g = g->next)
	{
		// Check visibility
		if (!g->isVisible()) continue;

		// Setup transformation matrix for Grid
		Matrix A;
		A.setIdentity();
		A.applyTranslation(g->origin());
		A.multiplyRotation(g->axes());

		// Find GridPrimitive for this Grid
		GridPrimitive* gp = findGridPrimitive(g);
		if (gp == NULL)
		{
			printf("Internal Error: Tried to render text for Grid, but no GridPrimitive has been created.\n");
			continue;
		}

		// Loop over axes
		for (int n=0; n<3; ++n)
		{
			// Is axis visible
			if (!g->isAxisVisible(n)) continue;
			
			// Dump text for this axis
			Vec3<double> r, r2;
			Vec4<double> screenr;
			// ATEN2 TODO
// 			for (TextPrimitive3D *tp = gp->axisTextPrimitives(n).first(); tp != NULL; tp = tp->next)
// 			{
// 				r = A * tp->r();
// 				r2 = source->modelToWorld(r, &screenr);
// 				if (r2.z < -1.0) renderTextPrimitive(screenr.x, screenr.y, tp->text(), 0, tp->rightAlign());
// 			}
		}
	}
	Messenger::exit("Viewer::renderGridText");
}

// Render additional model information (measurements etc.)
void Viewer::renderModelOverlays(Model* source)
{
	Vec3<double> r1, r2, r3, r4, rji, rjk, pos;
	Vec4<double> screenr;
	GLfloat colour[4];
	double gamma, t;
	int labels;
	Dnchar text(512);
	Atom **atoms, *i;
	ForcefieldAtom *ffa;

	// Clear depth buffer to force lines on top of existing primitives,
	glDisable(GL_DEPTH_TEST);
	
	// Set colour
	prefs.copyColour(Prefs::TextColour, colour);
	glColor4fv(colour);
	
	// Atoms and Bonds
	atoms = source->atomArray();
	for (int n = 0; n<source->nAtoms(); ++n)
	{
		// Get atom pointer
		i = atoms[n];
		
		// Skip hidden atoms
		if (i->isHidden()) continue;
		
		// Labels
		labels = i->labels();
		if (labels == 0) continue;
		
		// Grab forcefield atom pointer
		ffa = i->type();
		
		// Blank label string
		text.clear();
		// Now add on all parts of the label that are required
		if (labels&(1 << Atom::IdLabel)) text.strcatf("%i ", i->id()+1);
		if (labels&(1 << Atom::ElementLabel)) text.strcatf("%s ", Elements().symbol(i));
		if (labels&(1 << Atom::TypeLabel))
		{
			if (ffa == NULL) text.strcat("[None] ");
			else text.strcatf("[%i %s] ", ffa->typeId(), ffa->name());
		}
		if (labels&(1 << Atom::EquivLabel)) text.strcatf("[=%s] ", ffa == NULL ? "None" : ffa->equivalent());
		if (labels&(1 << Atom::ChargeLabel)) text.strcatf(prefs.chargeLabelFormat(), i->charge());
		
		// Add text object
		r2 = source->modelToWorld(i->r(), &screenr);
		if (r2.z < -1.0) renderTextPrimitive(screenr.x, screenr.y, text.get());
	}
	
	// Measurements
	// Apply standard transformation matrix to OpenGL so we may just use local atom positions for vertices
	// Load model transformation matrix
	glLoadIdentity();
	glMultMatrixd(modelTransformationMatrix_.matrix());
	
	// Distances
	for (Measurement* m = source->distanceMeasurements(); m != NULL; m = m->next)
	{
		atoms = m->atoms();
		// Check that all atoms involved in the measurement are visible (i.e. not hidden)
		if (atoms[0]->isHidden() || atoms[1]->isHidden()) continue;
		r1 = atoms[0]->r();
		r2 = atoms[1]->r();
		glBegin(GL_LINES);
		glVertex3d(r1.x, r1.y, r1.z);
		glVertex3d(r2.x, r2.y, r2.z);
		glEnd();
		r4 = (r1+r2)*0.5;
		r3 = source->modelToWorld(r4, &screenr);
		if (r3.z < -1.0) renderTextPrimitive(screenr.x, screenr.y, ftoa(m->value(), prefs.distanceLabelFormat()), 0x212b);
	}
	
	// Angles
	for (Measurement* m = source->angleMeasurements(); m != NULL; m = m->next)
	{
		atoms = m->atoms();
		// Check that all atoms involved in the measurement are visible (i.e. not hidden)
		if (atoms[0]->isHidden() || atoms[1]->isHidden() || atoms[2]->isHidden()) continue;
		r1 = atoms[0]->r();
		r2 = atoms[1]->r();
		r3 = atoms[2]->r();
		glBegin(GL_LINE_STRIP);
		glVertex3d(r1.x, r1.y, r1.z);
		glVertex3d(r2.x, r2.y, r2.z);
		glVertex3d(r3.x, r3.y, r3.z);
		glEnd();
		// Curved angle marker
		rji = (r1 - r2);
		rjk = (r3 - r2);
		rji.normalise();
		rjk.normalise();
		gamma = acos(rji.dp(rjk));
		// Draw segments
		t = 0.0;
		glBegin(GL_LINES);
		for (int n=0; n<11; n++)
		{
			pos = (rji * sin((1.0-t)*gamma) + rjk * sin(t*gamma)) / sin(gamma);
			pos *= 0.2;
			pos += r2;
			glVertex3d(pos.x, pos.y, pos.z);
			t += 0.1;
			// Store text position
			if (n == 5) r4 = pos;
		}
		glEnd();
		// Determine left or right-alignment of text
		source->modelToWorld(r2, &screenr);
		gamma = screenr.x;
		r3 = source->modelToWorld(r4, &screenr);
		if (r3.z < -1.0) renderTextPrimitive(screenr.x, screenr.y, ftoa(m->value(), prefs.angleLabelFormat()), 176, gamma > screenr.x);
	}
	
	// Torsions
	for (Measurement* m = source->torsionMeasurements(); m != NULL; m = m->next)
	{
		atoms = m->atoms();
		// Check that all atoms involved in the measurement are visible (i.e. not hidden)
		if (atoms[0]->isHidden() || atoms[1]->isHidden() || atoms[2]->isHidden() || atoms[3]->isHidden()) continue;
		r1 = atoms[0]->r();
		r2 = atoms[1]->r();
		r3 = atoms[2]->r();
		r4 = atoms[3]->r();
		glBegin(GL_LINE_STRIP);
		glVertex3d(r1.x, r1.y, r1.z);
		glVertex3d(r2.x, r2.y, r2.z);
		glVertex3d(r3.x, r3.y, r3.z);
		glVertex3d(r4.x, r4.y, r4.z);
		glEnd();
		r1 = (r2+r3)*0.5;
		r4 = source->modelToWorld(r1, &screenr);
		if (r4.z < -1.0) renderTextPrimitive(screenr.x, screenr.y, ftoa(m->value(), prefs.angleLabelFormat()), 176);
	}
	
	// Re-enable depth buffer
	glEnable(GL_DEPTH_TEST);
}
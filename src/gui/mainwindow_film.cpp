/*
	*** Main Window - Film Functions
	*** src/gui/mainwindow_film.cpp
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

#include "gui/mainwindow.h"
#include "main/aten.h"
#include <QMessageBox>

// Cleanup film export files
void AtenWindow::cleanupFilmExport(QStringList images, QString imagesFile)
{
	return;
	// Remove all files specified in the images list
	for (int n=0; n<images.count(); ++n)
	{
		// Make sure image exists before we try to delete it...
		if (!QFileInfo::exists(images.at(n))) continue;
		QFile::remove(images.at(n));
	}

	// Check imagesFile
	if ((!imagesFile.isEmpty()) && QFileInfo::exists(imagesFile)) QFile::remove(imagesFile);
}

// Export film
bool AtenWindow::exportFilm()
{
	// Basic variables
	int indexWidth = 7;

	// Get relevant info for film
	int imageWidth = exportFilmDialog_.filmWidth();
	int imageHeight = exportFilmDialog_.filmHeight();
	int fps = exportFilmDialog_.fps();

	// If encoding, get output filename and make sure it doesn't exist (or we are allowed to overwrite it)
	QString outputFile = exportFilmDialog_.outputFilename();
	if (exportFilmDialog_.outputFilm())
	{
		if (QFileInfo::exists(outputFile))
		{
			if (QMessageBox::question(this, "Overwrite File?", "Output film file already exists. Overwrite it?") == QMessageBox::No) return false;
		}
	}

	// We will always save the images, regardless of the type of output we're doing - the only difference will be the basename/location
	QString imageBasename;
	QString imageExtension;
	
	if (exportFilmDialog_.outputImages())
	{
		imageBasename = exportFilmDialog_.imageBasename();
		imageExtension = exportFilmDialog_.imageExtension();
	}
	else
	{
		// Always generate png images
		imageExtension = "png";

		// Generate unique run number id for image file saving
		int runid;
		do
		{
			runid = AtenMath::randomimax();
			imageBasename = prefs.tempDir().absoluteFilePath(QString("aten-filmexport-%1").arg(runid, 9, 10, QChar('0')));
		}
		while (QFileInfo::exists(QString("%1-%2.%3").arg(imageBasename).arg(0, indexWidth, 10, QChar('0')).arg(imageExtension)));
	}

	// Almost ready!
	Model* model = aten_.currentModelOrFrame();
	int startIndex, endIndex, nFrames;

	// Check setup for selected source, and construct the script. The script will be constructed as follows, using global variables to have any necessary persistent
	// values between frames. A function called 'next' will be called after each image is saved.
	QStringList scriptStrings;

	// Always need global frameIndex variable
	scriptStrings << "    int next(int frameIndex) {";

	// Get start and end frame indices, and add necessary code to script
	if (exportFilmDialog_.viewSource())
	{
		startIndex = 1;
		endIndex = exportFilmDialog_.viewNFrames();
	}
	else if (exportFilmDialog_.trajectorySource())
	{
		// Double-check that current model has a trajectory, or this is a trajectory frame
		if ((!model->hasTrajectory()) && (model->type() != Model::TrajectoryFrameType))
		{
			Messenger::error("Trajectory film requested, but none associated to current model.");
			return false;
		}

		startIndex = exportFilmDialog_.trajectoryStartFrame();
		endIndex = exportFilmDialog_.trajectoryEndFrame();

		scriptStrings << "seekFrame(frameIndex);";
	}
	else if (exportFilmDialog_.vibrationSource())
	{
		// ATEN2 TODO
	}
	nFrames = (endIndex - startIndex) + 1;

	// Add on view rotation if requested
	if (exportFilmDialog_.rotateView())
	{
		Vec3<bool> rotateAxis = exportFilmDialog_.rotateViewAxes();
		Vec3<bool> rotateWhole = exportFilmDialog_.rotateViewWhole();
		Vec3<double> rotationDelta = exportFilmDialog_.rotateViewDeltas();
		Vec3<double> rotationWhole = exportFilmDialog_.rotateViewWholeRotations();

		// Add commands to script
		for (int n=0; n<3; ++n)
		{
			if (!rotateAxis[n]) continue;

			// Calculate rotation deltas if using whole numbers of rotations
			if (rotateWhole[n]) rotationDelta[n] = (rotationWhole[n]*360.0) / nFrames;

			if (n == 0) scriptStrings << QString("rotateView(%1, 0.0);").arg(rotationDelta[n]);
			else if (n == 1) scriptStrings << QString("rotateView(0.0, %1);").arg(rotationDelta[n]);
			else if (n == 2) scriptStrings << QString("zRotateView(%1);").arg(rotationDelta[n]);
		}
	}

	scriptStrings << "}";

	// Compile script. and grab necessary functions from script
	Program filmScript;
	if (!filmScript.generateFromStringList(scriptStrings, "Film Script", "Script generated by exportFilm()", false))
	{
		Messenger::error("Failed to create film script.");
		return false;
	}

	Tree* nextFunction = filmScript.findFunction("next");
	if (!nextFunction)
	{
		Messenger::error("Failed to find required 'next' function in film script.");
		return false;
	}

	// Ready - loop over start/end frame range. Save images and build up image list
	QStringList frameImages;
	ReturnValue rv;
	Task* task = Messenger::initialiseTask("Exporting Images", nFrames);
	for (int frame = startIndex; frame <= endIndex; ++frame)
	{
		// Generate image filename
		QString imageFilename = QString("%1-%2.%3").arg(imageBasename).arg(frame, indexWidth, 10, QChar('0')).arg(imageExtension);
		frameImages << imageFilename;

		// Generate and save image
		QPixmap pixmap = scenePixmap(imageWidth, imageHeight);
		if (!pixmap.save(imageFilename, qPrintable(imageExtension), -1))
		{
			Messenger::error("Failed to save image '%s'.", qPrintable(imageFilename));
			if (!exportFilmDialog_.outputImages()) cleanupFilmExport(frameImages, QString());
			return false;
		}

		// Run script commands
		rv.set(frame);
		filmScript.executeFunction("next", rv, "i", frame);

		if (!Messenger::incrementTaskProgress(task))
		{
			if (!exportFilmDialog_.outputImages()) cleanupFilmExport(frameImages, QString());
			return false;
		}
	}
	Messenger::terminateTask(task);

	// Perform encoding?
	if (exportFilmDialog_.outputFilm())
	{
		// Check encoder 
		EncoderDefinition* encoder = exportFilmDialog_.encoder();
		if (!encoder)
		{
			Messenger::error("Film output requested, but no encoder specified.");
			cleanupFilmExport(frameImages, QString());
			return false;
		}

		// Write frames file
		QString framesFile = imageBasename + ".frames";
		LineParser parser;
		parser.openOutput(framesFile, true);
		if (!parser.isFileGoodForWriting())
		{
			Messenger::error("Failed to open frames file '%s' for writing.", qPrintable(framesFile));
			cleanupFilmExport(frameImages, QString());
			return false;
		}
		for (int n=0; n<frameImages.count(); ++n) parser.writeLineF("%s\n", qPrintable(frameImages.at(n)));
		parser.closeFiles();

		// Loop over steps defined in encoder definition
		Task* encoderTask = Messenger::initialiseTask("Encoding film", encoder->nCommands());
		for (ExternalCommand* command = encoder->commands(); command != NULL; command = command->next)
		{
			Messenger::print("Executing command '%s'", qPrintable(command->name()));

			// Grab executable absolute path (and check it)
			QString executable = command->absoluteExecutable();
			if (executable.isEmpty())
			{
				Messenger::error("Failed to locate executable '%s' in any search path specified.", qPrintable(command->executable()));
				cleanupFilmExport(frameImages, framesFile);
				Messenger::terminateTask(encoderTask);
				return false;
			}

			// Construct arguments stringlist, replacing any strings that we need to
			QString arguments = command->arguments();
			arguments.replace("FRAMESPERSECOND", QString::number(fps));
			arguments.replace("FRAMESFILE", framesFile);
			arguments.replace("FRAMEBASENAME", imageBasename);
			arguments.replace("OUTPUTFILE", outputFile);
			arguments.replace("FRAMEFORMAT", imageExtension);
			arguments.replace("FRAMEWIDTH", QString::number(imageWidth));
			arguments.replace("FRAMEHEIGHT", QString::number(imageHeight));
			arguments.replace("FRAMESIZE", QString("%1x%2").arg(imageWidth).arg(imageHeight));

			// Print intended comand to execute
			Messenger::print(QString("Command to execute is: %1 %2").arg(executable, arguments));

			// Execute external task
			Task* commandTask = Messenger::initialiseCommandTask(command->name(), executable, arguments);
			while (!commandTask->commandFinished())
			{
				if (!Messenger::incrementTaskProgress(commandTask))
				{
					Messenger::error("Encoder task '%s' exited early. See messages for details.", qPrintable(command->name()));
					cleanupFilmExport(frameImages, framesFile);
					Messenger::terminateTask(encoderTask);
					return false;
				}
			}
			if (commandTask->commandFailed())
			{
				Messenger::error("Encoder task '%s' failed. See messages for details.", qPrintable(command->name()));
				cleanupFilmExport(frameImages, framesFile);
				Messenger::terminateTask(commandTask);
				Messenger::terminateTask(encoderTask);
				return false;
			}
			Messenger::terminateTask(commandTask);

			// Check for cancellation in main encoding task
			if (!Messenger::incrementTaskProgress(encoderTask))
			{
				Messenger::error("Encoding canceled.");
				cleanupFilmExport(frameImages, framesFile);
				return false;
			}
		}
		Messenger::terminateTask(encoderTask);
	}

	return true;
}

// 	// Check that the specified vibration exists
// 	Vibration* vib = obj.rs()->vibration(vibrationId);
// 	if (!vib)
// 	{
// 		Messenger::print("Specified vibration (id %i) does not exist in current model.", vibrationId);
// 		return false;
// 	}
// 	
// 	// Check initial movie 'setup'
// 	int runid = movieSetup(true, height);
// 	if (runid == -1) return false;
// 
// 	// Generate vibration frams info
// 	obj.rs()->generateVibration(vibrationId, framesPerVibration);
// 	obj.rs()->setVibrationFrameIndex(0);
// 	obj.rs()->setRenderFromVibration(true);
// 
// 	QPixmap pixmap;
// 	QImage image;
// 
// 	int progid = progress.initialise("Saving vibration movie frames...", framesPerVibration);
// 	bool canceled = false;
// 	QString basename;
// 	for (int n = 0; n < framesPerVibration; ++n)
// 	{
// 		obj.rs()->setVibrationFrameIndex(n);
// 		
// 		basename = prefs.tempDir().filePath("aten-movie-%1-%2-%3.png").arg(QApplication::applicationPid(), runid).arg(n, 9, 10, QChar('0'));
// // 		parent_.updateWidgets(AtenWindow::MainViewTarget);
// 
// 		pixmap = aten_.atenWindow()->scenePixmap(width, height);
// 		pixmap.save(basename, "png", -1);
// 		
// 		if (!progress.update(progid,n))
// 		{
// 			canceled = true;
// 			Messenger::print("Canceled.");
// 			break;
// 		}
// 	}
// 	progress.terminate(progid);
// 	obj.rs()->setRenderFromVibration(fromVib);
// 
// 	// Construct list of ping-pong'ed frame images
// 	QStringList files;
// 	int n;
// 	for (int cycle = 0; cycle < nCycles; ++cycle)
// 	{
// 		// First half...
// 		for (n=0; n<framesPerVibration; ++n)
// 		{
// 			basename = prefs.tempDir().filePath("aten-movie-%1-%2-%3.png").arg(QApplication::applicationPid(), runid).arg(n, 9, 10, QChar('0'));
// 			files << basename;
// 		}
// 		// Second half...
// 		for (n=framesPerVibration-1; n>0; --n)
// 		{
// 			basename = prefs.tempDir().filePath("aten-movie-%1-%2-%3.png").arg(QApplication::applicationPid(), runid).arg(n, 9, 10, QChar('0'));
// 			files << basename;
// 		}
// 	}
// 
// 	// Reset after movie frame creation
// 	movieSetup(false, -1);
// 
// 	// Perform post-processing of movie frames
// 	if (!moviePostProcess(files, runid, c->argc(0), fps)) return false;
// 
// 	if (canceled) return false;
// 	
// 	return true;

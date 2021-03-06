// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Configuration.h"
#include "JsonConfigurationManager.h"
#include "UsualMatrixSerializer.h"
#include "Logging.h"
#include "Filesystem.h"
#include "ConsoleUserInterface.h"
#include "Setup.h"
#include "MatrixTypes.h"
#include "GaussSolver.h"


int main()
{
	bool unSuccessfullStart = CreateSettingsDir();

	LoggingInitialization();
	logging::add_common_attributes();
	
	if (unSuccessfullStart) {
		BoostLog(error, "The application started with errors");
	}
	else {
		BoostLog(info, "The application successfully started");
	}

	auto injector = BuildInjector();

	auto jsonManager = injector.create<JsonConfigurationManager>();
	Configuration configuration;
	configuration = jsonManager.Load();

	auto matrixSerializer = injector.create<UsualMatrixSerializer>();
		
	auto userInterface = injector.create<ConsoleUserInterface>();
	userInterface.Start();

	return unSuccessfullStart;
}


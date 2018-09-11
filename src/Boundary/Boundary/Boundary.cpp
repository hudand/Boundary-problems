// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Configuration.h"
#include "JsonConfigurationManager.h"
#include "Logging.h"
#include "Filesystem.h"

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

	JsonConfigurationManager jsonManager;
	Configuration configuration;
	
	configuration = jsonManager.Load();
		
	// ...

	jsonManager.Save(configuration);
	
	return unSuccessfullStart;
}


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
		boostLog(error, "The application started with errors");
	}
	else {
		boostLog(info, "The application successfully started");
	}

	JsonConfigurationManager jsonManager;
	Configuration configuration;
	
	try {
		configuration = jsonManager.Load();
		boostLog(info, "Settings successfully read");
	}
	catch (boost::property_tree::json_parser_error) {
		boostLog(error, "Errors when reading settings");
	} 
	
	// ...

	try {
		jsonManager.Save(configuration);
		boostLog(info, "Settings successfully written");
	}
	catch (...) {
		boostLog(error, "Errors when writing settings");
	}

	return unSuccessfullStart;
}


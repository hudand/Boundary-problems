// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Configuration.h"
#include "JsonConfigurationManager.h"
#include "UsualMatrixSerializer.h"
#include "Logging.h"
#include "Filesystem.h"
#include "Setup.h"

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
		
	// ...

	jsonManager.Save(configuration);

	auto matrixSerializer = injector.create<UsualMatrixSerializer>();
	
	UsualMatrix m;
	m = matrixSerializer.Load("matrix.dat");
	std::cout << m.size1() << " " << m.size2() << std::endl;
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++)
			std::cout << m(i, j) << " ";
		std::cout << std::endl;
	}

	m(1, 2) = 11;

	matrixSerializer.Save("matrix.dat", m); 
	
	return unSuccessfullStart;
}


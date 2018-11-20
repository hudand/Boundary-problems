// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Configuration.h"
#include "JsonConfigurationManager.h"
#include "UsualMatrixSerializer.h"
#include "Logging.h"
#include "Filesystem.h"
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
		
	// ...

	jsonManager.Save(configuration);

	auto matrixSerializer = injector.create<UsualMatrixSerializer>();
	
	UsualMatrix m;
	m = matrixSerializer.Load("linesystem.dat");
	std::cout << m.size1() << " " << m.size2() << std::endl;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 5; j++)
			std::cout << m(i, j) << " ";
		std::cout << std::endl;
	}

	//m(1, 2) = 11;

	//matrixSerializer.Save("matrix.dat", m); 

	Vector b(m.size1());
	for (unsigned i = 0; i < m.size1(); ++i)
	{
		b(i) = m(i, m.size2() - 1);
		std::cout << b(i) << " ";
	}
	std::cout << std::endl;

	m.resize(m.size1(), m.size1());

	GaussSolver solver;
	Vector x = solver.Solve(m, b);

	for (unsigned i = 0; i < m.size1(); ++i)
	{
		std::cout << x(i) << " ";
	}

	std::cout << std::endl;
		
	return unSuccessfullStart;
}


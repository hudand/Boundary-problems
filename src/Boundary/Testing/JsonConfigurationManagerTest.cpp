#include "pch.h"
#include "Auxiliary.cpp"
#include "JsonConfigurationManager.cpp"
#include "Filesystem.cpp"
#include "Logging.cpp"
#include "Configuration.h"


BOOST_FIXTURE_TEST_SUITE(TestJsonConfigurationManager, ClassForTesting)

BOOST_AUTO_TEST_CASE(TestJsonConfigurationManagerLoad)
{
	std::filesystem::path testPath("FilesForTesting");									   // path to the test json file
	testPath.append("testJsonConfigurationManagerLoad.json");			   

	Configuration configuration;
	JsonConfigurationManager jsonManager(testPath);
		
	configuration = jsonManager.Load();
	
	BOOST_CHECK_EQUAL(configuration.equation, "y''(x) + 1.3 * y'(x) + (y(x))^5 + y(x) = 10 * cos(x)");
	BOOST_CHECK_EQUAL(configuration.leftBound, "y(0) = 1.58");
	BOOST_CHECK_EQUAL(configuration.rightBound, "y(2 * pi) = 1.58");
	BOOST_CHECK_EQUAL(configuration.initialApproximation, "sin(x)");
	BOOST_CHECK_EQUAL(configuration.isInitialApproximationFromFile, false);
	BOOST_CHECK_EQUAL(configuration.isPeriodicProblem, false);

	BOOST_CHECK(configuration.regularization == Regularization::Full);
	BOOST_CHECK_CLOSE(configuration.alpha, 1e-4, 1);
	BOOST_CHECK_CLOSE(configuration.alpha2, 1e-7, 1);

	BOOST_CHECK_EQUAL(configuration.isUniformGrid, true);
	BOOST_CHECK_EQUAL(configuration.nodesCount, static_cast<size_t>(256));
	BOOST_CHECK_EQUAL(configuration.patternNodesCount, static_cast<size_t>(19));

	BOOST_CHECK(configuration.nonlinearMethod == IterativeMethod::Kalitkin);
	BOOST_CHECK_CLOSE(configuration.accuracy, 1e-12, 1);
	BOOST_CHECK(configuration.methodOrder == MethodOrder::Third);

	BOOST_CHECK(configuration.approximation == Approximation::Spline5);

	BOOST_CHECK_EQUAL(configuration.iterationMax, static_cast<size_t>(300));
	BOOST_CHECK_CLOSE(configuration.normMax, 1e50, 1);

}

BOOST_AUTO_TEST_CASE(TestJsonConfigurationManagerDefaultLoad)
{
	std::filesystem::path testPath("NoSuchFile.json");						// case when the file does not exist

	Configuration configuration;
	JsonConfigurationManager jsonManager(testPath);

	configuration = jsonManager.Load();

	BOOST_CHECK_EQUAL(configuration.equation, "y''(x) + 0.2 * y'(x) + (y(x))^3 + y(x) = 50 * cos(x)");
	BOOST_CHECK_EQUAL(configuration.leftBound, "y(0) = y(2 * pi)");
	BOOST_CHECK_EQUAL(configuration.rightBound, "y'(0) = y'(2 * pi)");
	BOOST_CHECK_EQUAL(configuration.initialApproximation, "sin(x) + cos(x)");
	BOOST_CHECK_EQUAL(configuration.isInitialApproximationFromFile, false);
	BOOST_CHECK_EQUAL(configuration.isPeriodicProblem, true);

	BOOST_CHECK(configuration.regularization == Regularization::Usual);
	BOOST_CHECK_CLOSE(configuration.alpha, 1e-5, 1);
	BOOST_CHECK_CLOSE(configuration.alpha2, 1e-8, 1);

	BOOST_CHECK_EQUAL(configuration.isUniformGrid, true);
	BOOST_CHECK_EQUAL(configuration.nodesCount, static_cast<size_t>(384));
	BOOST_CHECK_EQUAL(configuration.patternNodesCount, static_cast<size_t>(21));

	BOOST_CHECK(configuration.nonlinearMethod == IterativeMethod::Newton);
	BOOST_CHECK_CLOSE(configuration.accuracy, 1e-13, 1);
	BOOST_CHECK(configuration.methodOrder == MethodOrder::Second);

	BOOST_CHECK(configuration.approximation == Approximation::Spline3);

	BOOST_CHECK_EQUAL(configuration.iterationMax, static_cast<size_t>(500));
	BOOST_CHECK_CLOSE(configuration.normMax, 1e100, 1);

}

BOOST_AUTO_TEST_CASE(TestJsonConfigurationManagerSave)
{
	Configuration oldConfiguration;

	// partially change the default settings
	oldConfiguration.equation = "y''(x) = 5";
	oldConfiguration.leftBound = "y(0) = 100";
	oldConfiguration.isInitialApproximationFromFile = true;
	oldConfiguration.regularization = Regularization::Partial;
	oldConfiguration.alpha = 2.4;
	oldConfiguration.nodesCount = 512;
	oldConfiguration.methodOrder = MethodOrder::Hybrid;
	oldConfiguration.accuracy = 1e-9;
	oldConfiguration.normMax = 1e250;
	
	std::filesystem::path testPath("FilesForTesting");									   // settings saving
	testPath.append("Save.json");
	JsonConfigurationManager jsonManager(testPath);

	jsonManager.Save(oldConfiguration);

	Configuration configuration = jsonManager.Load();

	BOOST_CHECK_EQUAL(configuration.equation, "y''(x) = 5");
	BOOST_CHECK_EQUAL(configuration.leftBound, "y(0) = 100");
	BOOST_CHECK_EQUAL(configuration.rightBound, "y'(0) = y'(2 * pi)");
	BOOST_CHECK_EQUAL(configuration.initialApproximation, "sin(x) + cos(x)");
	BOOST_CHECK_EQUAL(configuration.isInitialApproximationFromFile, true);
	BOOST_CHECK_EQUAL(configuration.isPeriodicProblem, true);

	BOOST_CHECK(configuration.regularization == Regularization::Partial);
	BOOST_CHECK_CLOSE(configuration.alpha, 2.4, 1);
	BOOST_CHECK_CLOSE(configuration.alpha2, 1e-8, 1);

	BOOST_CHECK_EQUAL(configuration.isUniformGrid, true);
	BOOST_CHECK_EQUAL(configuration.nodesCount, static_cast<size_t>(512));
	BOOST_CHECK_EQUAL(configuration.patternNodesCount, static_cast<size_t>(21));

	BOOST_CHECK(configuration.nonlinearMethod == IterativeMethod::Newton);
	BOOST_CHECK_CLOSE(configuration.accuracy, 1e-9, 1);
	BOOST_CHECK(configuration.methodOrder == MethodOrder::Hybrid);

	BOOST_CHECK(configuration.approximation == Approximation::Spline3);

	BOOST_CHECK_EQUAL(configuration.iterationMax, static_cast<size_t>(500));
	BOOST_CHECK_CLOSE(configuration.normMax, 1e250, 1);

	std::filesystem::remove(testPath);
}

BOOST_AUTO_TEST_SUITE_END()




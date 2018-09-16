#include "pch.h"
#define BOOST_TEST_MODULE testJsonConfigurationManagerLoad
#include <boost/test/unit_test.hpp>
#include "JsonConfigurationManager.cpp"
#include "Filesystem.cpp"
#include "Logging.cpp"
#include "Configuration.h"

BOOST_AUTO_TEST_CASE(testJsonConfigurationManagerLoad)
{
	JsonConfigurationManager jsonManager;
	Configuration configuration;
	
	configuration = jsonManager.Load();

	BOOST_CHECK_EQUAL(configuration.equation, "y''(x) + 0.2 * y'(x) + (y(x))^5 + y(x) = 50 * cos(x)");
	BOOST_CHECK_EQUAL(configuration.leftBound, "y(0) = y(2 * pi)");
	BOOST_CHECK_EQUAL(configuration.rightBound, "y'(0) = y'(2 * pi)");
	BOOST_CHECK_EQUAL(configuration.initialApproximation, "sin(x) + cos(x)");
	BOOST_CHECK_EQUAL(configuration.isInitialApproximationFromFile, false);
	BOOST_CHECK_EQUAL(configuration.isPeriodicProblem, true);

	BOOST_CHECK(configuration.regularization == Regularization::Usual);
	BOOST_CHECK_CLOSE(configuration.alpha, 1e-5, 1);
	BOOST_CHECK_CLOSE(configuration.alpha2, 1e-8, 1);

	BOOST_CHECK_EQUAL(configuration.isUniformGrid, true);
	BOOST_CHECK_EQUAL(configuration.nodesCount, static_cast<unsigned int>(384));
	BOOST_CHECK_EQUAL(configuration.patternNodesCount, static_cast<unsigned int>(21));

	BOOST_CHECK(configuration.nonlinearMethod == IterativeMethod::Newton);
	BOOST_CHECK_CLOSE(configuration.accuracy, 1e-13, 1);
	BOOST_CHECK(configuration.methodOrder == MethodOrder::Second);

	BOOST_CHECK(configuration.approximation == Approximation::Spline3);

	BOOST_CHECK_EQUAL(configuration.iterationMax, static_cast<unsigned int>(500));
	BOOST_CHECK_CLOSE(configuration.normMax, 1e100, 1);

}

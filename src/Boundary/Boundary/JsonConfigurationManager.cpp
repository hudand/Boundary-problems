#include "stdafx.h"
#include "JsonConfigurationManager.h"
#include "Boundary.h"
#include "Logging.h"

namespace pt = boost::property_tree;

JsonConfigurationManager::JsonConfigurationManager()
{
	path = SettingsPath() / "Settings.json";
}

JsonConfigurationManager::JsonConfigurationManager(std::filesystem::path path)
{
	this->path = path;
}


JsonConfigurationManager::~JsonConfigurationManager()
{
}


void JsonConfigurationManager::Save(const Configuration& configuration)
{
	pt::ptree root;

	root.put("equation", configuration.equation);
	root.put("left_bound", configuration.leftBound);
	root.put("right_bound", configuration.rightBound);
	root.put("initial_approximation", configuration.initialApproximation);
	root.put("is_initial_approximation_from_file", configuration.isInitialApproximationFromFile);
	root.put("is_periodic_problem", configuration.isPeriodicProblem);

	root.put("regularization", int(configuration.regularization));
	root.put("alpha", configuration.alpha);
	root.put("alpha_2", configuration.alpha2);

	root.put("is_uniform_grid", configuration.isUniformGrid);
	root.put("nodes_count", configuration.nodesCount);
	root.put("pattern_nodes_count", configuration.patternNodesCount);

	root.put("nonlinear_method", int(configuration.nonlinearMethod));
	root.put("accuracy",configuration.accuracy);
	root.put("method_order", int(configuration.methodOrder));

	root.put("approximation", int(configuration.approximation));

	root.put("iteration_max",configuration.iterationMax);
	root.put("norm_max", configuration.normMax);

	pt::write_json(path.string(), root);
}

Configuration JsonConfigurationManager::DefaultLoad()
{
	Configuration configuration;

	configuration.equation = "y''(x) + 0.2 * y'(x) + (y(x))^3 + y(x) = 50 * cos(x)";
	configuration.leftBound = "y(0) = y(2 * pi)";
	configuration.rightBound = "y'(0) = y'(2 * pi)";
	configuration.initialApproximation = "sin(x) + cos(x)";
	configuration.isInitialApproximationFromFile = false;
	configuration.isPeriodicProblem = true;

	configuration.regularization = Regularization::Usual;
	configuration.alpha = 1e-5;
	configuration.alpha2 = 1e-8;

	configuration.isUniformGrid = true;
	configuration.nodesCount = 384;
	configuration.patternNodesCount = 21;

	configuration.nonlinearMethod = IterativeMethod::Newton;
	configuration.accuracy = 1e-13;
	configuration.methodOrder = MethodOrder::Second;

	configuration.approximation = Approximation::Spline3;

	configuration.iterationMax = 500;
	configuration.normMax = 1e100;

	return configuration;
}

Configuration JsonConfigurationManager::Load()
{
	pt::ptree root;
	Configuration configuration;
	
	try {
		pt::read_json(path.string(), root);
		boostLog(info, "The settings file is successfully parsed");
	}
	catch (pt::json_parser_error) {
		configuration = DefaultLoad();
		boostLog(warning, "When the settings file was parsed, errors occurred. The default settings are loaded");
		return configuration;
	}
		
	configuration.equation = root.get<std::string>("equation");
	configuration.leftBound = root.get<std::string>("left_bound");
	configuration.rightBound = root.get<std::string>("right_bound");
	configuration.initialApproximation = root.get<std::string>("initial_approximation");
	configuration.isInitialApproximationFromFile = root.get<bool>("is_initial_approximation_from_file");
	configuration.isPeriodicProblem = root.get<bool>("is_periodic_problem");

	configuration.regularization = Regularization(root.get<int>("regularization"));
	configuration.alpha = root.get<double>("alpha");
	configuration.alpha2 = root.get<double>("alpha_2");

	configuration.isUniformGrid = root.get<bool>("is_uniform_grid");
	configuration.nodesCount = root.get<int>("nodes_count");
	configuration.patternNodesCount = root.get<int>("pattern_nodes_count");

	configuration.nonlinearMethod = IterativeMethod(root.get<int>("nonlinear_method"));
	configuration.accuracy = root.get<double>("accuracy");
	configuration.methodOrder = MethodOrder(root.get<int>("method_order"));

	configuration.approximation = Approximation(root.get<int>("approximation"));

	configuration.iterationMax = root.get<int>("iteration_max");
	configuration.normMax = root.get<double>("norm_max");

	return configuration;
}

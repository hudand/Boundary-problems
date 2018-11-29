#include "stdafx.h"
#include "JsonConfigurationManager.h"
#include "Logging.h"
#include "Filesystem.h"

JsonConfigurationManager::JsonConfigurationManager() : path{ GetSettingsPath() / "Settings.json" }
{
	
}

JsonConfigurationManager::JsonConfigurationManager(std::filesystem::path path) : path{path}
{
	
}

void JsonConfigurationManager::Save(const Configuration& configuration)
{
	try {
		pt::ptree root;

		root.put("equation", configuration.equation);
		root.put("left_bound", configuration.leftBound);
		root.put("right_bound", configuration.rightBound);
		root.put("initial_approximation", configuration.initialApproximation);
		root.put("is_initial_approximation_from_file", configuration.isInitialApproximationFromFile);
		root.put("is_periodic_problem", configuration.isPeriodicProblem);

		root.put("regularization", static_cast<unsigned int>(configuration.regularization));
		root.put("alpha", configuration.alpha);
		root.put("alpha_2", configuration.alpha2);

		root.put("is_uniform_grid", configuration.isUniformGrid);
		root.put("nodes_count", configuration.nodesCount);
		root.put("pattern_nodes_count", configuration.patternNodesCount);

		root.put("nonlinear_method", static_cast<unsigned int>(configuration.nonlinearMethod));
		root.put("accuracy", configuration.accuracy);
		root.put("method_order", static_cast<unsigned int>(configuration.methodOrder));

		root.put("approximation", static_cast<unsigned int>(configuration.approximation));

		root.put("iteration_max", configuration.iterationMax);
		root.put("norm_max", configuration.normMax);

		pt::write_json(path.string(), root);

		BoostLog(info, "Settings successfully written");
	}
	catch (...) {
		BoostLog(error, "Errors when writing settings");
	}
	
}

Configuration JsonConfigurationManager::Load()
{
	pt::ptree root;
		
	try {
		pt::read_json(path.string(), root);
		Configuration configuration;

		configuration.equation = root.get<std::string>("equation");
		configuration.leftBound = root.get<std::string>("left_bound");
		configuration.rightBound = root.get<std::string>("right_bound");
		configuration.initialApproximation = root.get<std::string>("initial_approximation");
		configuration.isInitialApproximationFromFile = root.get<bool>("is_initial_approximation_from_file");
		configuration.isPeriodicProblem = root.get<bool>("is_periodic_problem");

		configuration.regularization = static_cast<Regularization>(root.get<unsigned int>("regularization"));
		configuration.alpha = root.get<double>("alpha");
		configuration.alpha2 = root.get<double>("alpha_2");

		configuration.isUniformGrid = root.get<bool>("is_uniform_grid");
		configuration.nodesCount = root.get<unsigned int>("nodes_count");
		configuration.patternNodesCount = root.get<unsigned int>("pattern_nodes_count");

		configuration.nonlinearMethod = static_cast<IterativeMethod>(root.get<unsigned int>("nonlinear_method"));
		configuration.accuracy = root.get<double>("accuracy");
		configuration.methodOrder = static_cast<MethodOrder>(root.get<unsigned int>("method_order"));

		configuration.approximation = static_cast<Approximation>(root.get<unsigned int>("approximation"));

		configuration.iterationMax = root.get<unsigned int>("iteration_max");
		configuration.normMax = root.get<double>("norm_max");

		BoostLog(info, "Settings successfully read");
		
		return configuration;
	}
	catch (pt::json_parser_error) {
		Configuration configuration;
		BoostLog(warning, "When the settings file was parsed, errors occurred. The default settings are loaded");
		return configuration;
	}
	
}

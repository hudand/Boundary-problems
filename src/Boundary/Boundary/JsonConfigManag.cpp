#include "stdafx.h"
#include "JsonConfigManag.h"
#include "Boundary.h"

namespace pt = boost::property_tree;

JsonConfigManag::JsonConfigManag()
{
	path = SettingsPath() / "Settings.json";
}

JsonConfigManag::JsonConfigManag(std::filesystem::path path)
{
	this->path = path;
}


JsonConfigManag::~JsonConfigManag()
{
}


void JsonConfigManag::Save(const Configuration& configuration)
{
	pt::ptree root;

	root.put("equation", configuration.equation);
	root.put("left_bound", configuration.lbound);
	root.put("right_bound", configuration.rbound);
	root.put("init_approximation", configuration.initApprox);
	root.put("is_init_approx_from_file", configuration.isInitApproxFromFile);

	root.put("regularization", int(configuration.regul));
	root.put("alpha", configuration.alpha);
	root.put("alpha_2", configuration.alpha2);

	root.put("is_uniform_grid", configuration.isUniformGrid);
	root.put("nodes_count", configuration.nodesCount);
	root.put("pattern_nodes_count", configuration.patternNodesCount);

	root.put("nonlin_method", int(configuration.nonlinMethod));
	root.put("accuracy",configuration.accuracy);
	root.put("method_order", int(configuration.methodOrder));

	root.put("approximation", int(configuration.approx));

	root.put("iteration_max",configuration.iterationMax);
	root.put("norm_max", configuration.normMax);

	pt::write_json(path.string(), root);
}

Configuration JsonConfigManag::Load()
{
	pt::ptree root;
	pt::read_json(path.string(), root);
	
	Configuration config;
	config.equation = root.get<std::string>("equation");
	config.lbound = root.get<std::string>("left_bound");
	config.rbound = root.get<std::string>("right_bound");
	config.initApprox = root.get<std::string>("init_approximation");
	config.isInitApproxFromFile = root.get<bool>("is_init_approx_from_file");

	config.regul = Regularization(root.get<int>("regularization"));
	config.alpha = root.get<double>("alpha");
	config.alpha2 = root.get<double>("alpha_2");

	config.isUniformGrid = root.get<bool>("is_uniform_grid");
	config.nodesCount = root.get<int>("nodes_count");
	config.patternNodesCount = root.get<int>("pattern_nodes_count");

	config.nonlinMethod = IterMethod(root.get<int>("nonlin_method"));
	config.accuracy = root.get<double>("accuracy");
	config.methodOrder = MethodOrder(root.get<int>("method_order"));

	config.approx = Approximation(root.get<int>("approximation"));

	config.iterationMax = root.get<int>("iteration_max");
	config.normMax = root.get<double>("norm_max");

	return config;
}

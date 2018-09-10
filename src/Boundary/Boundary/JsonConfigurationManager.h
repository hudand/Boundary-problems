#pragma once
#include "IConfigurationManager.h"
class JsonConfigurationManager :
	public IConfigurationManager
{
private:
	std::filesystem::path path;
	Configuration DefaultLoad();
public:
	JsonConfigurationManager();
	JsonConfigurationManager(std::filesystem::path path);
	~JsonConfigurationManager();
	Configuration Load() override;
	void Save(const Configuration& configuration) override;
};


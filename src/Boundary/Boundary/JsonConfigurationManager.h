#pragma once
#include "IConfigurationManager.h"
class JsonConfigurationManager :
	public IConfigurationManager
{
private:
	std::filesystem::path path;
public:
	JsonConfigurationManager();
	JsonConfigurationManager(std::filesystem::path path);
	~JsonConfigurationManager() = default;
	Configuration Load() override;
	void Save(const Configuration& configuration) override;
};


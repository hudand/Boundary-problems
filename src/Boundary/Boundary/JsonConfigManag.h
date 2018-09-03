#pragma once
#include "IConfigurationManager.h"
class JsonConfigManag :
	public IConfigurationManager
{
private:
	std::filesystem::path path;
public:
	JsonConfigManag();
	JsonConfigManag(std::filesystem::path path);
	~JsonConfigManag();
	Configuration Load() override;
	void Save(const Configuration& configuration) override;
};


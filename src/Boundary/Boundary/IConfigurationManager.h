#pragma once
#include "Configuration.h"

struct IConfigurationManager
{
	Configuration Load() = 0;
	void Save(const Configuration& configuration) = 0;

};


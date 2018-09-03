#pragma once
#include "Configuration.h"

struct IConfigurationManager
{
public:
	virtual Configuration Load() = 0;
	virtual void Save(const Configuration& configuration) = 0;
};


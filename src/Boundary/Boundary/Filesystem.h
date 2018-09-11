#pragma once

#include "stdafx.h"

std::string GetEnvironmentVariable(const std::string& name);
std::filesystem::path GetSettingsPath();
bool CreateSettingsDir();
std::string GetLogFilePath();

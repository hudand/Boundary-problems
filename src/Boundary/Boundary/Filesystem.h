#pragma once

#include "stdafx.h"

std::string GetEnvironmentVariable(const std::string& name);
std::filesystem::path SettingsPath();
bool CreateSettingsDir();
std::string LogFilePath(const std::string FileName);

#include "stdafx.h"

// Returns the value of the environment variable
std::string GetEnvironmentVariable(const std::string& name)
{
	char *buffer = nullptr;
	size_t length = 0;
	if (!_dupenv_s(&buffer, &length, name.c_str()) && buffer)
	{
		std::string s = std::string(buffer, length - 1);
		delete[] buffer;
		return s;
	}
	return "";
}

// Returns a path with a folder for settings
std::filesystem::path SettingsPath() {

	std::string s;
	s = GetEnvironmentVariable("LocalAppData");
	std::filesystem::path path(s);
	return path / "Boundary";
}

// Creates a folder with settings and project logs
bool CreateSettingsDir() {

	return std::filesystem::create_directory(SettingsPath());
}

// Returns the path to LogFile
std::string LogFilePath(const std::string FileName) {

	std::filesystem::path path = SettingsPath();
	path.append(FileName);
	return path.string();
}
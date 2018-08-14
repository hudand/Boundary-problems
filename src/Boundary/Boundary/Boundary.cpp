// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Getting the value of the environment variable
std::string GetEnvironmentVariable(const std::string& name)
{
	char *buffer = nullptr;
	size_t length = 0;
	if (!_dupenv_s(&buffer, &length, name.c_str()) && buffer)
	{
		std::string s = std::string(buffer, length-1);
		delete[] buffer;
		return s;
	}
	return "";
}

// Create a folder with settings and project logs
bool CreateDir() {

	std::string s;
	s = GetEnvironmentVariable("LocalAppData");
	std::filesystem::path path(s);
	path.append("Boundary");
	return std::filesystem::create_directory(path);
}

int main()
{
	return CreateDir();
}


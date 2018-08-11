// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <boost/any.hpp>
#include "di.hpp"
#include <string>
#include <filesystem>

// Получение значения переменной окружения
std::string GetEnvironmentVariable(const std::string& name)
{
	char *buffer = nullptr;
	size_t length = 0;
	if (!_dupenv_s(&buffer, &length, name.c_str()) && buffer)
	{
		return std::string(buffer, length);
	}
	return "";
}

// Создание папки с настройками и логами проекта
bool CreateDir() {

	std::string s;
	s = GetEnvironmentVariable("LocalAppData");
	s.erase(s.length() - 1); // удалил последний символ
	std::filesystem::path path(s + "\\Boundary");
	return std::filesystem::create_directory(path);
}

int main()
{
	return CreateDir();
}


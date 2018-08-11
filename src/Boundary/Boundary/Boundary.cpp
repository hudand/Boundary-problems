// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/any.hpp>
#include "di.hpp"
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <string.h>

int create_dir() {
	char *buff;
	size_t len;
	errno_t err1 = _dupenv_s(&buff, &len, "LocalAppData");
	if (err1) return -1;

	len += strlen("\\Boundary");
		
	errno_t err2 = strcat_s(buff, len, "\\Boundary");
	if (err2) return -1;
	
	CreateDirectoryA(buff, NULL);

	return 0;
}

int main()
{
	//std::string s = std::getenv("LocalAppData");
	create_dir();
	return 0;
}


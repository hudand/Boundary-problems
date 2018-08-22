// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

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

void init()
{
	logging::add_file_log
	(
		keywords::file_name = "sample.log",
		//keywords::rotation_size = 10 * 1024 * 1024,
		//keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
		keywords::format = "[%TimeStamp%]: %Message%"
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);
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
	init();
	logging::add_common_attributes();

	using namespace logging::trivial;
	src::severity_logger< severity_level > lg;

	BOOST_LOG_SEV(lg, trace) << "A trace severity message";
	BOOST_LOG_SEV(lg, debug) << "A debug severity message";
	BOOST_LOG_SEV(lg, info) << "An informational severity message";
	BOOST_LOG_SEV(lg, warning) << "A warning severity message";
	BOOST_LOG_SEV(lg, error) << "An error severity message";
	BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";

	return CreateDir();
}


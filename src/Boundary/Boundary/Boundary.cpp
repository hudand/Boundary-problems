// Boundary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;

// Returns the value of the environment variable
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

// Returns a path with a folder for settings
std::filesystem::path SettingsPath() {

	std::string s;
	s = GetEnvironmentVariable("LocalAppData");
	std::filesystem::path path(s);
	path.append("Boundary");
	return path;
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

// initializing the logging
void log_init()
{
	logging::add_file_log
	(
		keywords::file_name = LogFilePath("SimpleLog.log"),
		keywords::format =
		(
			expr::stream
			<< expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
			<< ": <" << logging::trivial::severity
			<< "> " << expr::smessage
			)
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);
}

int main()
{
	bool UnSuccessfullStart = CreateSettingsDir();

	log_init();
	logging::add_common_attributes();
	using namespace logging::trivial;
	src::severity_logger< severity_level > lg;

	if (UnSuccessfullStart) {
		BOOST_LOG_SEV(lg, error) << "The application started with errors";
	}
	else {
		BOOST_LOG_SEV(lg, info) << "The application successfully started";
	}

	return UnSuccessfullStart;
}


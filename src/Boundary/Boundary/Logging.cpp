#include "stdafx.h"
#include "Logging.h"
#include "Filesystem.h"

namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;

// initializing the logging
void LoggingInitialization()
{
	logging::add_file_log
	(
		keywords::file_name = GetLogFilePath(),
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

void BoostLog(severity_level level, const std::string& message) {
	static src::severity_logger< severity_level > lg;
	BOOST_LOG_SEV(lg, level) << message;
}




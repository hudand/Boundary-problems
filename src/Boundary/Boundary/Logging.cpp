#include "stdafx.h"
#include "Logging.h"

namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;

// initializing the logging
void LoggingInitialization()
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

void boostLog(severity_level level, std::string message) {
	src::severity_logger< severity_level > lg;
	BOOST_LOG_SEV(lg, level) << message;
}




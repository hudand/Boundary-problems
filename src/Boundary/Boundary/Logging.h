#pragma once
#include "stdafx.h"
#include "Boundary.h"

namespace logging = boost::log;
namespace src = boost::log::sources;
using namespace logging::trivial;

void LoggingInitialization();
void boostLog(severity_level level, std::string message);

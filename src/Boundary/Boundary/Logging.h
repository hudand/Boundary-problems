#pragma once
#include "stdafx.h"

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace pt = boost::property_tree;
using namespace logging::trivial;

void LoggingInitialization();
void BoostLog(severity_level level, const std::string& message);

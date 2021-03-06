// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
//#include <tchar.h>

#include "di.hpp"
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#pragma warning(push)
#pragma warning(disable:4996 )
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#pragma warning(pop)
#include <boost/numeric/ublas/triangular.hpp>
#include <algorithm>
#include <boost/algorithm/cxx11/copy_n.hpp>

// TODO: reference additional headers your program requires here

#include "pch.h"
#include <boost/test/unit_test.hpp>

struct ClassForTesting {
	ClassForTesting() {  }
	~ClassForTesting() {  }
};

const boost::test_tools::tt_detail::tolerance_manip<double> accuracy = boost::test_tools::tolerance(1e-8);


#include "pch.h"
#include <iostream>
#define BOOST_TEST_MODULE testCalculator
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(testCalculator)
{
	Calculator calculator(12);
	BOOST_CHECK_EQUAL(calculator.Result(), 12);
	calculator.Divide(3);
	BOOST_CHECK_EQUAL(calculator.Result(), 4);
	calculator.Divide(2);
	BOOST_CHECK_EQUAL(calculator.Result(), 2);
	calculator.Multiply(2);
	BOOST_CHECK_EQUAL(calculator.Result(), 4);
	calculator.Multiply(3);
	BOOST_CHECK_EQUAL(calculator.Result(), 12);
}

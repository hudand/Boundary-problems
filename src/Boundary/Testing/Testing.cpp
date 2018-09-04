#include "pch.h"
#include <iostream>
#include <boost/test/unit_test.hpp>
#define BOOST_TEST_MODULE testCalculator

class Calculator
{
public:
	explicit Calculator(int value)
		: Value_(value)
	{
	}

	void Divide(int value)
	{
		if (value == 0)
		{
			throw std::invalid_argument("Деление на ноль!");
		}
		Value_ /= value;
	}

	void Multiply(int value)
	{
		Value_ *= value;
	}

	int Result() const
	{
		return Value_;
	}

private:
	int Value_;
};

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

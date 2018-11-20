#include "pch.h"
#include <boost/test/unit_test.hpp>
#include "UsualMatrixSerializer.h"
#include "GaussSolver.cpp"
#include "Auxiliary.cpp"


BOOST_FIXTURE_TEST_SUITE(TestGaussSolver, ClassForTesting)

BOOST_AUTO_TEST_CASE(TestGaussSolverSolve)
{
	using namespace boost::numeric::ublas;

	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testGaussSolverSolve.dat");

	UsualMatrixSerializer serializer;
	UsualMatrix a = serializer.Load(testPath);

	unsigned rowCount = a.size1();
	unsigned columnCount = a.size2();

	BOOST_REQUIRE(rowCount == static_cast<unsigned>(4));
	BOOST_REQUIRE(columnCount == static_cast<unsigned>(5));
		
	matrix_column<UsualMatrix> lastColumn(a, columnCount - 1);

	Vector b = lastColumn;
	a.resize(rowCount, rowCount);

	GaussSolver solver;
	Vector x = solver.Solve(a, b);

	using namespace boost::test_tools;
	BOOST_TEST(x(0) == 14.57512563, tolerance(1e-8));
	BOOST_TEST(x(1) == -0.87282520, tolerance(1e-8));
	BOOST_TEST(x(2) == -0.93760283, tolerance(1e-8));
	BOOST_TEST(x(3) == -13.92221322, tolerance(1e-8));

}

BOOST_AUTO_TEST_SUITE_END()
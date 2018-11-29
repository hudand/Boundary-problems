#include "pch.h"
#include "Auxiliary.cpp"
#include "UsualMatrixSerializer.h"
#include "GaussSolver.cpp"



BOOST_FIXTURE_TEST_SUITE(TestGaussSolver, ClassForTesting)

BOOST_AUTO_TEST_CASE(TestGaussSolverSolve)
{
	using namespace boost::numeric::ublas;

	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testGaussSolverSolve.dat");

	UsualMatrixSerializer serializer;
	UsualMatrix a = serializer.Load(testPath);

	const size_t rowCount = a.size1();
	const size_t columnCount = a.size2();

	BOOST_REQUIRE(rowCount == static_cast<size_t>(4));
	BOOST_REQUIRE(columnCount == static_cast<size_t>(5));
		
	matrix_column<UsualMatrix> lastColumn(a, columnCount - 1);

	Vector b = lastColumn;
	a.resize(rowCount, rowCount);

	GaussSolver solver;
	Vector x = solver.Solve(a, b);

	BOOST_TEST(x(0) == 14.57512563, accuracy);
	BOOST_TEST(x(1) == -0.87282520, accuracy);
	BOOST_TEST(x(2) == -0.93760283, accuracy);
	BOOST_TEST(x(3) == -13.92221322, accuracy);

}

BOOST_AUTO_TEST_SUITE_END()
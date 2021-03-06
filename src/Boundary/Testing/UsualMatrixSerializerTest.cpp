#include "pch.h"
#include "Auxiliary.cpp"
#include "UsualMatrixSerializer.cpp"


BOOST_FIXTURE_TEST_SUITE(TestUsualMatrixSerializer, ClassForTesting)

BOOST_AUTO_TEST_CASE(TestUsualMatrixSerializerLoad)
{
	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testUsualMatrixSerializerLoad.dat");

	UsualMatrixSerializer serializer;
	UsualMatrix m = serializer.Load(testPath);
	
	BOOST_REQUIRE(m.size1() == static_cast<size_t>(3));
	BOOST_REQUIRE(m.size2() == static_cast<size_t>(4));
		
	BOOST_TEST(m(0, 0) == 2,	accuracy);
	BOOST_TEST(m(0, 3) == 2.1,	accuracy);
	BOOST_TEST(m(1, 2) == 5,	accuracy);
	BOOST_TEST(m(1, 3) == 3e-5, accuracy);
	BOOST_TEST(m(2, 1) == 4.6,	accuracy);
	BOOST_TEST(m(2, 3) == 1e12, accuracy);
}

BOOST_AUTO_TEST_CASE(TestUsualMatrixSerializerSave)
{
	UsualMatrix m(4, 3);

	m(0, 0) = 3.4;		m(0, 1) = 6.2;		m(0, 2) = -44.56;
	m(1, 0) = 13;		m(1, 1) = -226.5;	m(1, 2) = 1e-9;
	m(2, 0) = -4e25;	m(2, 1) = -67.5;	m(2, 2) = 19;
	m(3, 0) = -1665;	m(3, 1) = -0.0007;	m(3, 2) = 28;
	
	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testUsualMatrixSerializerSave.dat");

	UsualMatrixSerializer serializer;
	serializer.Save(testPath, m);

	UsualMatrix m1 = serializer.Load(testPath);
	
	std::filesystem::remove(testPath);

	BOOST_REQUIRE(m1.size1() == static_cast<size_t>(4));
	BOOST_REQUIRE(m1.size2() == static_cast<size_t>(3));
	for (size_t k = 0; k < 4; k++)
		for (size_t j = 0; j < 3; j++)
			BOOST_TEST(m(k, j) == m1(k, j), accuracy);
}

BOOST_AUTO_TEST_SUITE_END()

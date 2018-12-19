#include "pch.h"
#include "Auxiliary.cpp"
#include "VectorSerializer.cpp"


BOOST_FIXTURE_TEST_SUITE(TestVectorSerializer, ClassForTesting)

BOOST_AUTO_TEST_CASE(TestVectorSerializerLoad)
{
	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testVectorSerializerLoad.dat");

	VectorSerializer serializer;
	Vector v = serializer.Load(testPath);

	BOOST_REQUIRE(v.size() == static_cast<size_t>(7));
	
	BOOST_TEST(v(0) == 1.896, accuracy);
	BOOST_TEST(v(1) == 3, accuracy);
	BOOST_TEST(v(2) == 6.34, accuracy);
	BOOST_TEST(v(3) == -5.256, accuracy);
	BOOST_TEST(v(4) == 11.12, accuracy);
	BOOST_TEST(v(5) == 5e26, accuracy);
	BOOST_TEST(v(6) == 4e-16, accuracy);
}

BOOST_AUTO_TEST_CASE(TestVectorSerializerSave)
{
	Vector v(6);

	v(0) = 2.4;
	v(1) = 6.256;
	v(2) = 23.565;
	v(3) = 1.43;
	v(4) = -26.53e18;
	v(5) = 1.34e-9;
	
	std::filesystem::path testPath("FilesForTesting");									   // path to the test file
	testPath.append("testVectorSerializerSave.dat");

	VectorSerializer serializer;
	serializer.Save(testPath, v);

	Vector v1 = serializer.Load(testPath);

	std::filesystem::remove(testPath);

	BOOST_REQUIRE(v1.size() == static_cast<size_t>(6));

	//boost::algorithm::equal(v.begin(), v.end(), v1.begin(), v1.end());
	//BOOST_TEST(boost::algorithm::equal(v.begin(), v.end(), v1.begin(), v1.end()));
	/*for (size_t k = 0; k < 6; k++)
		BOOST_TEST(v(k) == v1(k), accuracy);*/
}

BOOST_AUTO_TEST_SUITE_END()

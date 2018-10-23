#include "stdafx.h"
#include "UsualMatrixSerializer.h"
#include "Filesystem.h"
#include "Logging.h"

UsualMatrix UsualMatrixSerializer::Load(const std::filesystem::path& path) const
{
	try
	{
		std::ifstream inputFile{ path.string() };
		int unsigned size1{ 0 }; // rows count
		int unsigned size2{ 0 }; // columns count

		inputFile >> size1 >> size2;

		UsualMatrix m(size1, size2);
		for (unsigned int i = 0; i < size1; i++)
			for (unsigned int j = 0; j < size2; j++)
				inputFile >> m(i, j);

		BoostLog(info, "Matrix " + std::to_string(size1) + "x" + std::to_string(size2) + " successfully loaded from file \"" +
			path.string() + "\"");
		return m;
	}
	catch (...) {
		std::string message = "Could not load matrix from file \"" + path.string() + "\"";
		BoostLog(error, message);
		throw message;
	}
}

void UsualMatrixSerializer::Save(const std::filesystem::path& path, const UsualMatrix& matrix) const
{
	try 
	{
		std::ofstream outputFile{ path.string() };

		outputFile << matrix.size1() << " " << matrix.size2() << std::endl;

		for (unsigned int i = 0; i < matrix.size1(); i++)
		{
			for (unsigned int j = 0; j < matrix.size2() - 1; j++)
				outputFile << matrix(i, j) << " ";
			outputFile << matrix(i, matrix.size2() - 1) << std::endl;
		}

		BoostLog(info, "Matrix " + std::to_string(matrix.size1()) + "x" + std::to_string(matrix.size2()) +
			                                                          " successfully saved to file \"" + path.string() + "\"");
	}
	catch (...) {
		std::string message = "Could not save matrix to file \"" + path.string() + "\"";
		BoostLog(error, message);
		throw message;
	}
} 
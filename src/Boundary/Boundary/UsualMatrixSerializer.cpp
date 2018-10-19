#include "stdafx.h"
#include "UsualMatrixSerializer.h"
#include "Filesystem.h"

UsualMatrix UsualMatrixSerializer::Load(const std::filesystem::path& path) const
{
	std::ifstream inputFile{ path.string() };
	int unsigned size1{0}; // rows count
	int unsigned size2{0}; // columns count

	inputFile >> size1 >> size2; 

	UsualMatrix m(size1, size2);
	for (unsigned int i = 0; i < size1; i++)
		for (unsigned int j = 0; j < size2; j++)
			inputFile >> m(i, j);
	return m;
}

void UsualMatrixSerializer::Save(const std::filesystem::path& path, const UsualMatrix& matrix) const
{
	std::ofstream outputFile{ path.string() };

	outputFile << matrix.size1() << " " << matrix.size2() << std::endl;

	for (unsigned int i = 0; i < matrix.size1(); i++)
	{
		for (unsigned int j = 0; j < matrix.size2() - 1; j++)
			outputFile << matrix(i, j) << " ";
		outputFile << matrix(i, matrix.size2() - 1) << std::endl;
	}
} 
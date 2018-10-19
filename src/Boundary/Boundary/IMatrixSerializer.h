#pragma once
#include "stdafx.h"

using MatrixElement = double;
//using Matrix = boost::numeric::ublas::matrix<MatrixElement>;

template<typename TMatrix>
struct IMatrixSerializer
{
public:
	virtual TMatrix Load(const std::filesystem::path& path) const = 0;
	virtual void Save(const std::filesystem::path& path, const TMatrix& matrix) const = 0;
};
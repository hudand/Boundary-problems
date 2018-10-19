#pragma once
#include "stdafx.h"
#include "IMatrixSerializer.h"

using UsualMatrix = boost::numeric::ublas::matrix<MatrixElement>;

class UsualMatrixSerializer :
	public IMatrixSerializer<UsualMatrix>
{
public:
	UsualMatrixSerializer() = default;
	~UsualMatrixSerializer() = default;
	UsualMatrix Load(const std::filesystem::path& path) const override;
	void Save(const std::filesystem::path& path, const UsualMatrix& matrix) const override;
};
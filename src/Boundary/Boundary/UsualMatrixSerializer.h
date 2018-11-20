#pragma once
#include "stdafx.h"
#include "IMatrixSerializer.h"
#include "MatrixTypes.h"


class UsualMatrixSerializer :
	public IMatrixSerializer<UsualMatrix>
{
public:
	UsualMatrixSerializer() = default;
	~UsualMatrixSerializer() = default;
	UsualMatrix Load(const std::filesystem::path& path) const override;
	void Save(const std::filesystem::path& path, const UsualMatrix& matrix) const override;
};
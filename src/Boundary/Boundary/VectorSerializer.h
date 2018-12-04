#pragma once
#include "stdafx.h"
#include "MatrixTypes.h"


class VectorSerializer
{
public:
	VectorSerializer() = default;
	~VectorSerializer() = default;
	Vector Load(const std::filesystem::path& path) const;
	void Save(const std::filesystem::path& path, const Vector& vector) const;
};


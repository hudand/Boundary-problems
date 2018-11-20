#pragma once
#include "stdafx.h"
#include "ILinearSolver.h"
#include "MatrixTypes.h"

class GaussSolver :
	public ILinearSolver<UsualMatrix>
{
public:
	GaussSolver() = default;
	~GaussSolver() = default;
	Vector Solve(UsualMatrix& a, Vector& b) override;
};


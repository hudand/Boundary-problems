#pragma once
#include "stdafx.h"
#include "MatrixTypes.h"


template<typename TMatrix>
struct ILinearSolver
{
public:
	virtual Vector Solve(TMatrix& a, Vector& b) = 0;
};
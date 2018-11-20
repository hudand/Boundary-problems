#include "stdafx.h"
#include "GaussSolver.h"
#include "MatrixTypes.h"


Vector GaussSolver::Solve(UsualMatrix& a, Vector& b)
{
	const unsigned n = a.size1();

	// forward elimination
	for (unsigned j = 0; j < n - 1; ++j) {
		const double pivot = a(j, j);
		if (pivot == 0)
			throw "Gauss: zero on the main diagonal";

		for (unsigned i = j + 1; i < n; ++i) {
			const double mult = a(i, j) / pivot;
			for (unsigned k = j; k < n; ++k)
				a(i, k) -= a(j, k) * mult;
			b[i] -= b[j] * mult;
		}
	}

	// back-substitution
	using namespace boost::numeric::ublas;
	return solve(a, b, upper_tag());
}


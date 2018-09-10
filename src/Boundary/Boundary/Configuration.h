#pragma once

enum class Regularization {
	Noregularized, Partial, Usual, Full
};

enum class IterativeMethod {
	Newton, Kalitkin
};

enum class Approximation {
	Spline3, Spline5, FourierTrigonometricSeries, ChebyshevPolinoms, Lagrange, Newton, TrigonometricLagrange, LeastSquare
};

enum class MethodOrder {
	Second, Third, Hybrid
};

struct Configuration
{
	Configuration();
	~Configuration();

	std::string equation; // differential equation
	std::string leftBound; // left boundary condition
	std::string rightBound; // right boundary condition
	std::string initialApproximation; // initial approximation
	bool isInitialApproximationFromFile; // initial approximation from file?
	bool isPeriodicProblem; // periodic problem?
	
	Regularization regularization; // type of regularization
	double alpha; // regularization parameter
	double alpha2; // regularization parameter

	bool isUniformGrid; // grid uniformity
	unsigned int nodesCount; // number of grid nodes
	unsigned int patternNodesCount; // number of pattern nodes

	IterativeMethod nonlinearMethod; // method of solving a system of nonlinear algebraic equations
	double accuracy; // accuracy of the grid solution
	MethodOrder methodOrder; // order of method (2 or 3 or hybrid)
	
	Approximation approximation; // type of grid solution approximation

	unsigned int iterationMax; // maximum number of iterations
	double normMax; // maximum norm value (after method was sold out)

};


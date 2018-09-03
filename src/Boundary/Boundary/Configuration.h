#pragma once

enum class Regularization {
	Noreg, Partial, Usual, Full
};

enum class IterMethod {
	Newton, Kalitkin
};

enum class Approximation {
	Spline3, Spline5, FourierTrigSeries, ChebyshevPolinoms, Lagrange, Newton, TrigLagrange, LeastSquare
};

enum class MethodOrder {
	Second, Third, Hybrid
};

struct Configuration
{
	Configuration();
	~Configuration();

	std::string equation; // differential equation
	std::string lbound; // left boundary condition
	std::string rbound; // right boundary condition
	std::string initApprox; // initial approximation
	bool isInitApproxFromFile; // initial approximation from file?
	
	Regularization regul; // type of regularization
	double alpha; // regularization parameter
	double alpha2; // regularization parameter

	bool isUniformGrid; // grid uniformity
	int nodesCount; // number of grid nodes
	int patternNodesCount; // number of pattern nodes

	IterMethod nonlinMethod; // method of solving a system of nonlinear algebraic equations
	double accuracy; // accuracy of the grid solution
	MethodOrder methodOrder; // order of method (2 or 3 or hybrid)
	
	Approximation approx; // type of grid solution approximation

	int iterationMax; // maximum number of iterations
	double normMax; // maximum norm value (after method was sold out)

};


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
	std::string equation = "y''(x) + 0.2 * y'(x) + (y(x))^3 + y(x) = 50 * cos(x)"; // differential equation
	std::string leftBound = "y(0) = y(2 * pi)";                                    // left boundary condition
	std::string rightBound = "y'(0) = y'(2 * pi)";                                 // right boundary condition
	std::string initialApproximation = "sin(x) + cos(x)";                          // initial approximation
	bool isInitialApproximationFromFile = false;                                   // initial approximation from file?
	bool isPeriodicProblem = true;                                                 // periodic problem?
	
	Regularization regularization = Regularization::Usual;                         // type of regularization
	double alpha = 1e-5;                                                           // regularization parameter
	double alpha2 = 1e-8;                                                          // regularization parameter

	bool isUniformGrid = true;                                                     // grid uniformity
	unsigned int nodesCount = 384;                                                 // number of grid nodes
	unsigned int patternNodesCount = 21;                                           // number of pattern nodes

	IterativeMethod nonlinearMethod = IterativeMethod::Newton;                     // method of solving a system of 
	                                                                               // nonlinear algebraic equations

	double accuracy = 1e-13;													   // accuracy of the grid solution
	MethodOrder methodOrder = MethodOrder::Second;								   // order of method (2 or 3 or hybrid)
	
	Approximation approximation = Approximation::Spline3;						   // type of grid solution approximation

	unsigned int iterationMax = 500;											   // maximum number of iterations
	double normMax = 1e100;														   // maximum norm value (after method was sold out)

};


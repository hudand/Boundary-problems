#include "stdafx.h"
#include "ConsoleUserInterface.h"
#include "UsualMatrixSerializer.h"
#include "VectorSerializer.h"
#include "GaussSolver.h"

ConsoleUserInterface::ConsoleUserInterface(const UsualMatrixSerializer &pSerializer) : matrixSerializer{ pSerializer }
{
}

void ConsoleUserInterface::Start() const
{
	std::string command;
	while (true) {
		std::cout << "Input command>";
		std::getline(std::cin, command);
		if (command == "exit")
			break;
		AnalyzeCommand(command);
	}
}


void ConsoleUserInterface::ShowCommandList() const
{
	std::cout << "Command list:" << std::endl
	<< "solve-linear \t\t Solving the system of linear equations." << std::endl << std::endl;
}


void ConsoleUserInterface::ShowCommandHelp(const std::string &command) const
{
	if (command.find("solve-linear") != std::string::npos)
		std::cout << "Solving a system of linear equations." << std::endl << std::endl
		<< "solve-linear A B X" << std::endl
		<< "where" << std::endl
		<< "A is input matrix (left-hand) file name" << std::endl
		<< "B is input vector (right-hand) file name" << std::endl
		<< "X is output vector (solution) file name" << std::endl << std::endl;
}


void ConsoleUserInterface::SolveLinearRun(std::stringstream &commandStream) const
{
	std::string fileForMatrixA;
	std::string fileForVectorB;
	std::string fileForVectorX;

	commandStream >> fileForMatrixA >> fileForVectorB >> fileForVectorX;

	//UsualMatrixSerializer matrixSerializer;
	VectorSerializer vectorSerializer;
	
	UsualMatrix A;
	Vector B, X;

	A = matrixSerializer.Load(fileForMatrixA);
	B = vectorSerializer.Load(fileForVectorB);

	GaussSolver solver;
	X = solver.Solve(A, B);

	vectorSerializer.Save(fileForVectorX, X);

	std::cout << "The solution saved to file " << fileForVectorX << std::endl;
}


void ConsoleUserInterface::AnalyzeCommand(std::string &command) const
{
	const size_t position{ command.find("/?") };

	if (position != std::string::npos)
		if (position == 0)
			ShowCommandList();
		else
			ShowCommandHelp(command);
	else {

		std::stringstream commandStream{ command };
		std::string commandType;
		commandStream >> commandType;
		
		if (commandType == "solve-linear")
			SolveLinearRun(commandStream);

	}
};

#pragma once
#include "stdafx.h"
#include "UsualMatrixSerializer.h"

class ConsoleUserInterface
{
public:
	ConsoleUserInterface() = default;
	ConsoleUserInterface(const UsualMatrixSerializer &pSerializer);
	~ConsoleUserInterface() = default;
	void Start() const;
	UsualMatrixSerializer matrixSerializer;
private:
	//UsualMatrixSerializer matrixSerializer;
	void ShowCommandList() const;
	void AnalyzeCommand(std::string &command) const;
	void ShowCommandHelp(const std::string &command) const;
	void SolveLinearRun(std::stringstream &commandStream) const;
};


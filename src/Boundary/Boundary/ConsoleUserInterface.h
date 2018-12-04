#pragma once
#include "stdafx.h"

class ConsoleUserInterface
{
public:
	ConsoleUserInterface() = default;
	~ConsoleUserInterface() = default;
	void Start() const;
private:
	void ShowCommandList() const;
	void AnalyzeCommand(std::string &command) const;
	void ShowCommandHelp(const std::string &command) const;
	void SolveLinearRun(std::stringstream &commandStream) const;
};


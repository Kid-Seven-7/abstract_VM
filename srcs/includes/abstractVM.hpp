#ifndef __ABSTRACTVM_HPP__
#define __ABSTRACTVM_HPP__

/* Includes
#include <>
#include ""
*/
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "IOperand.class.hpp"
#include "int8.class.hpp"

//Function declararions
	//Voids
	void mainLoop();
	void printLine();
	void newLine(std::vector<std::string> & inst);
	void instExec(std::vector<std::string> insts);

	//std::vectors
	std::vector<std::string> dump();

	//std::strings
	//ints
	//doubles
	//bools

#endif

#ifndef __ABSTRACTVM_HPP__
#define __ABSTRACTVM_HPP__

//Error defines
#define UNKNOWN_ERROR -1
#define VALID_INST 0
#define INVALID_INST 1
#define INVALID_DATATYPE 2
#define INVALID_DATAVALUE 3
#define INVALID_FORMAT 4
#define VALUE_EXCEEDS_LIMIT 5
#define NO_DATA_TYPE 6

//Max defines
#define MAX_INT8 std::numeric_limits<signed char>::max()
#define MAX_INT16 std::numeric_limits<short>::max()
#define MAX_INT32 std::numeric_limits<int>::max()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MAX_DOUBLE std::numeric_limits<double>::max()

//Min defines
#define MIN_INT8 std::numeric_limits<signed char>::min()
#define MIN_INT16 std::numeric_limits<short>::min()
#define MIN_INT32 std::numeric_limits<int>::min()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MIN_DOUBLE std::numeric_limits<double>::min()

#include <cstdlib>
#include <regex>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "IOperand.class.hpp"
#include "int8.class.hpp"


//Function declararions
	//Voids
	void exitProg();
	void mainLoop();
	void printLine();
	void validate(std::string arr[5]);
	void newLine(std::vector<std::string> & inst);
	void instExec(std::vector<std::string> insts);
	void errorHandler(std::string arr[5], int parseCode);

	//bools
	bool validDataType(const char *dataType);
	bool validInstNoData(const char *inst, const char *dataType);
	bool validInstData(const char *inst, const char *dataType);
	bool validDataVal(const char *dataType, const char *dataVal);

	//std::vectors
	std::vector<std::string> dump();

	//std::strings
	//ints
	//doubles
#endif

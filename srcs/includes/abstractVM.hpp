#ifndef _ABST_HPP_
#define _ABST_HPP_

enum eOperand
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

//standard lib includes
		#include <cmath>
    #include <regex>
		#include <string>
		#include <vector>
    #include <limits>
		#include <fstream>
		#include <sstream>
		#include <cstdlib>
		#include <iostream>
		#include <exception>

//Custom hedaers files
// #include "../includes/Int8.hpp"
// #include "../includes/Int16.hpp"
    #include "../includes/exceptions.hpp"
		#include "../includes/IOperand.hpp"
    #include "../includes/OperandFactory.hpp"

// #defines
    //Display
    #define INFO 0
    #define WARNING 1
    #define ERROR 2

    //Errorlog
    #define INVALID_INSTRUCTION_PASSED 1
    #define MULTIPLE_INSTRUCTIONS_PASSED 2
    #define MULTIPLE_DATA_TYPES_PASSED 3
    #define EMPTY_STACK 4
    #define INVALID_FLAG_PASSED 5
    #define INVALID_DATA_VALUE_FORMAT 6
    #define INVALID_DATA_VALUE 7
		#define OUT_OF_RANGE 8
		#define ASSERTED_VALUE_NOT_EQUAL 9
		#define NEED_TWO_VALUES 10
		#define DIV_BY_ZERO 11
		#define EMPTY_PEREN 12
    #define NO_DATA_TYPE 13

//Function declarations
    //ints
    int GetErrorCount();

    //bools
    bool isVerbose();
    bool Semi();
    bool Error();
    bool Multi();
    bool exited();
		bool getError();

    //voids
    void setSemi();
    void setMulti();
		void setError();
    void exitFound();
		void showError();
    void resetLine();
    void setVerbose();
    void resetErrors();
    void dumpErrorLog();
    void Log(int error, std::string command);
    void PrintLine(std::string message, int status);
		void execute(std::vector<std::string> &InstructionSet);
    void parse(std::string& command,	std::vector<std::string>& InstructionSet);

		//enums
		eOperand getType(std::string command);

		//std::strings
		std::string strip(std::string &command);

#endif

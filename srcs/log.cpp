#include "includes/abstractVM.hpp"

static std::vector<std::string> ErrorLog;
static int ErrorCount;
static bool hasExit = false;
static bool hasNoSemi = true;
static bool hasVerbose = false;
static bool showAllError = false;
static bool multiFile = false;

void resetErrors(){
	ErrorLog.clear();
	ErrorCount = 0;
	hasExit = false;
	if (!multiFile){ //Keeps current status in multi file format
		hasVerbose = false;
		hasNoSemi = true;
		showAllError = false;
	}
}

bool Semi(){ return hasNoSemi;} //Return semi colon status
bool Multi(){ return multiFile;} //Set multi file format
void exitFound(){ hasExit = true;} //Set if exit command is found
void setSemi(){ hasNoSemi = false;} //Sets semi colon status to false
void setMulti(){ multiFile = true; } //Sets multi file format status to true
bool isVerbose(){ return hasVerbose;} //Returns Verbose status
void showError(){ showAllError = true;} //Sets show all errors flag
bool getError(){ return showAllError;} //Returns show all errors status
void setVerbose(){ hasVerbose = true;} //Sets Verbose status to true
int GetErrorCount(){ return (ErrorCount);} // Returns number of errors found

void Log(int error, std::string command){
	std::string err;
	int Throw = 0;

	//Error Logger
	switch (error)	{
	case INVALID_INSTRUCTION_PASSED:
		err = "Line " + command;
		err += " :\033[1;31m Invalid instruction passed\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case MULTIPLE_INSTRUCTIONS_PASSED:
		err = "Line " + command;
		err += " :\033[1;31m Mutiple instructions passed\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case MULTIPLE_DATA_TYPES_PASSED:
		err = "Line " + command;
		err += " :\033[1;31m Mutiple Data Types passed\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case EMPTY_STACK:
		err = "Line " + command;
		err += " :\033[1;31m Cannot perform this operation on empty stack\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case INVALID_FLAG_PASSED:
		err = "Command line :\033[1;31m Invalid flag passed\033[0m\n";
		err += command;
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case INVALID_DATA_VALUE_FORMAT:
		err = "Line " + command;
		err += " :\033[1;31m Invalid data value format\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case INVALID_DATA_VALUE:
		err = "Line " + command;
		err += " :\033[1;31m Invalid data value\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case OUT_OF_RANGE:
		err = "Line " + command;
		err += " :\033[1;31m Value is out of range\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case ASSERTED_VALUE_NOT_EQUAL:
		err = "Line " + command;
		err += " :\033[1;31m Asserted value is not equal to stack\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case NEED_TWO_VALUES:
		err = "Line " + command;
		err += " :\033[1;31m A minimun of two stack values is needed for this operation\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case DIV_BY_ZERO:
		err = "Line " + command;
		err += " :\033[1;31m Cannot divide by zero\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case EMPTY_PEREN:
		err = "Line " + command;
		err += " :\033[1;31m Empty perenthesis found\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	case NO_DATA_TYPE:
		err = "Line " + command;
		err += " :\033[1;31m Invalid data type passed\033[0m\n";
		ErrorLog.push_back(err);
		ErrorCount++;
		break;
	default:
		for (size_t i = 0; i < ErrorLog.size(); ++i){
			err = ErrorLog[i];
			try{
				//Checks what logic error was logged
				Throw += (err.find("Invalid instruction passed") != std::string::npos)?1:0;
				Throw += (err.find("Mutiple instructions passed") != std::string::npos)?1:0;
				Throw += (err.find("Mutiple Data Types passed") != std::string::npos)?1:0;
				Throw += (err.find("Cannot perform this operation on empty stack") != std::string::npos)?1:0;
				Throw += (err.find("Invalid flag passed") != std::string::npos)?1:0;
				Throw += (err.find("Invalid data value format") != std::string::npos)?1:0;
				Throw += (err.find("Invalid data value") != std::string::npos)?1:0;
				Throw += (err.find("Value is out of range") != std::string::npos)?1:0;
				Throw += (err.find("Asserted value is not equal to stack") != std::string::npos)?1:0;
				Throw += (err.find("A minimun of two stack values is needed for this operation") != std::string::npos)?1:0;
				Throw += (err.find("Cannot divide by zero") != std::string::npos)?1:0;
				Throw += (err.find("Empty perenthesis found") != std::string::npos)?1:0;
				Throw += (err.find("invalid data type passed") != std::string::npos)?1:0;
				//If any throw it
				if (Throw != 0 )
					throw CustomExceptions::Logic();
			}
			catch (std::exception & e)
			{
				//Catch thrown exception and print out error 'err'
				std::cout << e.what() << '\n' << err;
				exit(1);
			}
		}
	}
}

void dumpErrorLog(){
	std::string err = "";
	std::string failed = "Failed to compile\n"
		+ std::to_string(ErrorCount)
		+ " Errors found";
		int Throw = 0;
	if (!hasExit)
		ErrorCount++;

	if (ErrorCount == 0){
		PrintLine("Complied successfully", INFO);
	}
	else	{
		PrintLine(failed, ERROR);
		if (!hasExit){
			std::cout << "No exit instruction found" << '\n';
		}
		for (size_t i = 0; i < ErrorLog.size(); ++i){
			err = ErrorLog[i];
			try{
				//Checks what syntax error was logged
				Throw += (err.find("Invalid instruction passed") != std::string::npos)?1:0;
				Throw += (err.find("Mutiple instructions passed") != std::string::npos)?1:0;
				Throw += (err.find("Mutiple Data Types passed") != std::string::npos)?1:0;
				Throw += (err.find("Cannot perform this operation on empty stack") != std::string::npos)?1:0;
				Throw += (err.find("Invalid flag passed") != std::string::npos)?1:0;
				Throw += (err.find("Invalid data value format") != std::string::npos)?1:0;
				Throw += (err.find("Invalid data value") != std::string::npos)?1:0;
				Throw += (err.find("Value is out of range") != std::string::npos)?1:0;
				Throw += (err.find("Asserted value is not equal to stack") != std::string::npos)?1:0;
				Throw += (err.find("A minimun of two stack values is needed for this operation") != std::string::npos)?1:0;
				Throw += (err.find("Cannot divide by zero") != std::string::npos)?1:0;
				Throw += (err.find("Empty perenthesis found") != std::string::npos)?1:0;
				Throw += (err.find("invalid data type passed") != std::string::npos)?1:0;
				//If any throw it
				if (Throw != 0 )
					throw CustomExceptions::Syntax();
			}
			catch (std::exception & e)
			{
				//Catch thrown exception and print out error 'err'
				std::cout << e.what() << '\n' << err	<< std::endl;
				if (ErrorCount > 2 && getError()){
					PrintLine("Other errors", ERROR);
					for (size_t i = 1; i < ErrorLog.size(); ++i) {
						std::cout << ErrorLog[i] << '\n';
					}
				}
				resetLine();
				return;
			}
		}

	}
	ErrorLog.clear();
}

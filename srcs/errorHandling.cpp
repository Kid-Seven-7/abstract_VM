#include "includes/abstractVM.hpp"

void errorHandler(std::string arr[5], int parseCode){
	if (parseCode != 0){
		const char *lineNo = arr[1].c_str();
		const char *inst = arr[2].c_str();
		const char *dataType = arr[3].c_str();
		const char *dataVal = arr[4].c_str();

		switch (parseCode){
			case INVALID_INST:
				std::cout
				<< "Line #"
				<< lineNo
				<< " Invalid instruction : "
				<< " \033[1;31m"
				<< inst
				<< "\033[0m "
				<< dataType
				<< " "
				<< dataVal
				<< "\n";
				exit(1);
				break;

			case INVALID_DATATYPE:
				std::cout
				<< "Line #"
				<< lineNo
				<< " Invalid data type : "
				<< " "
				<< inst
				<< " "
				<<"\033[1;31m"
				<< dataType
				<< "\033[0m "
				<< " "
				<< dataVal
				<< '\n';
				exit(1);
				break;

			case INVALID_DATAVALUE:
				std::cout
				<< "Line #"
				<< lineNo
				<< " Invalid data value : "
				<< " "
				<< inst
				<< " "
				<< dataType
				<< " "
				<<"\033[1;31m"
				<< dataVal
				<< "\033[0m "
				<< '\n';
				exit(1);
				break;

			case INVALID_FORMAT:
				std::cout
				<< "Invalid format passed "
				<< '\n';
				exit(1);
				break;

			case VALUE_EXCEEDS_LIMIT:
				std::cout
				<< "Line #"
				<< lineNo
				<< " \033[1;31m"
				<< dataVal
				<< "\033[0m exceeds \033[1;33m"
				<< dataType
				<< "\033[0m limit";
				exit(1);
				break;

			case NO_DATA_TYPE:
				std::cout
				<< "Line #"
				<< lineNo
				<< " \033[1;31m"
				<< inst
				<< "\033[0m"
				<< " requires a data type and data value\n";
				exit(1);
				break;

			default:
				std::cout
				<< "\033[1;31mAn unknown error occurred\033[0m"
				<< lineNo
				<< '\n'
				<< inst
				<< " "
				<< dataType
				<< " "
				<< dataVal
				<< '\n';
				exit(1);
				break;
		}
	}
}

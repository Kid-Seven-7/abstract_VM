#include "includes/abstractVM.hpp"

/*
	Adds 50 '='
	- purely for astheic purposes
*/
void printLine(){
	for (int i = 0; i < 16; ++i){
		std::cout << "\033[1;31m=\033[0m";
		std::cout << "\033[1;33m=\033[0m";
		std::cout << "\033[1;32m=\033[0m";
	}
	std::cout << '\n';
}

void exitProg(){
	printLine();
	std::cout << "Exiting Abstract VM" << '\n';
	printLine();
	exit(0);
}

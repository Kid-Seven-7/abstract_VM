#include "includes/abstractVM.hpp"

/*
	Adds 50 '='
	- purely for astheic purposes
*/
void printLine(){
	for (int i = 0; i < 50; ++i)
		std::cout << "=";
	std::cout << '\n';
}

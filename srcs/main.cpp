#include "includes/abstractVM.hpp"

/*
	Just a figure head
	- no actual 'code' here
	- just points to the logic
*/
int main (){
	printLine();
	std::cout << "Abstract VM" << '\n';
	printLine();

	mainLoop();

	return (0);
}

#include "includes/abstractVM.hpp"

/*
	Just a figure head
	- no actual 'code' here
	- just points to the logic
*/
int main (){
	system("clear");
	printLine();
	for (int i = 0; i < 20; ++i)
		std::cout << " ";
	std::cout << "\033[5mAbstract VM\033[0m" << '\n';
	printLine();

	mainLoop();

	return (0);
}

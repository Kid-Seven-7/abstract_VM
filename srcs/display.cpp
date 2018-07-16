#include "includes/abstractVM.hpp"

void DrawLine(){
	for (int i = 0; i < 75; ++i)
		std::cout << "=";
	std::cout << '\n';
}

void writeMessage(std::string message, int status){
	switch (status) {
		case INFO:
			std::cout << "\033[1;32m" << message << "\033[0m\n";
			break;
		case WARNING:
			std::cout << "\033[1;33m" << message << "\033[0m\n";
			break;
		case ERROR:
			std::cout << "\033[1;31m" << message << "\033[0m\n";
			break;
	}
}

void PrintLine(std::string message, int status){
	DrawLine();
	writeMessage(message, status);
	DrawLine();
}

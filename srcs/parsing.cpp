#include "includes/abstractVM.hpp"

/*
	Keeps track of what line the instruction is on
	- For bonus purposes
*/
void newLine(std::vector<std::string> & inst){
	static size_t line = 0;

	std::stringstream ss;

	ss << "line " <<line;
	std::string sLine = ss.str();
	inst.push_back(sLine);
	line++;
}

/*
	Converts the raw vector into a parsed vector
	- with all instructions and values separated by space
	(easier to handle)
*/
std::vector<std::string> dump(std::vector<std::string> & inst){
	std::vector<std::string> parsed;
	std::string temp;
	for (size_t i = 0; i < inst.size(); ++i){
		if (inst[i][0] == 'l'){
			parsed.push_back(temp);
			temp = "";
		}
		temp += inst[i];
		temp += " ";
	}
	// for (size_t i = 0; i < parsed.size(); ++i)
		// std::cout <<"parsed "<<i<<" is "<< parsed[i] << '\n';
	return (parsed);
}

/*
	Initial parsing of raw instruction set
	- For cleaner looking code
*/
void initParse(std::vector<std::string> & inst, std::string command){
	std::string temp;
	for (size_t i = 0; i <= command.length(); ++i){
		if (command[i] == ' ' || command[i] == '(' || command[i] == ')' || i == command.length()){
			inst.push_back(temp);
			temp = "";
			i++;
			if (command[i] == '(')
			i++;
		}
		if (command[i] == ';')
			break;
		temp += command[i];
	}
}

/*
	The main logic of my program
	- makes the main look cleaner
*/
void mainLoop(){
	std::string command;
	std::vector<std::string> inst;
	int breaker = 1;
	while (breaker){
		getline(std::cin, command);

		newLine(inst);

		initParse(inst, command);

		for (size_t i = 0; i < inst.size(); ++i){
			if (inst[i] == "exit"){
				inst = dump(inst);
				instExec(inst);
			}
		}
	}
}

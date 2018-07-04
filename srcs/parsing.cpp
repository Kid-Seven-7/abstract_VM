#include "includes/abstractVM.hpp"

/*
	Keeps track of what line the instruction is on
	- For bonus purposes
*/
int newLine(std::vector<std::string> & inst, int reset){
	static int line = 0;

	if (reset == 0){
		std::stringstream ss;
		ss
		<< "line "
		<<line;
		std::string sLine = ss.str();
		inst.push_back(sLine);
		line++;
	}else{
		line = 0;
	}
	return (line);
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
	int words = 1;
	int peren = 0;

	for (size_t i = 0; i <= command.length(); ++i){
		if (command[i] == ';')
			while (++i <= command.length());
		words += (command[i] == ' ') ? 1 : 0 ;
		peren += (command[i] == '(') ? 1 : 0 ;
		peren += (command[i] == ')') ? -1 : 0 ;
		if (peren < 0){
			std::cout
			<< "\033[1;31mFailed to compile\033[0m\nIntruction is not valid\n"
			<< "Cannot close perenthesis before opening them\n\033[1;33m"
			<< command
			<< "\033[0m"
			<< '\n';
			exit (1);
		}
	}

	if(words == 1 || (words == 2 && peren == 0)){
		for (size_t i = 0; i <= command.length(); ++i){
			if (command[i] == ';')
				while (++i <= command.length());
			if (command[i] == ' ' || command[i] == '(' || command[i] == ')' || i == command.length()){
				inst.push_back(temp);
				temp = "";
				i++;
				i += (command[i] == '(') ? 1 : 0 ;
			}
			temp += command[i];
		}
	}
	else{
		std::cout
		<< "\033[1;31mFailed to compile\033[0m\nIntruction is not valid\n\033[1;33m"
		<< command
		<< "\033[0m"
		<< '\n';
		exit (1);
	}
}

std::string removeComments(std::string command){
	std::string temp = "";
	for (size_t i = 0; i < command.length(); ++i) {
		if (command[i] == ';'){
			temp = std::regex_replace(temp, std::regex("^ +| +$|( ) +"), "$1");
			temp = regex_replace(temp, std::regex(" +"), " ");
			return (temp);
		}
		temp += command[i];
	}
	temp = std::regex_replace(temp, std::regex("^ +| +$|( ) +"), "$1");
	temp = regex_replace(temp, std::regex(" +"), " ");
	return (temp);
}

/*
	The main logic of my program
	- makes the main look cleaner
*/
void mainLoop(){
	std::string command;
	std::vector<std::string> inst;
	int breaker = 1;
	int line = 0;
	while (breaker){
		getline(std::cin, command);

		command = std::regex_replace(command, std::regex("^ +| +$|( ) +"), "$1");
		command = regex_replace(command, std::regex(" +"), " ");

		line = newLine(inst, 0);

		command = removeComments(command);

		initParse(inst, command);

		for (size_t i = 0; i < inst.size(); ++i){
			if (inst[i] == "exit"){
				inst = dump(inst);
				instExec(inst);
				newLine(inst, 1);
				inst.clear();
			}
		}
	}
}

#include "includes/abstractVM.hpp"

/*
	Keeps track of what line the instruction is on
	- For bonus purposes
*/
void newLine(std::vector<std::string> & inst, int reset){
	static size_t line = 0;

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
	int line = 0;
	for (size_t i = 0; i <= command.length(); ++i){
		if (command[i] == ' ')
			words++;
		if (command[i] == '(' || command[i] == ')')
			peren++;
		if (command[i] == '\n')
			line++;
	}

	if(words == 1 || (words == 2 && peren == 2)){
		for (size_t i = 0; i <= command.length(); ++i){
			if (command[i] == ' ' || command[i] == '(' || command[i] == ')' || i == command.length()){
				inst.push_back(temp);
				temp = "";
				i++;
				if (command[i] == '(')
				i++;
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

/*
	Removes leading whitespaces from the command
*/
std::string trimComm(std::string command){
	std::string temp = "";
	int start = 0;
	for (size_t i = 0; i < command.length(); ++i){
		if (start == 0){
			while(command[++i] == ' ')
				start++;
		}
		temp += command[i];
	}
	return (temp);
}

/*
	The main logic of my program
	- makes the main look cleaner
*/
void mainLoop(){
	std::string command;
	std::vector<std::string> inst;
	// std::vector<std::vector<std::string> > allInst;
	int breaker = 1;
	while (breaker){
		getline(std::cin, command);
		printf("comm before trim |%s|\n", command.c_str());
		if (command[0] == ' ')
			command = trimComm(command);
			printf("comm after trim |%s|\n", command.c_str());

		newLine(inst, 0);

		initParse(inst, command);

		for (size_t i = 0; i < inst.size(); ++i){
			if (inst[i] == "exit"){
				inst = dump(inst);
				instExec(inst);
				newLine(inst, 1);
				inst.clear();
			}
			if (inst[i] == ";;"){
				printLine();
				std::cout << "Exiting Abstract VM" << '\n';
				printLine();
				exit(0);
			}
		}
	}
}

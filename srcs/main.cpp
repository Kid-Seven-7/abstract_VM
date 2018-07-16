#include "includes/abstractVM.hpp"

//Handles stdin 😫 why no use  file 😫
void StandardIn(std::vector<std::string> &InstructionSet){
	std::string command;
	std::string mode = "abstractVM stdin ";
	mode += (isVerbose()) ? ", Verbose mode " : "" ;
	mode += (getError()) ? ", show all errors mode " : "" ;
	PrintLine(mode, INFO);
	while (true){
		std::getline(std::cin, command);

		if (command.find("exit") != std::string::npos)
			exitFound();

		if (command.find(";;") != std::string::npos)
			break;

		command = strip(command);
		parse(command, InstructionSet);
	}
}

//Check the files validity
bool testfile(char *file){
	std::ifstream infile(file);
	std::string sFile(file);

	if (infile.good()){
		if (sFile.find(".avm") != std::string::npos)
			return true;

		PrintLine(sFile + " is not a valid file", ERROR);
		return false;
	}

	std::string temp(file);
	PrintLine(temp + " not found", ERROR);
	return false;
}

//Reads file one line at a time
void Readfile(char *file, std::vector<std::string> &InstructionSet){
	std::string line;
	std::string mode;

	if (testfile(file)){
		mode += (isVerbose()) ? " in Verbose mode" : "";
		mode += (getError()) ? " in show all errors mode" : "";

		PrintLine(std::string(file) + mode, INFO);
		std::ifstream infile(file);
		while (std::getline(infile, line)){
			if (line.find("exit") != std::string::npos)
				exitFound();

			parse(line, InstructionSet);
		}
	}

}

int main(int ac, char **av){
	std::vector<std::string> InstructionSet;
	std::string flags;
	int files = 0;
	bool useStdIn = false;
	resetLine();

	//Validates file
	for (int i = 1; i < ac; ++i){
		flags = std::string(av[i]);
		if (flags[0] == '-'){
			if (flags.find('v') != std::string::npos)
				setVerbose();

			if (flags.find('e') != std::string::npos)
				showError();

			if (!(isVerbose() || getError()))
				Log(INVALID_FLAG_PASSED, flags);

		}
		files += (flags.find(".avm") != std::string::npos) ? 1 : 0;
	}

	//Sets multi file format
	if (files > 1)
		setMulti();

	if ((ac == 1)
	||(ac == 2 && (isVerbose() || getError()))){
		useStdIn = true;
	}

	//Handles file input or stdin with flags
	if (useStdIn){
		StandardIn(InstructionSet);
		dumpErrorLog();
		if (GetErrorCount() == 0)
			execute(InstructionSet);
	}
	else
		for (int i = 1; i < ac; ++i){
			if (av[i][0] == '-')
				continue;
			Readfile(av[i], InstructionSet);
			dumpErrorLog();

			if (GetErrorCount() == 0)
				execute(InstructionSet);
		}

	return (0);
}

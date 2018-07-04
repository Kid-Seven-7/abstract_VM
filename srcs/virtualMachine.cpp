#include "includes/abstractVM.hpp"

void explodeInst(std::string inst){
	std::string arr[5];
	int i = 0;

	std::stringstream ss;
	ss << inst;

	while(ss.good() && i < 5){
		ss >> arr[i++];
		if (i > 5)
			errorHandler(arr, INVALID_FORMAT);
	}

	if (arr[0] != "")
		validate(arr);
}

void instExec(std::vector<std::string> insts){
	static int set = 0;
	printLine();
	std::cout
	<< "Instruction set "
	<< set
	<<" execution"
	<< '\n';
	printLine();
	for (size_t i = 0; i < insts.size(); ++i){
		explodeInst(insts[i]);
	}
	std::cout
	<< "Instruction set "
	<< set
	<<" completed"
	<< '\n';
	printLine();
	set++;
}

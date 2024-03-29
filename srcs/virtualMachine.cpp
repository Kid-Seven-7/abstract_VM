#include "includes/abstractVM.hpp"

void explodeInst(std::string inst, std::vector<IOperand> & theStack){
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

	brain(arr, theStack);

	// return (arr);
}

void instExec(std::vector<std::string> insts){
	std::vector<IOperand> theStack;
	std::string arr[5];
	static int set = 0;

	printLine();
	std::cout
	<< "Instruction set "
	<< set
	<<" execution"
	<< '\n';
	printLine();

	size_t size = insts.size();
	for (size_t i = 1; i < size; ++i){
		explodeInst(insts[i], theStack);
	}


	printLine();
	std::cout
	<< "Instruction set "
	<< set
	<<" completed"
	<< '\n';
	printLine();
	set++;
}

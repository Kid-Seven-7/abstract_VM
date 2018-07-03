#include "includes/abstractVM.hpp"

bool validate(std::string arr){
	if (arr[2] == "push"){
		if (arr[3].length > 4){
			if (arr[4] >= 1){
				return (true)
			}
		}
	}else if (arr[2] == "pop"){

	}
	return (false);
}

void explodeInst(std::string inst){
	std::string arr[5];
	int i = 0;

	std::stringstream ss;
	ss << inst;

	while(ss.good())
		ss >> arr[i++];

	for (int i = 0; i < 5; ++i){
		if (arr[i].length() > 0)
			std::cout << arr[i] << '\n';
	}

	if (validate(arr));

}

void instExec(std::vector<std::string> insts){
	for (size_t i = 0; i < insts.size(); ++i){
		explodeInst(insts[i]);
	}
}

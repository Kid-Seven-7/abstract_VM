#include "includes/abstractVM.hpp"

eOperand Type;

std::string getValue(std::string command){
	size_t start;
	std::string val = "";
	start = ((command.find('(')));

	while (command[++start] != ')')
		val += command[start];
	return (val);
}

eOperand getType(std::string command){
	if (command.find("int8")!=std::string::npos)
			return (Int8);
	if (command.find("int16")!=std::string::npos)
			return (Int16);
	if (command.find("int32")!=std::string::npos)
		return (Int32);
	if (command.find("float")!=std::string::npos)
		return (Float);
	else
		return (Double);
}

void checkFlow(eOperand Type, std::string val, std::string command){
	double min;
	double max;
	double base = stod(val);

	switch (Type) {
		case 0:
			//int8;
			min = std::numeric_limits<int8_t>::min();
			max = std::numeric_limits<int8_t>::max();
			if (base >= min && base <= max)
				return;
			else{
				Log(OUT_OF_RANGE, command);
				Log(0, "");
			}
			break;
		case 1:
			//int16;
			min = std::numeric_limits<int16_t>::min();
			max = std::numeric_limits<int16_t>::max();
			if (base >= min && base <= max)
				return;
			else{
				Log(OUT_OF_RANGE, command);
				Log(0, "");
			}
			break;
		case 2:
			//int8;
			min = std::numeric_limits<int32_t>::min();
			max = std::numeric_limits<int32_t>::max();
			if (base >= min && base <= max)
				return;
			else{
				Log(OUT_OF_RANGE, command);
				Log(0, "");
			}
			break;
		case 3:
			//float;
			min = std::numeric_limits<float>::min();
			max = std::numeric_limits<float>::max();
			if (base >= min && base <= max)
				return;
			else{
				Log(OUT_OF_RANGE, command);
				Log(0, "");
			}
			break;
		case 4:
			//double;
			min = std::numeric_limits<double>::min();
			max = std::numeric_limits<double>::max();
			if (base >= min && base <= max)
				return;
			else{
				Log(OUT_OF_RANGE, command);
				Log(0, "");
			}
			break;
		default:
			Log(OUT_OF_RANGE, command);
			Log(0,"");
	}
}

void _pop(std::vector<IOperand const *> &stack){
	stack.pop_back();
}

void _push(std::string command, std::vector<IOperand const *> &stack){
	eOperand type = getType(command);
	std::string val = getValue(command);
	OperandFactory Fac;
	IOperand const *create = Fac.createOperand(type, val);

	stack.push_back(create);
}

void _assert(std::string command, std::vector<IOperand const *> &stack){
	size_t len = (stack.size() - 1);
	std::string temp = stack.at(len)->toString();
	eOperand type = getType(command);
	std::string val = getValue(command);

	if (!(stack.at(len)->getType() == type && stack.at(len)->toString() == val)){
		Log(ASSERTED_VALUE_NOT_EQUAL, command);
		Log(0, "");
	}
}

void _print(std::string command, std::vector<IOperand const *> &stack){
	char c;
	size_t len = stack.size();
	if (stack.empty()){
		Log(EMPTY_STACK, command);
		Log(0,"");
	}
	if (stack.at(len - 1)->getType() == Int8){
		std::string temp = stack.at(len - 1)->toString();
		if ((c = stoi(temp)) && GetErrorCount() == 0)
		std::cout << c << '\n';
	}
}

void _dump(std::vector<IOperand const *> &stack){
	if (!stack.empty()){
		for (size_t i = (stack.size() - 1); i != 0 ; --i)
			std::cout << stack[i]->toString() << '\n';
		std::cout << stack[0]->toString() << '\n';
	}
}

void _add(std::string command, std::vector<IOperand const *> &stack){
	if(stack.size() < 2){
		Log(NEED_TWO_VALUES, command);
		Log(0,"");
	}else{
		size_t len = stack.size() - 1;
		eOperand type1 = stack.at(len)->getType();
		eOperand type2 = stack.at(len - 1)->getType();
		eOperand type = (type1 > type2) ? type1 : type2 ;

		OperandFactory Fac;
		std::string val;

		if (type < 3)
		val = std::to_string(stoi(stack.at(len)->toString()) + stoi(stack.at(len - 1)->toString()));
		if (type > 2)
		val = std::to_string(stod(stack.at(len)->toString()) + stod(stack.at(len - 1)->toString()));

		stack.pop_back();
		stack.pop_back();

		IOperand const *create = Fac.createOperand(type, val);
		checkFlow(type, val, command);
		stack.push_back(create);
		stack.at(stack.size() - 1)->toString();
	}
}

void _sub(std::string command, std::vector<IOperand const *> &stack){
	if(stack.size() < 2){
		Log(NEED_TWO_VALUES, command);
		Log(0,"");
	}else{
		size_t len = stack.size() - 1;
		eOperand type1 = stack.at(len)->getType();
		eOperand type2 = stack.at(len - 1)->getType();
		eOperand type = (type1 > type2) ? type1 : type2 ;
		OperandFactory Fac;
		std::string val;

		if (type < 3)
		val = std::to_string(stoi(stack.at(len)->toString()) - stoi(stack.at(len - 1)->toString()));
		if (type > 2)
		val = std::to_string(stod(stack.at(len)->toString()) - stod(stack.at(len - 1)->toString()));

		stack.pop_back();
		stack.pop_back();

		IOperand const *create = Fac.createOperand(type, val);
		checkFlow(type, val, command);
		stack.push_back(create);
		stack.at(stack.size() - 1)->toString();
	}
}

void _mul(std::string command, std::vector<IOperand const *> &stack){
	if(stack.size() < 2){
		Log(NEED_TWO_VALUES, command);
		Log(0,"");
	}else{
		size_t len = stack.size() - 1;
		eOperand type1 = stack.at(len)->getType();
		eOperand type2 = stack.at(len - 1)->getType();
		eOperand type = (type1 > type2) ? type1 : type2 ;
		OperandFactory Fac;
		std::string val;

		if (type < 3)
		val = std::to_string(stoi(stack.at(len)->toString()) * stoi(stack.at(len - 1)->toString()));
		if (type > 2)
		val = std::to_string(stod(stack.at(len)->toString()) * stod(stack.at(len - 1)->toString()));

		stack.pop_back();
		stack.pop_back();

		IOperand const *create = Fac.createOperand(type, val);
		checkFlow(type, val, command);
		stack.push_back(create);
		stack.at(stack.size() - 1)->toString();
	}
}

void _div(std::string command, std::vector<IOperand const *> &stack){
	size_t len = stack.size() - 1;
	if(stack.size() < 2){
		Log(NEED_TWO_VALUES, command);
		Log(0,"");
	}else{
		if(stack.at(len)->toString() == "0"){
			Log(DIV_BY_ZERO, command);
			Log(0, "");
		}else{

			eOperand type1 = stack.at(len)->getType();
			eOperand type2 = stack.at(len - 1)->getType();
			eOperand type = (type1 > type2) ? type1 : type2 ;
			OperandFactory Fac;
			std::string val;

			if (type < 3)
			val = std::to_string(stoi(stack.at(len - 1)->toString()) / stoi(stack.at(len)->toString()));
			if (type > 2)
			val = std::to_string(stod(stack.at(len - 1)->toString()) / stod(stack.at(len)->toString()));

			stack.pop_back();
			stack.pop_back();

			IOperand const *create = Fac.createOperand(type, val);
			checkFlow(type, val, command);
			stack.push_back(create);
			stack.at(stack.size() - 1)->toString();
		}
	}
}

void _mod(std::string command, std::vector<IOperand const *> &stack){
	std::cout << "inside mod" << '\n';
	size_t len = stack.size() - 1;
	if(stack.size() < 2){
		Log(NEED_TWO_VALUES, command);
		Log(0,"");
	}else{
		if(stack.at(len - 1)->toString() == "0"){
			Log(DIV_BY_ZERO, command);
			Log(0, "");
		}else{

			eOperand type1 = stack.at(len)->getType();
			eOperand type2 = stack.at(len - 1)->getType();
			eOperand type = (type1 > type2) ? type1 : type2 ;
			OperandFactory Fac;
			std::string val;

			if (type < 3)
			val = std::to_string(stoi(stack.at(len)->toString()) - (stoi(stack.at(len)->toString()) / stoi(stack.at(len - 1)->toString())) * stoi(stack.at(len - 1)->toString()));
			if (type > 2){
				double val1 = stod(stack.at(len)->toString());
				double val2 = stod(stack.at(len - 1)->toString());
				val = std::to_string(fmod(val1, val2));
			}

			stack.pop_back();
			stack.pop_back();

			IOperand const *create = Fac.createOperand(type, val);
			checkFlow(type, val, command);
			stack.push_back(create);
			stack.at(stack.size() - 1)->toString();
		}
	}
}

void _exit(){
	PrintLine("Ending current program", INFO);
	setMulti();
	resetErrors();
}

void execute(std::vector<std::string> &InstructionSet){
	std::string command;
	std::vector<IOperand const *> stack;
	for (size_t i = 0; i < InstructionSet.size(); ++i) {
		command = InstructionSet[i];

		if (command.find("pop")!=std::string::npos)
			_pop(stack);
		if (command.find("push")!=std::string::npos)
			_push(command, stack);
		if (command.find("assert")!=std::string::npos)
			_assert(command, stack);
		if (command.find("print")!=std::string::npos)
			_print(command, stack);
		if (command.find("dump")!=std::string::npos)
			_dump(stack);
		if (command.find("add")!=std::string::npos)
			_add(command, stack);
		if (command.find("sub")!=std::string::npos)
			_sub(command, stack);
		if (command.find("mul")!=std::string::npos)
			_mul(command, stack);
		if (command.find("div")!=std::string::npos)
			_div(command, stack);
		if (command.find("mod")!=std::string::npos){
			std::cout << "mod found" << '\n';
			_mod(command, stack);
		}
		if (command.find("exit")!=std::string::npos)
			_exit();
	}
}

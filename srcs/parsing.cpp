#include "includes/abstractVM.hpp"
static int Line;

void resetLine()
{
	resetErrors();
	Line = 1;
}

std::string strip(std::string &command)
{
	std::string temp;

	//Ignores anything after a ';'
	for (size_t i = 0; i < command.size(); ++i)
	{
		if (command[i] == ';')
			break;
		temp += command[i];
	}

	//Ensures command has no comments, extra spaces or leading and trailing spaces or tabs
	command = temp;
	command = regex_replace(command, std::regex(" +|\t+"), " ");
	command = std::regex_replace(command, std::regex("^ +| +$|( ) +"), "$1");
	return (command);
}

int valLimits(double base, std::string command){
	if (command.find('(') < (command.find_last_of(')')))	{
		//😫 templates would make this soooooo easy😫
		if (command.find("int8") != std::string::npos){
			if (base >= std::numeric_limits<int8_t>::min() && base <= std::numeric_limits<int8_t>::max())
				return (0);
		}
		else if (command.find("int16") != std::string::npos){
			if (base >= std::numeric_limits<int16_t>::min() && base <= std::numeric_limits<int16_t>::max())
				return (0);
		}
		else if (command.find("int32") != std::string::npos){
			if (base >= std::numeric_limits<int32_t>::min() && base <= std::numeric_limits<int32_t>::max())
				return (0);
		}
		else if (command.find("float") != std::string::npos){
			if (base >= std::numeric_limits<float>::min() && base <= std::numeric_limits<float>::max())
				return (0);
		}
		else if (command.find("double") != std::string::npos){
			if (base >= std::numeric_limits<double>::min() && base <= std::numeric_limits<double>::max())
				return (0);
		}
		else
			Log(OUT_OF_RANGE, command);
	}

	return 1;
}

int testValue(std::string command){
	bool negative = false;
	double base;
	int num = 0;
	int ref = 0;
	eOperand type = getType(command);

	std::string val = "";
	std::string temp = "";

	for (size_t start = (command.find('(')) + 1; command[start] != ')'; ++start)
		val += command[start];

		//Ensures val has no comments, extra spaces or leading and trailing spaces or tabs
		val = std::regex_replace(val, std::regex("^ +| +$|( ) +"), "$1");
		val = regex_replace(val, std::regex(" +|\t+"), " ");

	for (size_t i = 0; i < val.size(); ++i){
		if (val[i] == '-'){
			negative = true;
			continue;
		}

		if (type > 2 && val[i] == '.')
			continue;

		temp += val[i];
		num += (isdigit(val[i]))?1:0;
		ref++;
	}

	if (ref == 0){
		Log(EMPTY_PEREN, command);
		Log(0,"");
	}

	if (num == ref)
		base = stod(temp);
	else
		return -1;

	if (negative)
		base *= -1;

	return (valLimits(base, command));
}

void TypeValidator(std::string &command)
{
	int DataVal = 0;
	int validDataVal = 0;

	if (command.find("push") != std::string::npos || command.find("assert") != std::string::npos)	{
		DataVal += (command.find("int8") != std::string::npos) ? 1 : 0;
		DataVal += (command.find("int16") != std::string::npos) ? 1 : 0;
		DataVal += (command.find("int32") != std::string::npos) ? 1 : 0;
		DataVal += (command.find("float") != std::string::npos) ? 1 : 0;
		DataVal += (command.find("double") != std::string::npos) ? 1 : 0;
	}

	if (DataVal == 1){
		validDataVal = testValue(command);
	}else if (DataVal > 1){
		Log(MULTIPLE_DATA_TYPES_PASSED, command);
	}else{
		Log(NO_DATA_TYPE, command);
	}

	if (validDataVal == 1)
		Log(OUT_OF_RANGE, command);
	if (validDataVal == -1)
		Log(INVALID_DATA_VALUE, command);
}

void LogicValidator(std::string &command, std::vector<std::string> &InstructionSet)
{
	int instructions = 0;

	instructions += (command.find("pop") != std::string::npos) ? 1 : 0;
	instructions += (command.find("print") != std::string::npos) ? 1 : 0;
	instructions += (command.find("dump") != std::string::npos) ? 1 : 0;
	instructions += (command.find("assert") != std::string::npos) ? 1 : 0;

	if (instructions == 1)
		if (InstructionSet.empty())
			Log(EMPTY_STACK, command);
}

int lineTest(std::string &testString, std::string &command){
	const size_t step = testString.size();

	int count = 0;
	size_t pos = 0;

	while( (pos=command.find(testString, pos)) !=std::string::npos) {
	 pos +=step;
	 ++count ;
	}

	return count;
}

void InstValidator(std::string &command)
{
	int instructions = 0;
	std::string temp = "";
	std::string test = "";

	size_t start = 0;
	while (command[start++] != ' ');
	for (size_t i = start; command[i] != ' '; ++i)
		temp += command[i];


	test = "push";
	instructions += lineTest(test, command);
	test = "pop";
	instructions += lineTest(test, command);
	test = "assert";
	instructions += lineTest(test, command);
	test = "print";
	instructions += lineTest(test, command);
	test = "dump";
	instructions += lineTest(test, command);
	test = "add";
	instructions += lineTest(test, command);
	test = "sub";
	instructions += lineTest(test, command);
	test = "mul";
	instructions += lineTest(test, command);
	test = "div";
	instructions += lineTest(test, command);
	test = "mod";
	instructions += lineTest(test, command);
	test = "exit";
	instructions += lineTest(test, command);
	// instructions += (strcmp(temp.c_str(), "push") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "pop") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "print") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "dump") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "assert") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "add") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "sub") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "mul") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "div") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "mod") == 0)?1:0;
	// instructions += (strcmp(temp.c_str(), "exit") == 0)?1:0;

	std::cout << "instructions : " <<instructions<< '\n';

	if((strcmp(temp.c_str(), "push") == 0) || (strcmp(temp.c_str(), "assert") == 0))
		TypeValidator(command);

	if (command.find("exit") != std::string::npos)
		exitFound();

	if (instructions == 0)
		Log(INVALID_INSTRUCTION_PASSED, command);
	else if (instructions > 1)
		Log(MULTIPLE_INSTRUCTIONS_PASSED, command);
}

void parse(std::string &command, std::vector<std::string> &InstructionSet)
{
	if (command.find(";;") != std::string::npos)
		setSemi();

	command = strip(command);

	if (!command.empty())
		command.insert(0, std::to_string(Line++) + ") ");
	else
		return;

	if (isVerbose())
		std::cout << command << '\n';

	InstValidator(command);
	LogicValidator(command, InstructionSet);
	if (GetErrorCount() == 0)
		InstructionSet.push_back(command);

}

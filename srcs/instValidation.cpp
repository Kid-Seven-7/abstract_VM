#include "includes/abstractVM.hpp"

void validate(std::string arr[5]){
	const char *inst = arr[2].c_str();
	const char *dataType = arr[3].c_str();
	const char *dataVal = arr[4].c_str();

		if (strlen(inst) > 0){
			if (inst[0] == ';'){
				// if (inst[1] == ';')
				// 	exitProg();
				return;
			}
			if (strcmp(inst, "push") == 0 || strcmp(inst, "assert") == 0){
				if(!validInstData(inst, dataType)){
					errorHandler(arr, NO_DATA_TYPE);
				}
			}else{
				if(!validInstNoData(inst, dataType)){
					errorHandler(arr, INVALID_INST);
				}
			}
		}
		if (dataType){
			if (!validDataType(dataType)){
				errorHandler(arr, INVALID_DATATYPE);
			}
		}
		if (dataVal){
			if (!validDataVal(dataType, dataVal)){
				errorHandler(arr, VALUE_EXCEEDS_LIMIT);
			}
		}
}

bool validInstNoData(const char *inst, const char *dataType){
	if ((strcmp(inst, "pop") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "dump") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "add") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "sub") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "div") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "mul") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "mod") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "print") == 0 && strcmp(dataType, "") == 0)
		|| (strcmp(inst, "exit") == 0 && strcmp(dataType, "") == 0)){
		return (true);
	}
	return (false);
}

bool validInstData(const char *inst, const char *dataType){
	if((strcmp(inst, "push") == 0 && strcmp(dataType, "") != 0)
		|| (strcmp(inst, "assert") == 0 && strcmp(dataType, "") != 0))
		return (true);
	return (false);
}

bool validDataVal(const char *dataType, const char *dataVal){
	if (strcmp(dataType, "") == 0)
		return (true);

	double test = std::stod(dataVal);
	if (strcmp(dataType, "int8") == 0){
		if (test < MIN_INT8 || test > MAX_INT8)
			return (false);
		return (true);
	}else	if (strcmp(dataType, "int16") == 0){
		if (test < MIN_INT16 || test > MAX_INT16)
			return (false);
		return (true);
	}else	if (strcmp(dataType, "int32") == 0){
		if (test < MIN_INT32 || test > MAX_INT32)
			return (false);
		return (true);
	}else	if (strcmp(dataType, "float") == 0){
		if (test < MIN_FLOAT || test > MAX_FLOAT)
			return (false);
		return (true);
	}else	if (strcmp(dataType, "double") == 0){
		if (test < MIN_DOUBLE || test > MAX_DOUBLE)
			return (false);
		return (true);
	}
	return (false);
}

bool validDataType(const char *dataType){
	if (strcmp(dataType, "") == 0){
		return (true);
	}
	if (strcmp(dataType, "float") == 0 || strcmp(dataType, "double") == 0)
		return (true);
	else if (strncmp(dataType, "int", 3) == 0){
		if (dataType[3] == '8')
			return (true);
		if ((dataType[3] == '1' && dataType[3] == '6')
		||(dataType[3] == '3' && dataType[4] == '2'))
			return (true);
	}
	return (false);
}

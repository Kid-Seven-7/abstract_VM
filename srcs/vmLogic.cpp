#include "includes/abstractVM.hpp"

void function(std::vector<IOperand> & stack) {
  //TODO
}

void function(std::vector<IOperand> & stack,std::string a,std::string b) {
  //TODO
}

void brain(std::string *arr, std::vector<IOperand> & stack){
  const char * inst = arr[3].c_str();
  const char * dataType = arr[4].c_str();
  const char * dataVal = arr[5].c_str();

    if (strcmp(inst, "pop") == 0)
      function(stack);
    if (strcmp(inst, "dump") == 0)
      function(stack);
    if (strcmp(inst, "add") == 0)
      function(stack);
    if (strcmp(inst, "sub") == 0)
      function(stack);
    if (strcmp(inst, "div") == 0)
      function(stack);
    if (strcmp(inst, "mul") == 0)
      function(stack);
    if (strcmp(inst, "mod") == 0)
      function(stack);
    if (strcmp(inst, "print") == 0)
      function(stack);
    if (strcmp(inst, "push") == 0)
      function(stack, dataType, dataVal);
    if (strcmp(inst, "assert") == 0)
      function(stack, dataType, dataVal);
}

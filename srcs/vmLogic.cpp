#include "includes/abstractVM.hpp"

// \033[1;31m\033[0m

void pop(std::vector<IOperand> & stack) {
  if (stack.size() > 0)
    stack.pop_back();
  else
    std::cout << "\033[1;31mCan not pop empty stack\033[0m" << '\n';
}

void add(std::vector<IOperand> & stack) {
  if (stack.size() > 1){
    // Int8 temp(const stack.back());
    // stack.pop_back();
    // Int8 temp2(stack.back());
    // stack.pop_back();
    //
    // temp.getValue() += temp2.getValue();
    // stack.push_back(temp);
  }
  else
    std::cout << "\033[1;31mCan not add in stack with less than 2 items\033[0m" << '\n';
}

void dump(std::vector<IOperand> & stack) {
  size_t size = stack.size();

  for (size_t i = 0; i < size; i++) {
    //TODO
    //ToString overload
  }

}

void assertFunc(std::vector<IOperand> & stack,std::string dataType,std::string dataVal) {
// (void)stack;
  if (strcmp(dataType.c_str(), "int8") == 0){
    try{
      int i = stoi(dataVal);
      Int8 val(i);
      stack.push_back(val);
    }
    catch(std::exception err){
      std::cout << "error" << '\n';
    }
  }
}


void push(std::vector<IOperand> & stack,std::string dataType,std::string dataVal) {
// (void)stack;
  if (strcmp(dataType.c_str(), "int8") == 0){
    try{
      int i = stoi(dataVal);
      Int8 val(i);
      stack.push_back(val);
    }
    catch(std::exception err){
      std::cout << "error" << '\n';
    }
  }
}

// void function(std::vector<IOperand> & stack) {
//   //TODO
// }
//
// void function(std::vector<IOperand> & stack,std::string a,std::string b) {
//   //TODO
// }

void brain(std::string arr[5], std::vector<IOperand> & stack){
  const char * inst = arr[2].c_str();
  const char * dataType = arr[3].c_str();
  const char * dataVal = arr[4].c_str();

    if (strcmp(inst, "pop") == 0)
      pop(stack);
    if (strcmp(inst, "dump") == 0)
      dump(stack);
    if (strcmp(inst, "add") == 0)
      add(stack);
    // if (strcmp(inst, "sub") == 0)
    //   function(stack);
    // if (strcmp(inst, "div") == 0)
    //   function(stack);
    // if (strcmp(inst, "mul") == 0)
    //   function(stack);
    // if (strcmp(inst, "mod") == 0)
    //   function(stack);
    // if (strcmp(inst, "print") == 0)
    //   function(stack);
    if (strcmp(inst, "push") == 0)
      push(stack, dataType, dataVal);
    if (strcmp(inst, "assert") == 0)
      assertFunc(stack, dataType, dataVal);
}

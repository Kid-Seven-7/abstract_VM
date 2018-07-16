#ifndef _IOP_HPP_
#define _IOP_HPP_

#include "abstractVM.hpp"
#include "OperandFactory.hpp"

class OperandFactory;



class IOperand
{
  public:
	virtual int getPrecision(void) const = 0;
	virtual eOperand getType(void) const = 0;

	virtual IOperand const *operator+(IOperand const &rhs) const = 0;
	virtual IOperand const *operator-(IOperand const &rhs) const = 0;
	virtual IOperand const *operator*(IOperand const &rhs) const = 0;
	virtual IOperand const *operator/(IOperand const &rhs) const = 0;
	virtual IOperand const *operator%(IOperand const &rhs) const = 0;
	virtual std::string const &toString(void) const = 0;
	virtual ~IOperand(void) {}
};

#endif

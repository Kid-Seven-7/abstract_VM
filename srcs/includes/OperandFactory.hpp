#ifndef _OPFAC_HPP_
#define _OPFAC_HPP_

#include "abstractVM.hpp"

class IOperand;

class OperandFactory
{
	private:
    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;
  public:
    OperandFactory();
    OperandFactory(const OperandFactory & rhs);
    OperandFactory(eOperand type);
    IOperand const * createOperand( eOperand type, std::string const & value ) const;

};

#endif

#include "includes/OperandFactory.hpp"
#include "includes/Int8.hpp"
#include "includes/Int16.hpp"
#include "includes/Int32.hpp"
#include "includes/Float.hpp"
#include "includes/Double.hpp"

OperandFactory::OperandFactory(){

}

OperandFactory::OperandFactory(const OperandFactory & rhs){
	(void)rhs;
}

OperandFactory::OperandFactory(eOperand type){
	(void)type;
}

IOperand const *OperandFactory::createOperand( eOperand type, std::string const & value ) const{
	if (type == Int8)
		return (createInt8(value));
	else if (type == Int16)
		return (createInt16(value));
	else if (type == Int32)
		return (createInt32(value));
	else if (type == Float)
		return (createFloat(value));
	else
		return (createDouble(value));
}

IOperand const *OperandFactory::createInt8(std::string const &value) const{
  return (new Int8_class(value));
}

IOperand const *OperandFactory::createInt16(std::string const &value) const{
	return (new Int16_class(value));
}

IOperand const *OperandFactory::createInt32(std::string const &value) const{
	return (new Int32_class(value));
}

IOperand const *OperandFactory::createFloat(std::string const &value) const{
	return (new Float_class(value));
}

IOperand const *OperandFactory::createDouble(std::string const &value) const{
  return (new Double_class(value));
}

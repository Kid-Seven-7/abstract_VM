#ifndef _INT_8_HPP_
#define _INT_8_HPP_

#include "IOperand.hpp"

class Int8_class : public IOperand{
  private:
		int m_Precision;
		eOperand m_DataType;
		std::string m_DataValue;

  public:
		Int8_class();
		Int8_class(const Int8_class &rhs);
		Int8_class(std::string value);

		int getPrecision() const;
		eOperand getType(void) const;
		std::string getValue(void) const;

		IOperand const *operator+(IOperand const &rhs) const;
		IOperand const *operator-(IOperand const &rhs) const;
		IOperand const *operator*(IOperand const &rhs) const;
		IOperand const *operator/(IOperand const &rhs) const;
		IOperand const *operator%(IOperand const &rhs) const;
		std::string const &toString() const;
};
#endif

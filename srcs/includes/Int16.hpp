 #ifndef _INT_16_HPP_
#define _INT_16_HPP_

#include "IOperand.hpp"

class Int16_class : public IOperand{
  private:
		int m_Precision;
		eOperand m_DataType;
		std::string m_DataValue;

  public:
		Int16_class();
		Int16_class(const Int16_class &rhs);
		Int16_class(std::string value);

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

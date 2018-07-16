 #ifndef _INT_32_HPP_
#define _INT_32_HPP_

#include "IOperand.hpp"

class Int32_class : public IOperand{
  private:
		int m_Precision;
		eOperand m_DataType;
		std::string m_DataValue;

  public:
		Int32_class();
		Int32_class(const Int32_class &rhs);
		Int32_class(std::string value);

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

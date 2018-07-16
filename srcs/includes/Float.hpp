 #ifndef _FLOAT_HPP_
#define _FLOAT_HPP_

#include "IOperand.hpp"

class Float_class : public IOperand{
  private:
		int m_Precision;
		eOperand m_DataType;
		std::string m_DataValue;

  public:
		Float_class();
		Float_class(const Float_class &rhs);
		Float_class(std::string value);

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

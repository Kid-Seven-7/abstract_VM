 #ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_

#include "IOperand.hpp"

class Double_class : public IOperand{
  private:
		int m_Precision;
		eOperand m_DataType;
		std::string m_DataValue;

  public:
		Double_class();
		Double_class(const Double_class &rhs);
		Double_class(std::string value);

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

#include "includes/Int32.hpp"

Int32_class::Int32_class()
	: m_Precision(2),
	  m_DataType(Int16),
	  m_DataValue("")
{}

Int32_class::Int32_class(const Int32_class &rhs)
	: m_Precision(rhs.m_Precision),
	  m_DataType(rhs.m_DataType),
	  m_DataValue(rhs.m_DataValue)
{}

Int32_class::Int32_class(std::string value)
	: m_Precision(2),
	  m_DataType(Int16),
	  m_DataValue(value)
{}

int Int32_class::getPrecision() const
{
	return (m_Precision);
}

std::string Int32_class::getValue() const
{
	return (m_DataValue);
}

eOperand Int32_class::getType(void) const
{
	return (eOperand::Int32);
}

IOperand const *Int32_class::operator+(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int32_class::operator-(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int32_class::operator*(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int32_class::operator/(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int32_class::operator%(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

std::string const &Int32_class::toString() const
{
	std::string *temp = new std::string;
	*temp = this->getValue();
	return (*temp);
}

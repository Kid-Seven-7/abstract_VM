#include "includes/Int8.hpp"

Int8_class::Int8_class()
	: m_Precision(0),
	  m_DataType(Int8),
	  m_DataValue("")
{}

Int8_class::Int8_class(const Int8_class &rhs)
	: m_Precision(rhs.m_Precision),
	  m_DataType(rhs.m_DataType),
	  m_DataValue(rhs.m_DataValue)
{}

Int8_class::Int8_class(std::string value)
	: m_Precision(0),
	  m_DataType(Int8),
	  m_DataValue(value)
{}

int Int8_class::getPrecision() const
{
	return (m_Precision);
}

std::string Int8_class::getValue() const
{
	return (m_DataValue);
}

eOperand Int8_class::getType(void) const
{
	return (eOperand::Int8);
}

IOperand const *Int8_class::operator+(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int8_class::operator-(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int8_class::operator*(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int8_class::operator/(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int8_class::operator%(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

std::string const &Int8_class::toString() const
{
	std::string *temp = new std::string;
	*temp = this->getValue();
	return (*temp);
}

#include "includes/Int16.hpp"

Int16_class::Int16_class()
	: m_Precision(1),
	  m_DataType(Int16),
	  m_DataValue("")
{}

Int16_class::Int16_class(const Int16_class &rhs)
	: m_Precision(rhs.m_Precision),
	  m_DataType(rhs.m_DataType),
	  m_DataValue(rhs.m_DataValue)
{}

Int16_class::Int16_class(std::string value)
	: m_Precision(1),
	  m_DataType(Int16),
	  m_DataValue(value)
{}

int Int16_class::getPrecision() const
{
	return (m_Precision);
}

std::string Int16_class::getValue() const
{
	return (m_DataValue);
}

eOperand Int16_class::getType(void) const
{
	return (eOperand::Int16);
}

IOperand const *Int16_class::operator+(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int16_class::operator-(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int16_class::operator*(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int16_class::operator/(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Int16_class::operator%(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

std::string const &Int16_class::toString() const
{
	std::string *temp = new std::string;
	*temp = this->getValue();
	return (*temp);
}

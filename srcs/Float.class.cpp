#include "includes/Float.hpp"

Float_class::Float_class()
	: m_Precision(3),
	  m_DataType(Int16),
	  m_DataValue("")
{}

Float_class::Float_class(const Float_class &rhs)
	: m_Precision(rhs.m_Precision),
	  m_DataType(rhs.m_DataType),
	  m_DataValue(rhs.m_DataValue)
{}

Float_class::Float_class(std::string value)
	: m_Precision(3),
	  m_DataType(Int16),
	  m_DataValue(value)
{}

int Float_class::getPrecision() const
{
	return (m_Precision);
}

std::string Float_class::getValue() const
{
	return (m_DataValue);
}

eOperand Float_class::getType(void) const
{
	return (eOperand::Float);
}

IOperand const *Float_class::operator+(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Float_class::operator-(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Float_class::operator*(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Float_class::operator/(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Float_class::operator%(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

std::string const &Float_class::toString() const
{
	std::string *temp = new std::string;
	*temp = this->getValue();
	return (*temp);
}

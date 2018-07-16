#include "includes/Double.hpp"

Double_class::Double_class()
	: m_Precision(4),
	  m_DataType(Int16),
	  m_DataValue("")
{}

Double_class::Double_class(const Double_class &rhs)
	: m_Precision(rhs.m_Precision),
	  m_DataType(rhs.m_DataType),
	  m_DataValue(rhs.m_DataValue)
{}

Double_class::Double_class(std::string value)
	: m_Precision(4),
	  m_DataType(Int16),
	  m_DataValue(value)
{}

int Double_class::getPrecision() const
{
	return (m_Precision);
}

std::string Double_class::getValue() const
{
	return (m_DataValue);
}

eOperand Double_class::getType(void) const
{
	return (eOperand::Double);
}

IOperand const *Double_class::operator+(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Double_class::operator-(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Double_class::operator*(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Double_class::operator/(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

IOperand const *Double_class::operator%(IOperand const &rhs) const
{
	std::cout << rhs.getPrecision() << '\n';
	return (&rhs);
}

std::string const &Double_class::toString() const
{
	std::string *temp = new std::string;
	*temp = this->getValue();
	return (*temp);
}

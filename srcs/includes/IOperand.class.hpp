#ifndef __IOPERAND_HPP__
#define __IOPERAND_HPP__

#include "abstractVM.hpp"

class IOperand {
	private:
		/* Variable types
			std::string;
			int;
			double;
			float;
			bool;
		*/

	protected:

	public:
		/* Return types
			std::string;
			int;
			double;
			float;
			bool;
		*/

		//getters
			// virtual int getPrecision(void) const = 0;
			// virtual std::string getType(void) const = 0;
			virtual std::string getValue(void) const = 0;

		//setters
			// virtual void setPrecision(int deci) = 0;
			// virtual void setType(std::string type) = 0;

		//constructor(s)
			//default
			// IOperand();

			//copy
			// IOperand(const IOperand & rhs);

		//destructor
			// ~IOperand();

		//Overloads
			//Operator Overloads
			// virtual IOperand const * operator+(IOperand const & rhs) const = 0;
			// virtual IOperand const * operator-(IOperand const & rhs) const = 0;
			// virtual IOperand const * operator*(IOperand const & rhs) const = 0;
			// virtual IOperand const * operator/(IOperand const & rhs) const = 0;
			// virtual IOperand const * operator%(IOperand const & rhs) const = 0;

			//ToString Overload
			// virtual std::string const & ToString(void) const = 0;
};

#endif

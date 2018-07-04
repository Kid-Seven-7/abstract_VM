#ifndef __INT8_HPP__
#define __INT8_HPP__

#include "abstractVM.hpp"

class Int8 : public IOperand{
	private:
		int _precision;
		std::string _type;
		unsigned char _value;

	protected:

	public:
		//getters
			int getPrecision(void);
			std::string getType(void);
			unsigned char getValue(void);

		//setters
			void setPrecision(int deci);
			void setType(std::string type);
			void setValue(unsigned char value);

		//constructor(s)
			//default
			Int8();

			//copy
			Int8(const Int8 & rhs);

			//simple
			Int8(unsigned char value);

		//destructor
			~Int8();

		//Overloads
			//Operator Overloads
			Int8 const * operator=(Int8 const & rhs);
			// Int8 const * operator+(Int8 const & rhs) const;
			// Int8 const * operator-(Int8 const & rhs) const;
			// Int8 const * operator*(Int8 const & rhs) const;
			// Int8 const * operator/(Int8 const & rhs) const;
			// Int8 const * operator%(Int8 const & rhs) const;

			//ToString Overload
			std::string const & ToString(void);
};

#endif

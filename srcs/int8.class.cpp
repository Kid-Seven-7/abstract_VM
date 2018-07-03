#include "includes/abstractVM.hpp"

//getters
	int Int8::getPrecision(){return (this -> _precision);}
	std::string Int8::getType(){return (this -> _type);}
	unsigned char Int8::getValue(){return (this -> _value);}

//setters
	void Int8::setPrecision(int precision){this->_precision = precision;}
	void Int8::setType(std::string type){this->_type = type;}
	void Int8::setValue(unsigned char value){this->_value = value;}

//constructor(s)
//Default
	Int8::Int8(){
		this->_precision = 0;
		this->_type = "Int8";
		this->_value = 0;
	}

//Copy
	Int8::Int8(const Int8 & rhs){
		std::cout << "Copy constuctor called" << std::endl;
		this->_precision = rhs._precision;
		this->_type = rhs._type;
		this->_value = rhs._value;
	}

//simple
	Int8::Int8(unsigned char value){
		std::cout << "A simple constuctor called" << std::endl;
		this->_precision = 0;
		this->_type = "Int8";
		this->_value = value;
	}

//deconstructor
	Int8::~Int8(){
		std::cout << "Destructor called\n";
	}

//Overloads
	//Assign Overload
		const Int8 * Int8::operator=(const Int8 & rhs){
			this->_precision = rhs._precision;
			this->_type = rhs._type;
			this->_value = rhs._value;

			return (this);
		}

		// Int8 const * operator+(Int8 const & rhs) const{
		//
		// }
		// Int8 const * operator-(Int8 const & rhs) const{
		//
		// }
		// Int8 const * operator*(Int8 const & rhs) const{
		//
		// }
		// Int8 const * operator/(Int8 const & rhs) const{
		//
		// }
		// Int8 const * operator%(Int8 const & rhs) const{
		//
		// }

	//ToString Overload
		std::string const & Int8::ToString(){
			// std::stringstream stream;
			// stream << "some_message : " << std::endl;
			// const std::string str =  stream.str();
			const std::string& ref = this->_type;
		 return (ref);
		}

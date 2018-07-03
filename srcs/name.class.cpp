#include "__HEADERNAME_HPP__"

//getters
	std::string class_name::Get(){return (this-> some_variable);}

//setters
	void class_name::Set(){this->some_variable = some_variable;}

//constructor(s)
//Default
	class_name::class_name(){
		std::cout << "Default constuctor called" << std::endl;
		this->some_variable = some_other_variable
		class_name::NumOf++;
	}

//Copy
	class_name::class_name(const class_name [some_variable_name]){
		std::cout << "Copy constuctor called" << std::endl;
		ptr = new class_name;
		*ptr = *some_variable_name.ptr
		this->some_variable = some_other_variable
		class_name::NumOf++;
	}

//simple
	class_name::class_name(some_variable){
		std::cout << "A simple constuctor called" << std::endl;
		this->some_variable = some_other_variable
		class_name::NumOf++;
	}

//deconstructor
	class_name::~class_name(){
		std::cout << "Destructor called\n";
	}

//Member functions
	void class_name::SetAll(some_variable){
		this->some_variable = some_other_variable
		class_name::NumOf++;
	}

//Overloads
	//Assign Overload
		class_name & class_name::operator=(const class_name [some_variable1] & rhs){
			std::cout
			<< "Assignment operator called"
			<< '\n';

			this->some_variable = rhs.some_member_function();

			return (*this);
		}
		class_name & operator==(class_name const & rhs){

		}
		class_name & operator!=(class_name const & rhs){

		}
		class_name & operator<(class_name const & rhs){

		}
		class_name & operator>(class_name const & rhs){

		}
		class_name & operator<=(class_name const & rhs){

		}
		class_name & operator>=(class_name const & rhs){

		}
		class_name & operator<<(class_name const & rhs){

		}
		class_name & operator>>(class_name const & rhs){

		}

	//ToString Overload
		void class_name::ToString(){
			std::cout << "some_message : " << some_variable << std::endl;
		}

	//Static functions
		int GetNumOf(){return (NumOf);}

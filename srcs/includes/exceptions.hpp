#ifndef _EXCEP_HPP_
#define _EXCEP_HPP_

#include "abstractVM.hpp"

struct CustomExceptions{
	struct Syntax : public std::exception{char const *what(void) const _NOEXCEPT;};
  struct Logic : public std::exception{char const *what(void) const _NOEXCEPT;};
};

#endif

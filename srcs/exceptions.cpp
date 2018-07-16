#include "includes/abstractVM.hpp"

char const *CustomExceptions::Syntax::what(void) const _NOEXCEPT { return "The following syntax error was found:-"; }
char const *CustomExceptions::Logic::what(void) const _NOEXCEPT { return "The following logic error was found:-"; }

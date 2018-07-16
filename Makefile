NAME = avm

SRCPATH = srcs/

SRC = 	$(SRCPATH)Int8.class.cpp\
				$(SRCPATH)Int16.class.cpp\
				$(SRCPATH)Int32.class.cpp\
				$(SRCPATH)Float.class.cpp\
				$(SRCPATH)Double.class.cpp\
				$(SRCPATH)main.cpp\
				$(SRCPATH)parsing.cpp\
				$(SRCPATH)log.cpp\
				$(SRCPATH)display.cpp\
				$(SRCPATH)exceptions.cpp\
				$(SRCPATH)vmLogic.cpp\
				$(SRCPATH)OperandFactory.cpp

SRCO = 	Int8.class.o\
				Int16.class.o\
				Int32.class.o\
				Float.class.o\
				Double.class.o\
				main.o\
				parsing.o\
				log.o\
				display.o\
				exceptions.o\
				vmLogic.o\
				OperandFactory.o

COMP = clang++

CPPSTD = -std=c++11

CPPFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	@echo compiling source files
	@$(COMP) -c $(SRC) $(CPPFLAGS) $(CPPSTD)
	@$(COMP) -o $(NAME) $(SRCO)
	clear

clean:
	@echo removing object files
	@rm -f $(SRCO)

fclean: clean
	@echo removing exectutable
	@rm -f $(NAME)

re: fclean all

NAME = avm

SRCPATH = srcs/

SRC = $(SRCPATH)main.cpp\
			$(SRCPATH)parsing.cpp\
			$(SRCPATH)asthetics.cpp\
			$(SRCPATH)virtualMachine.cpp\
			$(SRCPATH)instValidation.cpp\
			$(SRCPATH)errorHandling.cpp\
			$(SRCPATH)vmLogic.cpp\
			$(SRCPATH)int8.class.cpp

SRCO = 	main.o\
				parsing.o\
				asthetics.o\
				virtualMachine.o\
				instValidation.o\
				errorHandling.o\
				vmLogic.o\
				int8.class.o

COMP = clang++

CPPFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	@echo compiling source files
	@$(COMP) -c $(SRC) $(CPPFLAGS)
	@$(COMP) -o $(NAME) $(SRCO)
	clear

clean:
	@echo removing object files
	@rm -f $(SRCO)

fclean: clean
	@echo removing exectutable
	@rm -f $(NAME)

re: fclean all

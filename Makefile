NAME = avm

SRCPATH = srcs/

SRC = $(SRCPATH)main.cpp\
			$(SRCPATH)parsing.cpp\
			$(SRCPATH)asthetics.cpp\
			$(SRCPATH)virtualMachine.cpp\
			$(SRCPATH)int8.class.cpp

SRCO = 	main.o\
				parsing.o\
				asthetics.o\
				virtualMachine.o\
				int8.class.o

COMP = clang++

CPPFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(COMP) -c $(SRC) $(CPPFLAGS)
	$(COMP) -o $(NAME) $(SRCO)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

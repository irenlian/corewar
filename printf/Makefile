C = *.c
OBJECTS = *.o
INCLUDES = ./includes
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Wextra -Wall -Werror -c $(C) -I $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
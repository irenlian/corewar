C = src/main.c src/list_worker.c get_next_line/get_next_line.c
OBJECTS = *.o
INCLUDES = ./includes
NAME = corewar

all: $(NAME)

$(NAME):
	cd printf && make
	gcc -Wextra -Wall -Werror -g -c $(C) -I $(INCLUDES)
	gcc -Wextra -Wall -Werror -o $(NAME) $(OBJECTS) -L./printf -lftprintf
clean:
	rm -f $(OBJECTS)
	cd printf && make clean
fclean: clean
	rm -f $(NAME)
	cd printf && make fclean
re: fclean all
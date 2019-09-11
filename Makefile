NAME	=	compile

LIBFT_PATH	= ./libft
VM_PATH	= ./src/vm
ASM_PATH	= ./src/assembler

all:	$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@make -C $(VM_PATH)
	@make -C $(ASM_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(VM_PATH) clean
	@make -C $(ASM_PATH) clean

fclean:	clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(VM_PATH) fclean
	@make -C $(ASM_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re

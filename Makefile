NAME	=	compile

LIBFT_PATH	= ./libft
VM_PATH	= ./vm
ASM_PATH	= ./assembler

all:	$(NAME)
	@printf "\x1b[38;5;160m"
	@echo " ▄████████  ▄██████▄     ▄████████    ▄████████  ▄█     █▄     ▄████████    ▄████████ "
	@echo "███    ███ ███    ███   ███    ███   ███    ███ ███     ███   ███    ███   ███    ███ "
	@printf "\x1b[38;5;166m"
	@echo "███    █▀  ███    ███   ███    ███   ███    █▀  ███     ███   ███    ███   ███    ███ "
	@printf "\x1b[38;5;226m"
	@echo "███        ███    ███  ▄███▄▄▄▄██▀  ▄███▄▄▄     ███     ███   ███    ███  ▄███▄▄▄▄██▀ "
	@printf "\x1b[38;5;28m"
	@echo "███        ███    ███ ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     ███     ███ ▀███████████ ▀▀███▀▀▀▀▀   "
	@printf "\x1b[38;5;19m"
	@echo "███    █▄  ███    ███ ▀███████████   ███    █▄  ███     ███   ███    ███ ▀███████████ "
	@printf "\x1b[38;5;126m"
	@echo "███    ███ ███    ███   ███    ███   ███    ███ ███ ▄█▄ ███   ███    ███   ███    ███ "
	@echo "████████▀   ▀██████▀    ███    ███   ██████████  ▀███▀███▀    ███    █▀    ███    ███ "
	@echo "                        ███    ███                                         ███    ███ "
	@printf "\x1b[32;1m"


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
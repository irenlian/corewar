# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 12:32:00 by pdemian           #+#    #+#              #
#    Updated: 2019/06/28 16:36:37 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		corewar

SRCDIR :=	src/assembler/
INCDIR :=	includes/
LIBDIR :=	libft/
OBJDIR :=	.obj/

CC :=		clang
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INCDIR)
LFLAGS :=	-lft -L $(LIBDIR)

LIB :=		$(LIBDIR)libft.a	
INC :=		corewar
SRC :=		list_worker main

INCS :=		$(addprefix $(INCDIR), $(addsuffix .h, $(INC)))
SRCS :=		$(addprefix $(SRCDIR), $(addsuffix .c, $(SRC)))
OBJS :=		$(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME):	$(LIB) $(OBJDIR) $(OBJS)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
$(LIB):
	@ make -C $(LIBDIR) libft.a

$(OBJDIR):
	mkdir -p $(OBJDIR)$(SRCDIR)
$(OBJDIR)%.o:		%.c $(INCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

mclean:
	rm -rf $(OBJDIR)
mfclean: mclean
	rm -rf $(NAME)
mre: mfclean all

clean: mclean
	make clean -C $(LIBDIR)
fclean: clean mfclean
	make fclean -C $(LIBDIR)
re: fclean all

.PHONY: $(LIB) all clean fclean re

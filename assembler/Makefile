# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 19:07:41 by pdemian           #+#    #+#              #
#    Updated: 2019/09/11 19:07:50 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		../asm

SRCDIR :=	src/
INCDIR :=	../includes/
LIBDIR :=	../libft/
OBJDIR :=	.obj/

CC :=		clang
CFLAGS :=	-g #-Wall -Wextra -Werror
IFLAGS :=	-I $(INCDIR)
LFLAGS :=	-lft -L $(LIBDIR)

LIB :=		$(LIBDIR)libft.a	
INC :=		corewar op
SRC :=		main byte_list validation

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


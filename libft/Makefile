# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 15:55:01 by pdemian           #+#    #+#              #
#    Updated: 2019/03/26 18:11:26 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		libft.a
OBJDIR :=	.obj/
INCLD :=	includes/libft.h

CC :=		clang
CFLAGS :=	-g #-Wall -Wextra -Werror

SRCS :=		ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_strlen.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_isdigit.c \
				ft_atoi.c \
				ft_isascii.c \
				ft_isalpha.c \
				ft_isalnum.c \
				ft_tolower.c \
				ft_isprint.c \
				ft_toupper.c  \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strjoin.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_memccpy.c \
				ft_strlcat.c \
				ft_memmove.c  \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_numlen.c \
				ft_swap.c \
				ft_sqrt.c \
				ft_free_arr.c \
				ft_foreach.c \
				ft_power.c \
				itoa_base.c \
				floatoa.c \
				ft_strndup.c \
				ft_strrew.c \
				ft_u_itoa.c \
				u_itoa_base.c \
				get_next_line.c \
				ft_del.c \
				is_whitespace.c \
				ft_strcdup.c \
				ft_strwhile.c \
				ft_lstdelast.c \
				ft_lstpush.c \
				ft_lstfree.c \
				types_a.c \
				types_b.c \
				x_type.c \
				manage.c \
				parsing.c \
				ft_lstrev.c \
				ft_printf.c

OBJS :=		$(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

   
all:		$(NAME)

$(NAME): 	$(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(OBJDIR)%.o:		%.c $(INCLD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re

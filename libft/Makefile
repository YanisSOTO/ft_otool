# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoto <ysoto@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 10:24:04 by ysoto             #+#    #+#              #
#    Updated: 2014/04/26 20:39:17 by ysoto            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC			=	ft_memset.c						\
				ft_bzero.c						\
				ft_memcpy.c						\
				ft_memccpy.c					\
				ft_memmove.c					\
				ft_memchr.c						\
				ft_memcmp.c						\
				ft_strlen.c						\
				ft_strdup.c						\
				ft_strcpy.c						\
				ft_strncpy.c					\
				ft_strcat.c						\
				ft_strncat.c					\
				ft_strlcat.c					\
				ft_strchr.c						\
				ft_strrchr.c					\
				ft_strstr.c						\
				ft_strcmp.c						\
				ft_strnstr.c					\
				ft_strncmp.c					\
				ft_atoi.c						\
				ft_isalpha.c					\
				ft_isdigit.c					\
				ft_isascii.c					\
				ft_isalnum.c					\
				ft_isprint.c					\
				ft_toupper.c					\
				ft_tolower.c					\
				ft_putchar.c					\
				ft_putstr.c						\
				ft_putnbr.c						\
				ft_memalloc.c					\
				ft_memdel.c						\
				ft_striter.c					\
				ft_striteri.c					\
				ft_strclr.c						\
				ft_strdel.c						\
				ft_strnew.c						\
				ft_strsub.c						\
				ft_strequ.c						\
				ft_strnequ.c					\
				ft_strjoin.c					\
				ft_strmap.c						\
				ft_strmapi.c					\
				ft_strtrim.c					\
				ft_putendl.c					\
				ft_putchar_fd.c					\
				ft_putendl_fd.c					\
				ft_putnbr_fd.c					\
				ft_putstr_fd.c					\
				ft_strsplit.c					\
				ft_print_tab.c					\
				ft_strsrch.c					\
				ft_tab_dup.c					\
				gnl.c							\
				ft_check_digit.c				\
				ft_strcount.c					\
				ft_tabfree.c					\
				ft_convert_adress_to_string.c	\

OBJ				= $(SRC:.c=.o)

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf

CC				= gcc

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(CC) -c $(SRC) $(CFLAGS)
				@ar rc $(NAME) $(OBJ)

clean:
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY : fclean clean all

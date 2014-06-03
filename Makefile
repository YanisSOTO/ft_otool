# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguilbau <mguilbau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 16:08:49 by mguilbau          #+#    #+#              #
#    Updated: 2014/04/26 20:44:55 by ysoto            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_otool

LIB				= libft/

SRCS			=	otool_src/main.c					\
					otool_src/ft_print.c				\

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I$(I)

LFLAG			= -L libft/ -lft

I				= includes/

all: $(NAME)

$(NAME): $(OBJS)

	@echo "\033[1;33m"
	@make -C $(LIB)
	@echo "\033[1;37m"
	$(CC) $(CFLAGS) $(LFLAG) -o $(NAME) $(SRCS)
	@echo "Compilation complete √"

clean:

	@make -C $(LIB) clean
	@$(RM) $(OBJS)
	@echo  "\033[1;34m"
	@echo "Clean...\033[1;32m done"


fclean:		clean

	@make -C $(LIB) fclean
	@$(RM) $(NAME)
	@echo  "\033[1;34m"
	@echo "Fclean...\033[1;32m done"

re:			fclean all

.PHONY : fclean clean all

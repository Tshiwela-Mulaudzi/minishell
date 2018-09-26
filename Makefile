# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 13:28:38 by tmulaud           #+#    #+#              #
#    Updated: 2018/09/26 10:58:00 by tmulaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

HLOC = .

FLAGS = -Wall -Wextra -Werror -I$(HLOC) -c -g -g3 -static

SRC = commands.c commands2.c main.c needed.c needed2.c needed3.c \

LIB = libft/libft.a

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME):
	@make -C ./libft/
	@gcc $(FLAGS) $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "Compiled minishell"

lib:
	@make -C libft/ all

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Cleaned object files"

fcleanlib:
	@make -C libft/ fclean

fclean:
	@rm -f $(NAME)
	@echo "Cleaned minishell"

mclean:
	@find .-name '._*' -type f delete
	@echo "Cleaned hidden files"

re: fcleanlib fclean clean lib all

test: fclean all



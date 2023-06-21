# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:54:33 by subpark           #+#    #+#              #
#    Updated: 2023/06/21 16:27:08 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
SRC = ft_printf.c decimalNpointer.c low16.c prints1.c up16.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@$(CC) $(CCFLAGS) -c $< -o $@

clean :
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclea re

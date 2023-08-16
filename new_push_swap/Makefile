# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 15:21:28 by subpark           #+#    #+#              #
#    Updated: 2023/08/16 15:35:49 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

PRINTF		= libftprintf.a
PRINTF_DIR	= ft_printf
PRINTF_PATH	= $(PRINTF_DIR)/$(PRINTF)

NAME	= tmp
SRC		= source/push.cc

OBJ		= $(SRC:.c=.o)

all: $(NAME)

clean:
			rm -f $(OBJ)
			make clean -C $(LIBFT_DIR)
			make clean -C $(PRINTF_DIR)
fclean: clean
			rm -f $(NAME)
			rm -f $(PRINTF)
			rm -f $(LIBFT)
re: fclean all

%.o: %.c push_swap.h
			$(CC) -c $< -o $@
#			$(CC) $(CCFLAGS) -c $< -o $@
$(LIBFT):
			make bonus -C $(LIBFT_DIR)
			mv $(LIBFT_DIR)/$(LIBFT) .
$(PRINTF):
			make -C $(PRINTF_DIR)
			mv $(PRINTF_DIR)/$(PRINTF) .
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
			$(CC) -o $@ $^
#			$(CC) $(CCFLAGS) -o $@ $^
.PHONY: all clean fclean re
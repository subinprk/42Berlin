# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 15:21:28 by subpark           #+#    #+#              #
#    Updated: 2023/09/11 15:06:04 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra -g

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

PRINTF		= libftprintf.a
PRINTF_DIR	= ft_printf
PRINTF_PATH	= $(PRINTF_DIR)/$(PRINTF)

NAME	= push_swap
SRC		= source/push.c source/rerotate.c source/rotate.c source/swap.c \
		source/main.c source/select_sort.c source/stacking.c source/move.c \
		source/node.c source/check_node.c

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
			$(CC) $(CCFLAGS) -c $< -o $@
$(LIBFT):
			make bonus -C $(LIBFT_DIR)
			mv $(LIBFT_DIR)/$(LIBFT) .
$(PRINTF):
			make -C $(PRINTF_DIR)
			mv $(PRINTF_DIR)/$(PRINTF) .
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
			$(CC) $(CCFLAGS) -o $@ $^
.PHONY: all clean fclean re

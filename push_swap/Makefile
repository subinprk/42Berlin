# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siun <siun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 17:11:57 by subpark           #+#    #+#              #
#    Updated: 2023/08/14 00:24:23 by siun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

PRINTF		= libftprintf.a
PRINTF_DIR	= ft_printf
PRINTF_PARH = $(PRINTF_DIR)/$(PRINTF)

NAME = tmp
SRC = action_tools/push.c action_tools/rerotate.c \
	action_tools/rotate.c action_tools/swap.c push_swap.c select_sort.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

clean :
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(PRINTF)
		@rm -f $(LIBFT)

re: fclean all

%.o: %.c push_swap.h
	@$(CC) -c $< -o $@
#	@$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT) .

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@mv $(PRINTF_DIR)/$(PRINTF) .

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
		@$(CC) -o $@ $^
#		@$(CC) $(CCFLAGS) -o $@ $^

.PHONY: all clean fclean re
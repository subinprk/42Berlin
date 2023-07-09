# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 17:11:57 by subpark           #+#    #+#              #
#    Updated: 2023/07/10 00:10:31 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

NAME = tmp.a
SRC = list_tools/ft_lstadd_front.c list_tools/ft_lstclear.c \
	list_tools/ft_lstdelone.c list_tools/ft_lstlast.c list_tools/ft_lstnew.c \
	list_tools/ft_lstsize.c action_tools/push.c action_tools/rerotate.c \
	action_tools/rotate.c action_tools/swap.c other_tools/ft_atoi.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

%.o: %.c push_swap.h
	@$(CC) $(CCFLAGS) -c $< -o $@

clean :
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclea re
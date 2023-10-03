# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 10:43:28 by subpark           #+#    #+#              #
#    Updated: 2023/10/03 11:51:16 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = pipex
CC			 = cc
CCFLAGS		= -Werror -Wall -Wextra -fsanitize=address
RM 			= rm -rf
SRCS		= src


$(NAME) :
			make all -C libft
			CC $(CCFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
		$(RM) $(NAME)
		make fclean -C libft

clean :
		$(RM) $(NAME)
		make clean -C libft

re : fclean all
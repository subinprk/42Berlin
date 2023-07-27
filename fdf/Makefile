# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siun <siun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 15:58:17 by subpark           #+#    #+#              #
#    Updated: 2023/07/27 17:32:26 by siun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CCFLAGS		= -Wall -Werror -Wextra

RM			= rm

SOURCE_DIR	= source

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

MLX			= libmlx.a
MLX_DIR		= minilibx-linux
MLX_PATH	= $(MLX_DIR)/$(MLX)
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

HEADERS		= -I $(SOURCE_DIR) -I $(LIBFT_I_DIR) -I $(MLX_I_DIR)
LINUX_LINK	= -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME 		= fdf
SRC_NAME 	= source/alloc_array.c source/load_map.c source/get_next_line.c\
			source/vect_cal.c
OBJ_NAME 	= $(SRC_NAME:.c=.o)

# Main Command

# Don't forget to run "git submodule init && git submodule update"
all: $(NAME)

#bonus: $(NAME_B)

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		@$(RM) -f $(SOURCE_DIR)/$(OBJ_NAME)
		@$(RM) -rf $(MLX_DIR)/build

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) -f $(LIBFT)
		@$(RM) -f $(MLX)
		@$(RM) -f $(OBJ_NAME)
		@$(RM) -f $(NAME)

re: fclean all


# Sub Command

%.o: %.c
		@$(CC) -Imlx -c -o $@ $< $(HEADERS)
#		@$(CC) $(CCFLAGS) -Imlx -c -o $@ $< $(HEADERS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@mv $(LIBFT_DIR)/$(LIBFT) .

$(MLX):
		@make -C $(MLX_DIR)
		@mv $(MLX_DIR)/$(MLX) .

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX)
		@$(CC) -o $@ $^
# -fsanitize=address -static-libasan -g
#		@$(CC) $(CCFLAGS) -o $@ $^

# Phony target

.PHONY: all clean fclean re
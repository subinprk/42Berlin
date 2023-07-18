# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 15:58:17 by subpark           #+#    #+#              #
#    Updated: 2023/07/18 16:46:40 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm

INC_DIR		= ./include

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_I_DIR	= $(LIBFT_DIR)/include
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

MLX		= libmlx_Linux.a
MLX_DIR	= minilibx-linux
MLX_I_DIR	= $(MLX_DIR)/include
MLX_PATH	= $(MLX_DIR)/$(MLX)
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

HEADERS		= -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX_I_DIR)
LINUX_LINK	= -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME 		= fdf
SRC_NAME 	= alloc_array.c load_map.c
OBJ_NAME 	= $(SRC_NAME:.c=.o)

# Main Command

# Don't forget to run "git submodule init && git submodule update"
all: $(NAME)

#bonus: $(NAME_B)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) -f $(OBJ_NAME)
		@$(RM) -f $(OBJ_NAME_B)
		@$(RM) -rf $(MLX_DIR)/build

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) -f $(LIBFT)
		@$(RM) -f $(MLX)
		@$(RM) -f $(OBJ_NAME)
		@$(RM) -f $(OBJ_NAME_B)
		@$(RM) -f $(NAME)
		@$(RM) -f $(NAME_B)

re: fclean all


# Sub Command

%.o: %.c
		@$(CC) $(CFLAGS) -Imlx -c -o $@ $< $(HEADERS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@mv $(LIBFT_PATH) ./

$(MLX):
		@make -C $(MLX_DIR)
		@mv $(MLX_PATH) ./

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX)
		@$(CC) $(CCFLAGS) -o $@ $^ $(HEADERS) $(LINUX_LINK)

# Phony target

.PHONY: all clean fclean re bonus 
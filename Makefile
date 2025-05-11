# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:11 by mchingi           #+#    #+#              #
#    Updated: 2025/05/11 16:03:46 by mchingi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -l:libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz

LIBFT = ./libft

LFT = $(LIBFT)/libft.a

MINILIBX = ./minilibx-linux

MLX = $(MINILIBX)/libmlx_Linux.a

RM = rm -rf

SRC =	./src/main.c \
		./src/utils.c \
		./src/file_management.c \
		./src/scene_validations.c

INC =	./inc/miniRT.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(LFT) $(MLX) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LFT) -o $(NAME)
			@echo "Program Compiled!"

$(LFT): 
			@echo "Building LIBFT"
			@make -C $(LIBFT)

$(MLX):
			@echo "Building MLX"
			@make -C $(MINILIBX)

clean:		
			$(RM) $(OBJ)
			@make -C $(LIBFT) clean
			@echo "Deleted!"

fclean: clean
		$(RM) $(NAME)
		@make -C $(MINILIBX) clean
		@make -C $(LIBFT) fclean

re: fclean all
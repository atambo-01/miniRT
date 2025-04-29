# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:11 by mchingi           #+#    #+#              #
#    Updated: 2025/04/29 15:44:28 by mchingi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -l:libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz

MINILIBX = ./minilibx-linux

MLX = $(MINILIBX)/libmlx_Linux.a

RM = rm -rf

SRC =	./src/main.c \
		./src/utils.c

INC =	./inc/miniRT.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(MLX) $(OBJ)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(MLX) $(OBJ) -o $(NAME)
			@echo "Program Compiled!"

$(MLX):
			@echo "Building MLX"
			@make -C $(MINILIBX)

clean:		
			$(RM) $(OBJ)
			@echo "Deleted!"

fclean: clean
		$(RM) $(NAME)
		@make -C $(MINILIBX) clean

re: fclean all
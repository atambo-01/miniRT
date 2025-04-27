# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 18:48:12 by atambo            #+#    #+#              #
#    Updated: 2025/03/26 21:07:07 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		=	src/minirt.c\
				src/check_file.c\
				src/init.c\
				src/input.c\
				src/input_util.c\
				src/util.c\
				src/ft_perror.c\
				src/upscale_img.c\
				src/render_scene.c\

NAME		=	miniRT
CC			=	cc
CFLAGS		=	-g #-Wall -Wextra -Werror
OBJS		=	$(SOURCES:.c=.o)
INCLUDES	=	-Iinc

SUBDIR		=	./minilibx-linux
LIBS		=	-Lminilibx-linux -l:libmlx_Linux.a\
				-L/usr/lib -lXext -lX11 -lm -lz

all: submake $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

submake:
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir);)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

clean:
	rm -f $(OBJS)
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) clean;)

fclean: clean
	rm -f $(NAME)
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) fclean;)

re: fclean all

# Phony targets
.PHONY: all clean fclean re submake


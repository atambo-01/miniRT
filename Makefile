# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <atambo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:11 by mchingi           #+#    #+#              #
#    Updated: 2025/05/23 13:55:26 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		=	src/check_file.c\
				src/init.c\
				src/input.c\
				src/input_util.c\
				src/util.c\
				src/upscale_img.c\
				src/render_scene.c\
				src/print_data.c\
				src/hit_obj.c\
				src/exit_minirt.c\
				src/get_next_line.c\
				src/get_next_line_utils.c\
				src/read_file.c\
				src/minirt_error.c\
				src/ray.c\
				src/costum_scene.c\
				src/upscale_assign.c\
				src/hit_light.c\
				src/main.c\
				src/file_management.c\
				src/scene_validations.c\
				src/fill_data.c src/fill_obj_data.c\
				src/utils.c src/utils2.c\

NAME		=	miniRT
CC			=	cc
CFLAGS		=	-g #-Wall -Wextra -Werror
OBJS		=	$(SOURCES:.c=.o)
INCLUDES	=	-Iinc -Ilibft

SUBDIR		=	./minilibx-linux ./libft
LIBS		=	-Lminilibx-linux -l:libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz\
				-Llibft -l:libft.a\

all: submake $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

submake:
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir);)

clean:
	rm -f $(OBJS)
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) clean;)

fclean: clean
	rm -f $(NAME)
	$(foreach dir, $(SUBDIR), $(MAKE) -C $(dir) fclean;)

re: fclean all

# Phony targets
.PHONY: all clean fclean re submake


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <atambo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:11 by mchingi           #+#    #+#              #
#    Updated: 2025/07/09 14:07:07 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS		=	\
				\
				src/miniRT.o\
				\
				src/mchingi/file_management.o\
				src/mchingi/fill_data_acl.o\
				src/mchingi/fill_data.o\
				src/mchingi/fill_obj_data.o\
				src/mchingi/scene_validations.o\
				src/mchingi/utils.o\
				src/mchingi/utils2.o\
				src/mchingi/utils3.o\
				src/mchingi/print_debug.o\
				\
				src/atambo/minirt_error.o\
				src/atambo/exit_minirt.o\
				src/atambo/init.o\
				src/atambo/util_01.o\
				src/atambo/util_dbl.o\
				src/atambo/util_vec3_01.o\
				src/atambo/util_vec3_02.o\
				src/atambo/upscale_img.o\
				src/atambo/upscale_assign.o\
				src/atambo/render_scene.o\
				src/atambo/input.o\
				src/atambo/rotate_cam.o\
				src/atambo/rotate_obj.o\
				src/atambo/move.o\
				src/atambo/switch.o\
				src/atambo/color_switch.o\
				src/atambo/input_util.o\
				src/atambo/print_data.o\
				src/atambo/print_data_acl.o\
				src/atambo/obj_normal.o\
				src/atambo/hit_obj_01.o\
				src/atambo/hit_obj_02.o\
				src/atambo/ray.o\
				src/atambo/ray_color.o\
				src/atambo/hit_light.o\
				src/atambo/hit_obj_light.o\
				src/atambo/ft_sleep.o\
				src/atambo/ft_ftoa.o\
				src/atambo/export_scene.o\
				src/atambo/export_scene_acl.o\
				src/atambo/export_scene_obj.o\
				src/atambo/t_color.o

HEADERS		=	inc/miniRT.h\
				inc/miniRT_atambo.h\
				inc/miniRT_mchingi.h

NAME		=	miniRT
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g

SUBDIRS		=	./minilibx-linux\
				./libft
LFLAGS		=	\
				-Lminilibx-linux -l:libmlx_Linux.a\
				-L/usr/lib -lXext -lX11 -lm -lz\
				-Llibft -l:libft.a

all: $(SUBDIRS) $(NAME)

$(SUBDIRS):
	$(MAKE) -C $@

$(OBJECTS): $(HEADERS)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)
	for dir in $(SUBDIRS); do \
		make -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME)
	for dir in $(SUBDIRS); do \
		make -C $$dir fclean; \
	done

re: fclean all

.PHONY: all clean fclean $(SUBDIRS) re


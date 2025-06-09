# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <atambo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:55:11 by mchingi           #+#    #+#              #
#    Updated: 2025/06/09 16:17:28 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		=	\
				\
				src/miniRT.c\
				\
				src/mchingi/file_management.c\
				src/mchingi/fill_data_acl.c\
				src/mchingi/fill_data.c\
				src/mchingi/fill_obj_data.c\
				src/mchingi/scene_validations.c\
				src/mchingi/utils.c\
				src/mchingi/utils2.c\
				src/mchingi/print_debug.c\
				\
				src/atambo/minirt_error.c\
				src/atambo/exit_minirt.c\
				src/atambo/init.c\
				src/atambo/util_01.c\
				src/atambo/util_dbl.c\
				src/atambo/util_vec3_01.c\
				src/atambo/util_vec3_02.c\
				src/atambo/upscale_img.c\
				src/atambo/upscale_assign.c\
				src/atambo/render_scene.c\
				src/atambo/input.c\
				src/atambo/rotate.c\
				src/atambo/move.c\
				src/atambo/switch.c\
				src/atambo/color_switch.c\
				src/atambo/input_util.c\
				src/atambo/print_data.c\
				src/atambo/print_data_acl.c\
				src/atambo/obj_normal.c\
				src/atambo/hit_obj_01.c\
				src/atambo/hit_obj_02.c\
				src/atambo/ray.c\
				src/atambo/ray_color.c\
				src/atambo/hit_light.c\
				src/atambo/hit_obj_light.c\
				src/atambo/ft_sleep.c\
				src/atambo/ft_ftoa.c\
				src/atambo/export_scene.c\
				src/atambo/export_scene_acl.c\
				src/atambo/export_scene_obj.c\
				src/atambo/t_color.c\

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


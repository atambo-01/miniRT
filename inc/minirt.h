/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/05/02 01:44:16 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				MINIRT_H
# define			MINIRT_H

# include			<stdlib.h>
# include			<unistd.h>
# include			<math.h>
# include			<stdio.h>
# include			<errno.h>
# include			<fcntl.h>
#include			<string.h>

# include			"../minilibx-linux/mlx.h"

# define ESC		65307
# define UP			65363
# define DOWN		65361
# define LEFT		65362
# define RIGHT		65364
# define W_WIDTH	1080
# define W_HEIGHT	720
# define IM_WIDTH	1080
# define IM_HEIGHT	720
// # define IM_WIDTH	540
// # define IM_HEIGHT	360

typedef struct	s_vec3
{
    float x, y, z;
}				t_vec3;

typedef struct	s_obj t_obj;
typedef struct	s_obj
{
	char	type;
	t_vec3	center;
	t_vec3	dir;
	t_vec3	u;
	float	radius;
	float	len;
	int		color;
	t_obj	*next;
}				t_obj;
typedef struct	s_cam
{
    t_vec3	pos;
    t_vec3	dir;
    float	fov;
}				t_cam;
typedef struct	s_img
{
	void*	ptr;
	void*	addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_data
{
	void*	mlx;
	void*	win;
	int		fd;
	t_img	img;
	t_img	s_img;
	t_cam	cam;
	t_obj	*obj;
}				t_data;

// src/check_file.c
int 	ft_check_file(int ac, char **av);

// src/exit_minirt.c
void	ft_free_obj(t_obj *obj);
void	ft_quit_mlx(t_data *data);
void	ft_exit_minirt(t_data *data);

// ft_perror.c
int		ft_perror(char const *msg, int e);

// src/init.c
int 	ft_init_data(t_data *data, int fd);

// src/input.c
int		ft_key_hook(int keycode, t_data *data);
int		ft_mouse_hook(int button, int x, int y, t_data *data);

// src/intersect.c
float	ft_intersect_cube(t_vec3 origin, t_vec3 dir, t_obj *obj);
float	ft_intersect_plane(t_vec3 origin, t_vec3 dir, t_obj *obj);

// src/input_util.c
int		ft_close_window(t_data *data);

// print_data.c
int		ft_print_vec3(t_vec3 *vec);
int		ft_print_cam(t_cam *cam);
int		ft_print_obj(t_obj *obj);
int		ft_print_data(t_data *data);

// src/render_scene.c
float	ft_intersect_sphere(t_vec3 orig, t_vec3 dir, t_vec3 center, float radius);
void	ft_render_scene(t_data *data);

// src/upscale_img.c
void	ft_fill_color(t_data *data, int color);
void	ft_fill_tiled(t_img *img, t_data *data);
void	ft_upscale_img(t_data *data);

// src/util.c
void 	ft_setvec3(t_vec3 *v, float a, float b, float c);
void	ft_pixel_put_img(t_img *img, int x, int y, int color);
float	ft_dot(t_vec3 a, t_vec3 b);
void	ft_normalize(t_vec3 *v);

#endif

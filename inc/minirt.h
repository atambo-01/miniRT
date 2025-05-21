/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/05/21 19:30:51 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				MINIRT_H
# define			MINIRT_H

# ifndef 			BUFFER_SIZE
#  define 			BUFFER_SIZE 42
# endif

# include			<stdlib.h>
# include			<unistd.h>
# include			<math.h>
# include			<stdio.h>
# include			<errno.h>
# include			<fcntl.h>
#include			<string.h>

// remove these libs
#include <sys/time.h>

# include			"../minilibx-linux/mlx.h"
# include			"../libft/libft.h"

# define UPSCALE	1
# define ESC		65307
# define UP			65363
# define DOWN		65361
# define LEFT		65362
# define RIGHT		65364
# define W_WIDTH	1080
# define W_HEIGHT	720
# define IM_WIDTH	540
# define IM_HEIGHT	360
// # define IM_WIDTH	1080
// # define IM_HEIGHT	720

# define NUM_1
# define NUM_PLUS

// error msgs
# define ERR_PARAM "Too many params, only need one file_path\n"
# define ERR_NEED_FILE "Need a file_path as param\n"
# define ERR_ALIGHT "Bad ambient light formating\n"


typedef struct	s_upscale
{
	float	src_x;
	float	src_y;
	float	fx;
	float	fy;
	float	r;
	float	g;
	float	b;
	int		*p00;
	int		*p10;
	int		*p01;
	int		*p11;
	int		r00;
	int		g00;
	int		b00;
	int		r10;
	int		g10;
	int		b10;
	int		r01;
	int		g01;
	int		b01;
	int		r11;
	int		g11;
	int		b11;
} t_upscale;

typedef struct	s_neighbor
{
	float	r_sum;
	float	g_sum;
	float	b_sum;
	int		count;
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		nx;
	int		ny;
	int		*p;
}t_neighbor;
typedef struct	s_vec3
{
	float x, y, z;
}				t_vec3;

typedef struct	s_obj t_obj;
typedef struct	s_obj
{
	char	*type;
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

typedef struct	s_light
{
	t_vec3	center;
	float	ratio;
	int		color;
}				t_light;

typedef struct	s_alight
{
	float	ratio;
	int		color;
}				t_alight;

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
	void*			mlx;
	void*			win;
	int				fd;
	t_img			img;
	t_img			s_img;
	t_cam			cam;
	t_obj			*obj;
	t_obj			*curr;
	t_light			light;
	t_alight		alight;
	char			*err;
	struct timeval	start;
	struct timeval	end;
}				t_data;

typedef struct	s_hit
{
	float	t;
	t_obj	*obj;
}				t_hit;

typedef struct	s_ray
{
	t_vec3	o;
	t_vec3	dir;
	float   tan_half_fov;
	float   view_width;
	float	asp_ratio;
	float   view_height;
	float	u;
	float	v;
}				t_ray;

// src/check_file.c
int 	ft_check_file(int ac, char **av);

// src/exit_minirt.c
void	ft_free_obj(t_obj *obj);
void	ft_quit_mlx(t_data *data);
int		ft_exit_minirt(t_data *data);

// src/init.c
int		ft_init_obj(t_data *data);
int		ft_init_cam(t_data *data);
int 	ft_init_data(t_data *data, int fd);

// src/input.c
int		ft_key_hook(int keycode, t_data *data);
void	ft_switch_obj(t_data *data, int x, int y);
int		ft_mouse_hook(int button, int x, int y, t_data *data);

// src/input_util.c
int		ft_close_window(t_data *data);

// src/minirt_error.c
int		ft_strlen(char const *str);
int		ft_minirt_error(char const *msg, int e);

// print_data.c
int		ft_print_vec3(t_vec3 *vec);
int		ft_print_cam(t_cam *cam);
int		ft_print_obj(t_obj *obj);
int		ft_print_data(t_data *data);
// ray.c
void	ft_init_ray(t_data *data,int x, int y, t_ray *ray);
void	ft_calc_ray(t_data *data,int x, int y, t_ray *ray);

// src/render_scene.c
t_hit	*ft_calc_hit(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj);
void	ft_render_scene(t_data *data);
void ft_render_and_upscale(t_data *data, int upscale);

//src/upscale_assign.c
void	ft_assign_src_coords(t_data *data, t_upscale *up, int x, int y);
void	ft_assign_corner_pixels(t_data *data, t_upscale *up);
void	ft_assign_rgb_values(t_upscale *up);
void	ft_init_neighbor(t_upscale *up, t_neighbor *nb);

// src/upscale_img.c
void	ft_upscale_img(t_data *data);

// src/util.c
void 	ft_setvec3(t_vec3 *v, float a, float b, float c);
void	ft_pixel_put_img(t_img *img, int x, int y, int color);
float	ft_dot(t_vec3 a, t_vec3 b);
void	ft_normalize(t_vec3 *v);
float	ft_get_speed(struct timeval start, struct timeval end);

// src/get_next_line.c && src/get_next_line_utils.c
char	*ft_strchr_1(char *s, int c);
char	*ft_strjoin_1(char *str, char *buffer);
char	*ft_strjoin_2(char *new_str, char *str, char *buffer);
char	*ft_getline(char *str);
void	ft_free(char **str, char *buffer);
char	*ft_substr_1(char *str, int start, int len_str);
char	*ft_get_next_line(int fd);

// src/hit.c
float	ft_hit_cube(t_vec3 origin, t_vec3 dir, t_obj *obj);
float	ft_hit_plane(t_vec3 origin, t_vec3 dir, t_obj *obj);
float	ft_hit_sphere(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj);
float	ft_hit_cylinder(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj);

#endif

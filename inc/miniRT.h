/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/07 07:39:53 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//builtin libs
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<math.h>
# include	<fcntl.h>
# include	<X11/keysym.h>
# include	<errno.h>
# include	<stdbool.h>
# include	<limits.h>

// costum libs
# include	"../libft/libft.h"
# include	"../minilibx-linux/mlx.h"

// remove these libs before sending
# include	<sys/time.h>

# define EPSILON	1e-6
# define KAPPA		0.0001
# define GAMMA		0.0009

# define UPSCALE	1
# define W_WIDTH	1080
# define W_HEIGHT	720
// # define IM_WIDTH	540
// # define IM_HEIGHT	360
# define IM_WIDTH	1080
# define IM_HEIGHT	720

# define NUM_1
# define NUM_PLUS

// keys
# define TAB		65289
# define SHIFT		65505
# define ESC		65307
# define UP			65363
# define DOWN		65361
# define LEFT		65362
# define RIGHT		65364
# define NUMPAD_1	65436
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_9	65434

// error msgs
# define E_READFILE		"Error reading file\n"
# define E_EXTENSION	"Wrong file extension, need a '.rt' file\n"
# define E_PARAM		"Too many params, only need one file_path\n"
# define E_NEEDFILE		"Need a file_path as param\n"
# define E_ACL			"Duplicate or missing ACL element in scene\n"
# define E_MISS_ACL		"Missing ACL element in scene\n"
# define E_SCENE_DATA	"Invalid or missing identifier or number of tokens\n"
# define E_EXPORT		"Export failed, could not create './saved_scene'\n"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;
typedef struct s_upscale
{
	double	src_x;
	double	src_y;
	double	fx;
	double	fy;
	double	r;
	double	g;
	double	b;
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
}				t_upscale;

typedef struct s_neighbor
{
	double	r_sum;
	double	g_sum;
	double	b_sum;
	int		count;
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		nx;
	int		ny;
	int		*p;
}				t_neighbor;

typedef struct s_img
{
	void*	ptr;
	void*	addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}		t_cam;

typedef struct s_obj	t_obj;
typedef struct s_obj
{
	char	*type;
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	u;
	double	radius;
	double	len;
	t_color	color;
	t_obj	*next;
}				t_obj;

typedef struct s_light
{
	t_vec3	pos;
	double	radius;
	double	ratio;
	t_color	color;
}				t_light;

typedef struct s_alight
{
	double	ratio;
	t_color	color;
}				t_alight;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				fd;
	t_img			img;
	t_img			s_img;
	t_cam			cam;
	t_obj			*obj;
	t_obj			*curr;
	t_light			*curr_light;
	t_light			light;
	t_alight		alight;
	char			*err;
	struct timeval	start;
	struct timeval	end;
	int				focus;
}				t_data;

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	dir;
	//----------------------
	double	tan_half_fov;
	double	view_height;
	double	u;
	double	v;
	//----------------------
	double	t;
	double	d;
	t_vec3	p;
	t_color	color;
	t_vec3	n;
	t_vec3	l;
	t_obj	*obj;
	t_light	*lum;
}				t_ray;

typedef struct s_cy
{
	t_vec3	oc;
	double	dda;
	double	ocda;
	t_vec3	proj;
	t_vec3	oc_proj;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;
	double	z;
}				t_cy;

#endif
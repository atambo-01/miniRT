/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/29 13:44:04 by atambo           ###   ########.fr       */
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
# define KAPPA		0.001
# define GAMMA		0.0009

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
# define E_READFILE		"Error reading file\n"
# define E_EXTENSION	"Wrong file extension, need a '.rt' file\n"
# define E_PARAM		"Too many params, only need one file_path\n"
# define E_NEEDFILE		"Need a file_path as param\n"
# define E_ACL			"Duplicate or missing ACL element in scene\n"
# define E_MISS_ACL		"Missing ACL element in scene\n"
# define E_SCENE_DATA	"Invalid or missing identifier\n"
# define E_EXPORT		"Export failed, could not create './saved_scene'\n"

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;
typedef struct	s_upscale
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

typedef struct	s_neighbor
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

typedef struct	s_img
{
	void*	ptr;
	void*	addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_cam
{
	// char	id; // C
	t_vec3	pos; // x, y, z coordinates of the viewpoint
	t_vec3	dir; // 3D normalized orientation vector, in the range [-1,1] for each x, y, z axis
	double		fov; // Horizontal field of view in degrees in the range [0,180]
}		t_cam;


//--------  these structs need to be fixed and joined  -------- //


typedef struct	s_obj t_obj;
typedef struct	s_obj
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

typedef struct	s_light
{
	t_vec3	pos;
	double	radius;
	double	ratio;
	t_color	color;
}				t_light;

typedef struct	s_alight
{
	double	ratio;
	t_color	color;
}				t_alight;

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
	t_light			*curr_light;
	t_light			light;
	t_alight		alight;
	char			*err;
	struct timeval	start;
	struct timeval	end;
	int				focus;
}				t_data;

//=========================================================


// typedef struct s_amblight
// {
// 	// char	id; // A 
// 	double	light_ratio; // ambient lighting ratio in the range [0.0,1.0]
// 	t_color	color;
// }		t_amblight;


// typedef struct s_light
// {
// 	// char	id; // L
// 	t_vec3	pos; // x, y, z coordinates of the light point
// 	double	bright_ratio; // the light brightness ratio in the range [0.0,1.0]
// 	t_color	color;
// }		t_light;

// typedef struct s_sphere
// {
// 	char			id; // sp
// 	t_vec3			center; // x, y, z coordinates of the sphere center
// 	float			diameter; // the sphere diameter
// 	t_color			colors;
// 	struct s_sphere	*next; // if there are multiple sp
// }		t_sphere;

// typedef struct s_plane
// {
// 	char			id; // pl
// 	t_vec3			pos; // x, y, z coordinates of the center of the cylinder
// 	t_vec3			dir; // 3D normalized normal vector, in the range [-1,1] for each x, y, z axis
// 	t_color			colors;
// 	struct s_plane	*next; // if there are multiple pl
// }		t_plane;

// typedef struct s_cylinder
// {
// 	char				id; // cy
// 	t_vec3				center; // x, y, z coordinates of the center of the cylinder
// 	t_vec3				dir; // 3D normalized vector of axis of cylinder, in the range [-1,1] for each x, y, z axis
// 	float				diameter; // the cylinder diameter
// 	float				height; // the cylinder height
// 	t_color				colors;
// 	struct s_cylinder	*next;
// }	t_cylinder;

// typedef struct s_obj
// {
// 	t_sphere	*sp;
// 	t_plane		*pl;
// 	t_cylinder	*cy;
// }		t_obj;

//-----------------------------------------------------

typedef struct	s_hit
{
	double	t;
	double	d;
	t_vec3	p;
	t_color	color;
	t_vec3	u;
	t_vec3	n;
	t_obj	*obj;
}				t_hit;

typedef struct	s_ray
{
	t_vec3	o;
	t_vec3	dir;
	double   tan_half_fov;
	double   view_height;
	double	u;
	double	v;
}				t_ray;

# endif
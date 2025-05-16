/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/16 17:03:17 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#include <errno.h>
#include <stdbool.h>

// -----------------------------------------------------------

typedef struct s_img
{
	void	*init;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*init;
	void	*window;
}	t_mlx;

// -----------------------------------------------------------

typedef struct	s_vec3
{
	float x, y, z;
}				t_vec3;

typedef struct s_color
{
	int R, B, G;
}		t_color;

typedef struct s_amblight
{
	char	id; // A
	float	light_ratio; // ambient lighting ratio in the range [0.0,1.0]
	t_color	color; // R, G, B colors in the range [0-255]
} 		t_amblight;

typedef struct s_cam
{
	char	id; // C
	t_vec3	pos; // x, y, z coordinates of the viewpoint
	t_vec3	dir; // 3D normalized orientation vector, in the range [-1,1] for each x, y, z axis
	int		FOV; // Horizontal field of view in degrees in the range [0,180]

}		t_cam;

typedef struct s_light
{
	char	id; // L
	t_vec3	pos; // x, y, z coordinates of the light point
	float	bright_ratio; // the light brightness ratio in the range [0.0,1.0]
	
}		t_light;

typedef struct s_scene
{
	t_amblight	*ambient_light;
	t_cam		*cam;
	t_light		*light;
}			t_scene;

typedef struct s_sphere
{
	char	id; // sp
	t_vec3	center; // x, y, z coordinates of the sphere center
	float	diameter; // the sphere diameter
	t_color colors; // R, G, B colors in the range [0-255]
	struct s_sphere *next; // if there are multiple sp
}		t_sphere;

typedef struct s_plane
{
	char	id; // pl
	t_vec3	pos; // x, y, z coordinates of the center of the cylinder
	t_vec3	dir; // 3D normalized normal vector, in the range [-1,1] for each x, y, z axis
	t_color	colors; // R,G,B colors in the range [0-255]
	struct s_plane *next; // if there are multiple pl
}		t_plane;

typedef struct s_cylinder
{
	char	id; // cy
	t_vec3	center; // x, y, z coordinates of the center of the cylinder
	t_vec3	dir; // 3D normalized vector of axis of cylinder, in the range [-1,1] for each x, y, z axis
	float	diameter; // the cylinder diameter
	float	height; // the cylinder height
	t_color	colors; // R, G, B colors in the range [0,255]
	struct s_cylinder *next;
}	t_cylinder;

typedef struct s_obj
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}		t_obj;

typedef struct s_data
{
	t_scene scenario;
	t_obj	objects;
}		t_data;


// --------------------------------------------------------------------/



// ----------------------- FILE MANAGEMENT --------------------------------/
int		open_file(char *file_name);
int		file_management(char *file_name, t_data *data);
int		validate_scene(char **arr, int arr_size);
int		fill_data(char **scene, t_data *data);


// ------------------------- MLX UTILS -----------------------------------/
int		input_keys(int keysym, t_mlx *data);
void	ft_mlx_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_pixels(t_img *img, int x, int y, int size, int color);
void    draw_gradient(t_img *img, int width, int height);

// --------------------------- UTILS ----------------------------------/
void	ft_error(char *str);
void	ft_free_array(char **array);
int		ft_array_size(char **arr);
char	**remove_char(char **array);


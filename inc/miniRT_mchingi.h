/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_mchingi.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 14:01:39 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MCHINGI_H
# define MINIRT_MCHINGI_H

# include	"./miniRT.h"

// ----------------------- FILE MANAGEMENT --------------------------------/
int		open_file(char *file_name);
int		file_management(char *file_name, t_data *data);
int		validate_scene(char **arr, int arr_size);
int		fill_data(char **scene, t_data *data);

int		fill_color(char *color_data, int *color);
int		fill_coordinate(char *coordinate_data, t_vec3 *coordinates);
int		fill_normalized_vector(char *data, t_vec3 *direction);

int	sphere_data(t_obj *obj, char **data);
int	plane_data(t_obj *obj, char **data);
int	cylinder_data(t_obj *obj, char **data);

// ------------------------- MLX UTILS -----------------------------------/
// int		input_keys(int keysym, t_mlx *data);
// void	ft_mlx_put_pixel(t_img *img, int x, int y, int color);
// void	ft_put_pixels(t_img *img, int x, int y, int size, int color);
// void    draw_gradient(t_img *img, int width, int height);

// --------------------------- UTILS ----------------------------------/
void	ft_error(char *str);
// double	ft_atof2(char *str);
char	**remove_char(char **array);


#endif

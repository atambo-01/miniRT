/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_mchingi.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/14 15:54:12 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MCHINGI_H
# define MINIRT_MCHINGI_H

# include "./miniRT.h"

// ----------------------- FILE MANAGEMENT --------------------------------/
int		open_file(char *file_name);
int		file_management(char *file_name, t_data *data);
int		validate_scene(char **arr, int arr_size);
int		fill_data(char **scene, t_data *data);

int		fill_color(char *color_data, t_color *color);
int		fill_coordinate(char *coordinate_data, t_vec3 *coordinates);
int		fill_normalized_vector(char *data, t_vec3 *direction);

int		ambient_data(t_alight *amb, char **data);
void	ft_cam_right(t_cam *cam);
void	ft_cam_up(t_cam *cam);
int		camera_data(t_cam *cam, char **data);
int		light_data(t_light *light, char **data);

int		sphere_data(t_data *data, char **data_line);
int		plane_data(t_data *data, char **data_line);
int		cylinder_data(t_data *data, char **data_line);

// --------------------------- UTILS ----------------------------------/
void	ft_error(char *str);
char	**remove_char(char **array);
int		ft_valid_double(char *token);
int		check_coord_tokens(char **xyz);
int		ft_check_filename(char *filename);

// --------------------------- DEBUG ----------------------------------/
void	print_debug_sp(t_obj *obj);
void	print_debug_pl(t_obj *obj);
void	print_debug_cy(t_obj *obj);
void	print_debug_obj(t_obj *obj);
void	print_debug_info(t_data data);

#endif

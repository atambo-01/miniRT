/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_acl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:04 by atambo            #+#    #+#             */
/*   Updated: 2025/07/09 13:54:15 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	fill_lum_intensity(double *ratio, char *str)
{
	if (!str)
		return (0);
	if (ft_valid_double(str))
		*ratio = ft_atof(str);
	else
		*ratio = -42.0;
	if (*ratio < 0.0 || *ratio > 1.0)
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_INTENS, 1);
		return (0);
	}
	return (1);
}

int	ambient_data(t_alight *amb, char **data)
{
	if (ft_array_size(data) < 3)
		return (0);
	if (!fill_lum_intensity(&(amb->ratio), data[1])
		|| !fill_color(data[2], &amb->color))
		return (0);
	return (1);
}

void	ft_cam_local_vectors(t_cam *cam)
{
	t_vec3	world_up;
	t_vec3	alt_up;
	double	aprox_1;
	double	aprox_2;

	world_up = (t_vec3){0.0, 1.0, 0.0};
	alt_up = (t_vec3){0.0, 0.0, 1.0};
	aprox_1 = fabs(ft_dot(cam->dir, world_up));
	if (ft_cmp_dbl(aprox_1, ">", 0.999))
	{
		aprox_2 = fabs(ft_dot(cam->dir, alt_up));
		if (ft_cmp_dbl(aprox_2, "<", aprox_1))
			world_up = alt_up;
		else
			world_up = (t_vec3){1.0, 0.0, 0.0};
	}
	cam->right = ft_cross(world_up, cam->dir);
	ft_normalize(&cam->right);
	cam->up = ft_cross(cam->dir, cam->right);
	ft_normalize(&cam->up);
}

int	camera_data(t_cam *cam, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &cam->pos))
		return (0);
	if (!fill_normalized_vector(data[2], &cam->dir))
		return (0);
	if (fill_fov(cam, data, 3))
		return (0);
	ft_cam_local_vectors(cam);
	return (1);
}

int	light_data(t_light *light, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &light->pos))
		return (0);
	light->ratio = ft_atof(data[2]);
	if (light->ratio < 0.0 || light->ratio > 1.0)
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_INTENS, 1);
		return (0);
	}
	if (fill_color(data[3], &light->color) == 0)
		return (0);
	return (1);
}

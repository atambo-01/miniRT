/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_acl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:04 by atambo            #+#    #+#             */
/*   Updated: 2025/06/09 17:12:38 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ambient_data(t_alight *amb, char **data)
{
	if (ft_array_size(data) < 3)
		return (0);
	amb->ratio = ft_atof(data[1]);
	if (amb->ratio < 0.0 || amb->ratio > 1.0)
		return (0);
	if (!fill_color(data[2], &amb->color))
		return (0);
	return (1);
}

void	ft_cam_right(t_cam *cam)
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
}

void	ft_cam_up(t_cam *cam)
{
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
	cam->fov = atof(data[3]);
	if (cam->fov < 0 || cam->fov > 180)
		return (0);
	ft_cam_right(cam);
	ft_cam_up(cam);
	return (1);
}

int	light_data(t_light *light, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &light->pos))
		return (0);
	light->ratio = atof(data[2]);
	if (light->ratio < 0.0 || light->ratio > 1.0)
		return (0);
	if (fill_color(data[3], &light->color) == 0)
		return (0);
	light->radius = 1.0;
	return (1);
}
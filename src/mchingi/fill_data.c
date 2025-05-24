/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 17:36:44 by atambo           ###   ########.fr       */
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
	light->radius = 1;
	return (1);
}

int	parse_line(char *line, t_data *data)
{
	int		success;
	char	**tokens;

	success = 0;
	tokens = ft_split2(line);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		success = ambient_data(&data->alight, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		success = camera_data(&data->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		success = light_data(&data->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		success = plane_data(data, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		success = sphere_data(data, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		success = cylinder_data(data, tokens);
	ft_free_array(tokens);
	return (success);
}

int	fill_data(char **scene, t_data *data)
{
	int		i;

	i = -1;
	while (scene[++i])
	{
		if (!parse_line(scene[i], data))
		{
			printf("Error in line %d: %s\n", (i + 1), scene[i]); // Debug
			ft_free_array(scene);
			return (0);
		}
	}
	ft_free_array(scene);
	return (1);
}

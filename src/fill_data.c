/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/22 17:26:02 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	ambient_data(t_amblight *amb, char **data)
{
	if (ft_array_size(data) < 3)
		return (0);
	amb->light_ratio = ft_atof(data[1]);
	if (amb->light_ratio < 0.0 || amb->light_ratio > 1.0)
		return (0);
	return (fill_color(data[2], &amb->color));
}

int	camera_data(t_cam *cam, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &cam->pos))
		return (0);
	if (!fill_normalized_vector(data[2], &cam->dir))
		return (0);
	cam->fov = atoi(data[3]);
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
	light->bright_ratio = atof(data[2]);
	if (light->bright_ratio < 0.0 || light->bright_ratio > 1.0)
		return (0);
	return (fill_color(data[3], &light->color));
}

int	parse_line(char *line, t_data *data)
{
	int		success;
	char	**tokens;

	success = 0;
	tokens = ft_split2(line);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		success = ambient_data(&data->ambient_light, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		success = camera_data(&data->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		success = light_data(&data->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		success = plane_data(&data->objects, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		success = sphere_data(&data->objects, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		success = cylinder_data(&data->objects, tokens);
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

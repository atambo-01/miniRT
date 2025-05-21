/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/21 12:09:42 by mchingi          ###   ########.fr       */
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
	return(fill_color(data[2], &amb->color));
}

int	camera_data(t_cam *cam, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &cam->pos))
		return (0);
	if (!fill_normalized_orientation(data[2], &cam->dir))
		return (0);
	cam->fov = atoi(data[3]);
	if (cam->fov < 0 || cam->fov > 180)
		return (0);
	return (1);
}

int	light_data(t_light *light, char **data)
{
	if (ft_array_size(data) < 3)
		return (0);
	if (!fill_coordinate(data[1], &light->pos))
		return (0);
	light->bright_ratio = atof(data[2]);
	if (light->bright_ratio < 0.0 || light->bright_ratio > 1.0)
		return (0);
	return (1);
}

int	parse_line(char *line, t_data *data)
{
	int	success;
	char **tokens;

	success = 0;
	tokens = ft_split2(line);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		success = ambient_data(&data->scenario.ambient_light, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		success = camera_data(&data->scenario.cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		success = light_data(&data->scenario.light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return(printf("Element %s parsed\n", tokens[0])); // success = 1;
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return(printf("Element %s parsed\n", tokens[0])); // success = 1;
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return(printf("Element %s parsed\n", tokens[0])); // success = 1;
	ft_free_array(tokens);
	return (success);
}

int	fill_data(char **scene, t_data *data)
{
	int		i;

	i = -1;
	while(scene[++i])
	{
		if (!parse_line(scene[i], data))
		{
			printf("Error in line %d: %s\n", (i + 1), scene[i]);
			return (0);
		}
	}
	return (1);
}

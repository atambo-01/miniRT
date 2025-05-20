/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/20 20:00:03 by mchingi          ###   ########.fr       */
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

int	parse_line(char *line, t_data *data)
{
	int	success;
	char **tokens;

	success = 0;
	tokens = ft_split2(line);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		success = ambient_data(&data->scenario.ambient_light, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		success = 1;
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		success = 1;
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		success = 1;
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		success = 1;
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		success = 1;
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

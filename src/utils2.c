/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:08:11 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/20 19:59:57 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/miniRT.h"

int	color_range(int r, int b, int g)
{
	if ((r >= 0 && r <= 255) && (b >= 0 && b <= 255) && (g >= 0 && g <= 255))
		return (1);
	return (0);
}

int	fill_color(char *color_data, t_color *colors)
{
	char	**rbg;

	if (!color_data)
		return (0);
	rbg = ft_split(color_data, ',');
	if (!rbg || ft_array_size(rbg) != 3)
	{
		ft_free_array(rbg);
		return (0);
	}
	colors->r = ft_atoi(rbg[0]);
	colors->b = ft_atoi(rbg[1]);
	colors->g = ft_atoi(rbg[2]);
	ft_free_array(rbg);
	return (color_range(colors->r, colors->b, colors->g));
}

int	fill_coordinate(char *coordinate_data, t_vec3 *coordinates)
{
	char	**xyz;

	if (!coordinate_data)
		return (0);
	xyz = ft_split(coordinate_data, ',');
	if (!xyz || ft_array_size(xyz) != 3)
	{
		ft_free_array(xyz);
		return (0);
	}
	coordinates->x = ft_atof(xyz[0]);
	coordinates->y = ft_atof(xyz[1]);
	coordinates->z = ft_atof(xyz[2]);
	ft_free_array(xyz);
	return (1);
}

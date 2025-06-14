/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:08:11 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/15 00:46:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	color_range(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return (1);
	return (0);
}

int	fill_color(char *color_data, t_color *color)
{
	char	**rgb;

	if (!color_data)
		return (0);
	*color = (t_color){0, 0, 0};
	rgb = ft_split(color_data, ',');
	if (!rgb || ft_array_size(rgb) != 3
		|| !ft_valid_double(rgb[0])
		|| !ft_valid_double(rgb[1])
		|| !ft_valid_double(rgb[2])
		|| !color_range(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2])))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_COLOR, 1);
		ft_free_array(rgb);
		return (0);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	ft_free_array(rgb);
	return (1);
}

int	fill_coordinate(char *coordinate_data, t_vec3 *coordinates)
{
	char	**xyz;

	if (!coordinate_data)
		return (0);
	xyz = ft_split(coordinate_data, ',');
	if (!xyz || ft_array_size(xyz) != 3 || !check_coord_tokens(xyz))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_COOR, 1);
		ft_free_array(xyz);
		return (0);
	}
	coordinates->x = ft_atof(xyz[0]);
	coordinates->y = ft_atof(xyz[1]);
	coordinates->z = ft_atof(xyz[2]);
	ft_free_array(xyz);
	return (1);
}

int	threed_n_o_range(double x, double y, double z)
{
	double	tmp;

	tmp = x + y + z;
	if (ft_cmp_dbl(tmp, "=", 0.0)
		|| ft_cmp_dbl(fabs(x), ">", 1)
		|| ft_cmp_dbl(fabs(y), ">", 1)
		|| ft_cmp_dbl(fabs(z), ">", 1))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_VNORM, 1);
		if (ft_cmp_dbl(tmp, "=", 0.0))
		{
			ft_perror("\n", 1);
			ft_perror(E_VZERO, 1);
		}
		return (0);
	}
	return (1);
}

int	fill_normalized_vector(char *data, t_vec3 *direction)
{
	char	**xyz;

	if (!data)
		return (0);
	xyz = ft_split(data, ',');
	if (!xyz || ft_array_size(xyz) != 3 || !check_coord_tokens(xyz))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_VECT, 1);
		ft_free_array(xyz);
		return (0);
	}
	direction->x = ft_atof(xyz[0]);
	direction->y = ft_atof(xyz[1]);
	direction->z = ft_atof(xyz[2]);
	ft_free_array(xyz);
	return (threed_n_o_range(direction->x, direction->y, direction->z));
}

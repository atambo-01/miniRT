/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:38:15 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/21 19:30:21 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/miniRT.h"

// ----------- TO DO --------------- /

// Verify if the flag is on then iterate throughout the list and add a new node
//		This can be done in an aux

int	sphere_data(t_sphere *sp, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &sp->center))
		return (0);
	sp->diameter = atof(data[2]);
	if (sp->diameter < 0)
		return (0);
	return (fill_color(data[3], &sp->colors));
}

int	plane_data(t_plane *pl, char **data)
{
	if (ft_array_size(data) < 4)
		return (0);
	if (!fill_coordinate(data[1], &pl->pos))
		return (0);
	if (!fill_normalized_vector(data[2], &pl->dir))
		return (0);
	return (fill_color(data[3], &pl->colors));
}

int	cylinder_data(t_cylinder *cy, char **data)
{
	if (ft_array_size(data) < 6)
		return (0);
	if (!fill_coordinate(data[1], &cy->center))
		return (0);
	if (!fill_normalized_vector(data[2], &cy->dir))
		return (0);
	cy->diameter = atof(data[3]);
	cy->height = atof(data[4]);
	if (cy->diameter < 0 || cy->height < 0)
		return (0);
	return (fill_color(data[5], &cy->colors));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:38:15 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/22 16:41:31 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	obj_return(void *ptr)
{
	free(ptr);
	return (0);
}

int	sphere_data(t_obj *obj, char **data)
{
	t_sphere	*new_sphere;

	if (ft_array_size(data) < 4)
		return (0);
	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (0);
	new_sphere->id = 's';
	if (!fill_coordinate(data[1], &new_sphere->center))
		return (obj_return(new_sphere));
	new_sphere->diameter = atof(data[2]);
	if (new_sphere->diameter < 0)
		return (obj_return(new_sphere));
	if (!fill_color(data[3], &new_sphere->colors))
		return (obj_return(new_sphere));
	new_sphere->next = obj->sp;
	obj->sp = new_sphere;
	return (1);
}

int	plane_data(t_obj *obj, char **data)
{
	t_plane	*new_plane;

	if (ft_array_size(data) < 4)
		return (0);
	new_plane = (t_plane *)malloc(sizeof(t_plane));
	if (!new_plane)
		return (0);
	new_plane->id = 'p';
	if (!fill_coordinate(data[1], &new_plane->pos))
		return (obj_return(new_plane));
	if (!fill_normalized_vector(data[2], &new_plane->dir))
		return (obj_return(new_plane));
	if (!fill_color(data[3], &new_plane->colors))
		return (obj_return(new_plane));
	new_plane->next = obj->pl;
	obj->pl = new_plane;
	return (1);
}

int	cylinder_data(t_obj *obj, char **data)
{
	t_cylinder	*new_cylinder;

	if (ft_array_size(data) < 6)
		return (0);
	new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (0);
	if (!fill_coordinate(data[1], &new_cylinder->center))
		return (obj_return(new_cylinder));
	if (!fill_normalized_vector(data[2], &new_cylinder->dir))
		return (obj_return(new_cylinder));
	new_cylinder->diameter = atof(data[3]);
	new_cylinder->height = atof(data[4]);
	if (new_cylinder->diameter < 0 || new_cylinder->height < 0)
		return (obj_return(new_cylinder));
	if (!fill_color(data[5], &new_cylinder->colors))
		return (obj_return(new_cylinder));
	new_cylinder->next = obj->cy;
	obj->cy = new_cylinder;
	return (1);
}

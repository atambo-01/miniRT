/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:38:15 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 16:01:41 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_mchingi.h"


int	obj_return(void *ptr)
{
	free(ptr);
	return (0);
}

int	sphere_data(t_obj *obj, char **data)
{
	t_obj	*new_sphere;

	if (ft_array_size(data) < 4)
		return (0);
	new_sphere = (t_obj *)malloc(sizeof(t_obj));
	if (!new_sphere)
		return (0);
	new_sphere->type = ft_strdup(data[0]);
	if (!fill_coordinate(data[1], &new_sphere->pos))
		return (obj_return(new_sphere));
	new_sphere->radius = atof(data[2]) / 2;
	if (new_sphere->radius < 0)
		return (obj_return(new_sphere));
	if (!fill_color(data[3], &new_sphere->color))
		return (obj_return(new_sphere));
	new_sphere->next = NULL;
	obj = new_sphere;
	return (1);
}

int	plane_data(t_obj *obj, char **data)
{
	t_obj	*new_plane;

	if (ft_array_size(data) < 4)
		return (0);
	new_plane = (t_obj *)malloc(sizeof(t_obj));
	if (!new_plane)
		return (0);
	new_plane->type = ft_strdup(data[0]);
	if (!fill_coordinate(data[1], &new_plane->pos))
		return (obj_return(new_plane));
	if (!fill_normalized_vector(data[2], &new_plane->dir))
		return (obj_return(new_plane));
	if (!fill_color(data[3], &new_plane->color))
		return (obj_return(new_plane));
	new_plane->next = NULL;
	obj = new_plane;
	return (1);
}

int	cylinder_data(t_obj *obj, char **data)
{
	t_obj	*new_cylinder;

	if (ft_array_size(data) < 6)
		return (0);
	new_cylinder = (t_obj *)malloc(sizeof(t_obj));
	if (!new_cylinder)
		return (0);
	new_cylinder->type = ft_strdup(data[0]);
	if (!fill_coordinate(data[1], &new_cylinder->pos))
		return (obj_return(new_cylinder));
	if (!fill_normalized_vector(data[2], &new_cylinder->dir))
		return (obj_return(new_cylinder));
	new_cylinder->radius = atof(data[3]);
	new_cylinder->len = atof(data[4]);
	if (new_cylinder->radius < 0 || new_cylinder->len < 0)
		return (obj_return(new_cylinder));
	if (!fill_color(data[5], &new_cylinder->color))
		return (obj_return(new_cylinder));
	new_cylinder->next = NULL;
	obj = new_cylinder;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:38:15 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/26 16:29:02 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	obj_return(t_data *data, void *ptr)
{
	void*	temp;

	free(ptr);
	ft_free_obj(data->obj);
	return (0);
}

void put_obj_tail(t_data *data, t_obj *obj)
{
	t_obj *temp;

	if (!data->obj)
		data->obj = obj;
	else
	{
		temp = data->obj;
		while(temp->next)
			temp = temp->next;
		temp->next = obj;
	}
}

int	sphere_data(t_data *data, char **data_line)
{
	t_obj	*new_sphere;

	if (ft_array_size(data_line) < 4)
		return (0);
	new_sphere = (t_obj *)malloc(sizeof(t_obj));
	if (!new_sphere)
		return (0);
	new_sphere->type = ft_strdup(data_line[0]);
	if (!fill_coordinate(data_line[1], &new_sphere->pos))
		return (obj_return(data, new_sphere));
	new_sphere->radius = atof(data_line[2]) / 2;
	if (new_sphere->radius < 0)
		return (obj_return(data, new_sphere));
	if (!fill_color(data_line[3], &new_sphere->color))
		return (obj_return(data, new_sphere));
	new_sphere->next = NULL;
	put_obj_tail(data, new_sphere);
	return (1);
}

int	plane_data(t_data *data, char **data_line)
{
	t_obj	*new_plane;

	if (ft_array_size(data_line) < 4)
		return (0);
	new_plane = (t_obj *)malloc(sizeof(t_obj));
	if (!new_plane)
		return (0);
	new_plane->type = ft_strdup(data_line[0]);
	if (!fill_coordinate(data_line[1], &new_plane->pos))
		return (obj_return(data, new_plane));
	if (!fill_normalized_vector(data_line[2], &new_plane->dir))
		return (obj_return(data, new_plane));
	new_plane->u = ft_vec3_orthogonal(new_plane->dir);
	if (!fill_color(data_line[3], &new_plane->color))
		return (obj_return(data, new_plane));
	new_plane->next = NULL;
	new_plane->radius = 0;
	put_obj_tail(data, new_plane);
	return (1);
}

int	cylinder_data(t_data *data, char **data_line)
{
	t_obj	*new_cylinder;

	if (ft_array_size(data_line) < 6)
		return (0);
	new_cylinder = (t_obj *)malloc(sizeof(t_obj));
	if (!new_cylinder)
		return (0);
	new_cylinder->type = ft_strdup(data_line[0]);
	if (!fill_coordinate(data_line[1], &new_cylinder->pos))
		return (obj_return(data, new_cylinder));
	if (!fill_normalized_vector(data_line[2], &new_cylinder->dir))
		return (obj_return(data, new_cylinder));
	new_cylinder->u = ft_vec3_orthogonal(new_cylinder->dir);
	new_cylinder->radius = atof(data_line[3]);
	new_cylinder->len = atof(data_line[4]);
	if (new_cylinder->radius < 0 || new_cylinder->len < 0)
		return (obj_return(data, new_cylinder));
	if (!fill_color(data_line[5], &new_cylinder->color))
		return (obj_return(data, new_cylinder));
	new_cylinder->next = NULL;
	put_obj_tail(data, new_cylinder);
	return (1);
}

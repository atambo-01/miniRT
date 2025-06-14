/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:38:15 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/14 13:24:51 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	obj_return(t_data *data, void *ptr)
{
	free(ptr);
	ft_free_obj(data->obj);
	return (0);
}

void	put_obj_tail(t_data *data, t_obj *obj)
{
	t_obj	*temp;

	if (!data->obj)
		data->obj = obj;
	else
	{
		temp = data->obj;
		while (temp->next)
			temp = temp->next;
		temp->next = obj;
	}
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
	if ((!fill_coordinate(data_line[1], &new_plane->pos))
	||	(!fill_normalized_vector(data_line[2], &new_plane->dir))
	||	(!fill_color(data_line[3], &new_plane->color)))
		return (obj_return(data, new_plane));
	new_plane->u = ft_vec3_orthogonal(new_plane->dir);
	new_plane->next = NULL;
	new_plane->radius = 0;
	put_obj_tail(data, new_plane);
	return (1);
}

int	sphere_data(t_data *data, char **data_line)
{
	t_obj	*sp;

	if (ft_array_size(data_line) < 4)
		return (0);
	sp = (t_obj *)malloc(sizeof(t_obj));
	if (!sp)
		return (0);
	sp->type = ft_strdup(data_line[0]);
	if ((!fill_coordinate(data_line[1], &sp->pos))
	||	(!fill_radius(sp, data_line, 2))
	||	(!fill_color(data_line[3], &sp->color)))
		return (obj_return(data, sp));
	ft_setvec3(&sp->dir, 0.0, 0.0, 0.0);
	ft_setvec3(&sp->u, 0.0, 0.0, 0.0);
	sp->next = NULL;
	put_obj_tail(data, sp);
	return (1);
}

int	cylinder_data(t_data *data, char **data_line)
{
	t_obj	*cy;

	if (ft_array_size(data_line) < 6)
		return (0);
	cy = (t_obj *)malloc(sizeof(t_obj));
	if (!cy)
		return (0);
	cy->type = ft_strdup(data_line[0]);
	if ((!fill_coordinate(data_line[1], &cy->pos))
		|| (!fill_normalized_vector(data_line[2], &cy->dir))
		|| (!fill_radius(cy, data_line, 3))
		|| (!fill_color(data_line[5], &cy->color)))
		return (obj_return(data, cy));
	cy->u = ft_vec3_orthogonal(cy->dir);
	cy->next = NULL;
	put_obj_tail(data, cy);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:03:18 by atambo            #+#    #+#             */
/*   Updated: 2025/06/03 19:38:56 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_plane_obj()
{

}

void ft_cylinder_normal()
{

}

void ft_sphere_normal(t_hit *hit, t_obj *obj)
{
	t_vec3	normal;

	normal = (t_vec3){0.0, 0.0, 0.0};
	if(!obj)
		return ;
	normal = ft_vec3_sub(obj->pos, hit->p);
	ft_normalize(&normal);
	hit->n = normal;
	return ;
}

void ft_obj_normal(t_hit *hit, t_obj *obj)
{
	if (!ft_strcmp(obj->type, "cy"))
		ft_cylinder_normal();
	// else if (!ft_strcmp(obj->type, "pl"))
	// 	ft_plane_normal();
	// else if (!ft_strcmp(obj->type, "sp"))
	// 	ft_sphere_normal();
	// else if (!ft_strcmp(obj->type, "cub"))
	// 	ft_cube_normal();
}
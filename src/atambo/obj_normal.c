/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:03:18 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 16:20:20 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_plane_normal(t_ray *ray, t_obj *pl)
{
	if (!ray || !pl || !ray->lum)
		return ;
	ray->n = pl->dir;
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	ft_normalize(&ray->n);
	ft_normalize(&ray->l);
}

void ft_sphere_normal(t_ray *ray, t_obj *sp)
{
	if (!ray || !sp || !ray->lum)
		return ;
	ray->n = ft_vec3_sub(ray->p, sp->pos);
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	ft_normalize(&ray->n);
	ft_normalize(&ray->l);
} 

void ft_cylinder_normal(t_ray *ray, t_obj *cy)
{
    if (!ray || !cy || !ray->lum)
		return ;
    t_vec3 oc_to_p = ft_vec3_sub(ray->p, cy->pos);
    double h = ft_dot(oc_to_p, cy->dir);
    t_vec3 point_on_axis = ft_vec3_add(cy->pos, ft_scalar_mult(cy->dir, h));
    ray->n = ft_vec3_sub(ray->p, point_on_axis);
    ft_normalize(&ray->n);
    if (ray->lum != NULL)
    {
        ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
        ft_normalize(&ray->l);
    }
}

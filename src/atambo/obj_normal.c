/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:03:18 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 11:08:35 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_plane_normal(t_ray *ray, t_obj *pl)
{
	t_vec3	normal;

	if (!ray || !pl || !ray->lum)
		return ;
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	normal = pl->dir;
	if (ft_cmp_dbl(ft_dot(normal, ray->dir), ">=", 0))
		ray->n = normal;
	else
		ray->n = ft_vec3_invert(normal);
	ft_normalize(&ray->n);
	ft_normalize(&ray->l);
}

void	ft_sphere_normal(t_ray *ray, t_obj *sp)
{
	t_vec3	normal;

	if (!ray || !sp || !ray->lum)
		return ;
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	normal = ft_vec3_sub(ray->p, sp->pos);
	if (ft_cmp_dbl(ft_dot(normal, ray->dir), ">=", 0))
		ray->n = normal;
	else
		ray->n = ft_vec3_invert(normal);
	ft_normalize(&ray->n);
	ft_normalize(&ray->l);
}

void	ft_cylinder_normal(t_ray *ray, t_obj *cy)
{
	t_vec3	point_on_axis;
	t_vec3	oc_to_p;
	t_vec3	normal;
	double	h;

	if (!ray || !cy || !ray->lum)
		return ;
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	oc_to_p = ft_vec3_sub(ray->p, cy->pos);
	h = ft_dot(oc_to_p, cy->dir);
	point_on_axis = ft_vec3_add(cy->pos, ft_scalar_mult(cy->dir, h));
	normal = ft_vec3_sub(ray->p, point_on_axis);
	if (ft_cmp_dbl(ft_dot(normal, ray->dir), ">=", 0))
		ray->n = normal;
	else
		ray->n = ft_vec3_invert(normal);
	ft_normalize(&ray->n);
	ft_normalize(&ray->l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:03:18 by atambo            #+#    #+#             */
/*   Updated: 2025/06/05 17:01:00 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_plane_obj(t_ray *ray, t_obj *pl)
{
	if (!ray || !pl || !ray->lum)
		return ;
	ray->n = pl->dir;
	ft_normalize(&ray->n);
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	ft_normalize(&ray->l);
}


void ft_sphere_normal(t_ray *ray, t_obj *sp)
{
	if (!ray || !sp)
		return ;
	ray->n = ft_vec3_sub(ray->p, sp->pos);
	ft_normalize(&ray->n);
	ray->l = ft_vec3_sub(ray->lum->pos, ray->p);
	ft_normalize(&ray->l);
} 
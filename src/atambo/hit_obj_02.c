/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 07:44:22 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 07:44:51 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_hit_cy_aux(t_cy *cy, t_ray *ray, t_obj *obj)
{
	cy->oc = ft_vec3_sub(ray->o, obj->pos);
	cy->dda = ft_dot(ray->dir, obj->dir);
	cy->ocda = ft_dot(cy->oc, obj->dir);
	cy->proj = ft_vec3_sub(ray->dir, ft_scalar_mult(obj->dir, cy->dda));
	cy->oc_proj = ft_vec3_sub(cy->oc, ft_scalar_mult(obj->dir, cy->ocda));
	cy->a = ft_dot(cy->proj, cy->proj);
	cy->b = 2.0 * ft_dot(cy->proj, cy->oc_proj);
	cy->c = ft_dot(cy->oc_proj, cy->oc_proj) - obj->radius * obj->radius;
	cy->delta = cy->b * cy->b - 4.0 * cy->a * cy->c;
	cy->t = -1;
}

void	ft_hit_cylinder(t_obj *obj, t_ray *ray)
{
	t_cy	cy;

	ft_hit_cy_aux(&cy, ray, obj);
	if (ft_cmp_dbl(cy.delta, ">=", 0) && ft_cmp_dbl(cy.a, ">=", 1e-6))
	{
		cy.t = (-cy.b - sqrt(cy.delta)) / (2.0 * cy.a);
		cy.z = cy.ocda + cy.t * cy.dda;
		if (ft_cmp_dbl(cy.t, "<", 0)
			|| ft_cmp_dbl(fabs(cy.z), ">=", obj->len / 2))
		{
			cy.t = (-cy.b + sqrt(cy.delta)) / (2.0 * cy.a);
			cy.z = cy.ocda + cy.t * cy.dda;
			if (ft_cmp_dbl(cy.t, "<", 0)
				|| ft_cmp_dbl(fabs(cy.z), ">=", obj->len / 2))
				cy.t = -1;
		}
	}
	if (ft_cmp_dbl(cy.t, ">=", 0) && (ft_cmp_dbl(cy.t, "<", ray->t)
			|| ft_cmp_dbl(ray->t, "<", 0)))
	{
		ft_hit_assign(cy.t, ray, obj);
		ft_cylinder_normal(ray, obj);
	}
}

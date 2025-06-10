/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:21:37 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 19:32:45 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

t_vec3	ft_vec_ab(t_vec3 *A, t_vec3 *B)
{
	t_vec3	ab;
	double	mag;

	ab.x = B->x - A->x;
	ab.y = B->y - A->y;
	ab.z = B->z - A->z;
	mag = sqrt(pow(ab.x, 2) + pow(ab.y, 2) + pow(ab.z, 2));
	ab.x /= mag;
	ab.y /= mag;
	ab.z /= mag;
	return (ab);
}

void	ft_light_assign(double t, t_ray *ray, t_light *lum)
{
	if (ft_cmp_dbl(t, ">=", 0.0) && ft_cmp_dbl(t, "<", ray->t)
		|| ft_cmp_dbl(ray->t, "<", 0.0))
	{
		ray->t = t;
		ray->obj = NULL;
	}
}

void	ft_hit_light_aux(t_ray *ray, t_light *lum, double *b, double *c)
{
	t_vec3	oc;

	oc = ft_vec3_sub(ray->o, lum->pos);
	*b = 2.0 * ft_dot(oc, ray->dir);
	*c = ft_dot(oc, oc) - lum->radius * lum->radius;
}

void	ft_hit_light(t_data *data, t_ray *ray, t_light *lum)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	ft_hit_light_aux(ray, lum, &b, &c);
	a = ft_dot(ray->dir, ray->dir);
	delta = b * b - 4.0 * a * c;
	if (ft_cmp_dbl(fabs(a), "<", 0.0))
		return ;
	if (ft_cmp_dbl(delta, "<", 0))
		return ;
	t = (-b - sqrt(delta)) / (2.0 * a);
	if (ft_cmp_dbl(t, "<", 0))
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		if (ft_cmp_dbl(t, "<", 0))
			return ;
	}
	ft_light_assign(t, ray, lum);
}

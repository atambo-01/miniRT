/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 19:30:59 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_hit_assign(double t, t_ray *ray, t_obj *obj)
{
	ray->t = t;
	ray->obj = obj;
	ray->p = ft_vec3_add(ray->o, ft_scalar_mult(ray->dir, ray->t));
}

void	ft_hit_plane_limited(t_obj *obj, t_ray *ray, double t)
{
	t_vec3	hit_p;
	t_vec3	u;
	t_vec3	v;
	t_vec3	p;

	hit_p = ft_vec3_add(ray->o, ft_scalar_mult(ray->dir, t));
	u = obj->u;
	v = (t_vec3){
		obj->dir.y * u.z - obj->dir.z * u.y,
		obj->dir.z * u.x - obj->dir.x * u.z,
		obj->dir.x * u.y - obj->dir.y * u.x
	};
	ft_normalize(&v);
	p.x = ft_dot(hit_p, u) - ft_dot(obj->pos, u);
	p.y = ft_dot(hit_p, v) - ft_dot(obj->pos, v);
	if (p.x < -obj->radius || p.x > obj->radius
		|| p.y < -obj->radius || p.y > obj->radius)
		return ;
	if (ft_cmp_dbl(t, ">=", 0) && (ft_cmp_dbl(t, "<", ray->t)
			|| ft_cmp_dbl(ray->t, "<", 0)))
	{
		ft_hit_assign(t, ray, obj);
		ft_plane_normal(ray, obj);
	}
}

void	ft_hit_plane(t_obj *obj, t_ray *ray)
{
	double	denom;
	double	t;

	denom = ft_dot(obj->dir, ray->dir);
	if (denom == 0.0)
		return ;
	t = (ft_dot(obj->pos, obj->dir) - ft_dot(ray->o, obj->dir)) / denom;
	if (t < 0.0)
		return ;
	if (obj->radius <= 0.0)
	{
		if (ft_cmp_dbl(t, ">=", 0) && (ft_cmp_dbl(t, "<", ray->t)
				|| ft_cmp_dbl(ray->t, "<", 0)))
		{
			ft_hit_assign(t, ray, obj);
			ft_plane_normal(ray, obj);
		}
	}
	ft_hit_plane_limited(obj, ray, t);
}

void	ft_hit_sp_aux(double *b, double *c, t_ray *ray, t_obj *obj)
{
	t_vec3	oc;

	oc = ft_vec3_sub(ray->o, obj->pos);
	*b = 2.0 * ft_dot(oc, ray->dir);
	*c = ft_dot(oc, oc) - obj->radius * obj->radius;
}

void	ft_hit_sphere(t_obj *obj, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	delta;

	a = ft_dot(ray->dir, ray->dir);
	ft_hit_sp_aux(&b, &c, ray, obj);
	delta = b * b - 4.0 * a * c;
	if (ft_cmp_dbl(delta, "<", EPSILON))
		return ;
	t = (-b - sqrt(delta)) / (2.0 * a);
	if (ft_cmp_dbl(t, "<", EPSILON))
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		if (ft_cmp_dbl(t, "<", 0))
			return ;
	}
	if (ft_cmp_dbl(t, ">=", 0) && (ft_cmp_dbl(t, "<", ray->t)
			|| ft_cmp_dbl(ray->t, "<", 0)))
	{
		ft_hit_assign(t, ray, obj);
		ft_sphere_normal(ray, obj);
	}
}

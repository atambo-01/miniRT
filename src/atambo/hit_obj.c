/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/04 16:24:35 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_hit_assign(double t, t_hit *hit, t_obj *obj)
{
	if (ft_cmp_dbl( t, ">=" ,0) && (ft_cmp_dbl(t ,"<" ,hit->t) || ft_cmp_dbl(hit->t, "<" ,0)))
	{
		hit->t = t;
		hit->color = obj->color;
		hit->obj = obj;
		hit->p = ft_vec3_add(hit->o, ft_scalar(hit->l, hit->t));
	}
}

double	ft_hit_plane(t_obj *obj, t_hit *hit, t_ray *ray)
{
	double denom, t;
	t_vec3 hit_p, u, v, p;

	denom = ft_dot(obj->dir, ray->dir);
	if (denom == 0.0)
		return (-1);
	t = (ft_dot(obj->pos, obj->dir) - ft_dot(ray->o, obj->dir)) / denom;
	if (t < 0.0)
		return (-1);
	if (obj->radius <= 0.0)
	{
		ft_hit_assign(t, hit, obj);
		return (t);
	}
	hit_p.x = ray->o.x + t * ray->dir.x;
	hit_p.y = ray->o.y + t * ray->dir.y;
	hit_p.z = ray->o.z + t * ray->dir.z;
	u = obj->u;
	v = (t_vec3){
		obj->dir.y * u.z - obj->dir.z * u.y,
		obj->dir.z * u.x - obj->dir.x * u.z,
		obj->dir.x * u.y - obj->dir.y * u.x
	};
	ft_normalize(&v);
	p.x = ft_dot(hit_p, u) - ft_dot(obj->pos, u);
	p.y = ft_dot(hit_p, v) - ft_dot(obj->pos, v);
	if (p.x < -obj->radius || p.x > obj->radius || p.y < -obj->radius || p.y > obj->radius)
		return (-1);
	ft_hit_assign(t, hit, obj);
	return (t);

}

double	ft_hit_sphere(t_obj *obj, t_hit *hit, t_ray *ray)
{
	t_vec3 oc = ft_vec3_sub(ray->o, obj->pos);
	double a = ft_dot(ray->dir, ray->dir);
	double b = 2.0 * ft_dot(oc, ray->dir);
	double c = ft_dot(oc, oc) - obj->radius * obj->radius;
	double delta = b * b - 4.0 * a * c;

	if (ft_cmp_dbl(delta, "<", EPSILON))
		return (-1);
	double t = (-b - sqrt(delta)) / (2.0 * a);
	if (ft_cmp_dbl(t, "<", EPSILON))
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		if (ft_cmp_dbl(t, "<", 0))
			return (-1.0);
	}
	ft_hit_assign(t, hit, obj);
	return (t);
}


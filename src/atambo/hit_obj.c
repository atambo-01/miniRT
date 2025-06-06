/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 16:20:13 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_hit_assign(double t, t_ray *ray, t_obj *obj)
{
		ray->t = t;
		ray->color = obj->color;
		ray->obj = obj;
		ray->p = ft_vec3_add(ray->o, ft_scalar_mult(ray->dir, ray->t));
}
double ft_hit_plane_limited(t_obj *obj, t_ray *ray, double t)
{
	t_vec3 hit_p, u, v, p;

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
	if (ft_cmp_dbl( t, ">=" ,0) && (ft_cmp_dbl(t ,"<" ,ray->t) || ft_cmp_dbl(ray->t, "<" ,0)))
	{
		ft_hit_assign(t, ray, obj);
		ft_plane_normal(ray, obj);
	}
	return (t);
}


double	ft_hit_plane(t_obj *obj, t_ray *ray)
{
	double denom, t;
	

	denom = ft_dot(obj->dir, ray->dir);
	if (denom == 0.0)
		return (-1);
	t = (ft_dot(obj->pos, obj->dir) - ft_dot(ray->o, obj->dir)) / denom;
	if (t < 0.0)
		return (-1);
	if (obj->radius <= 0.0)
	{
		if (ft_cmp_dbl( t, ">=" ,0) && (ft_cmp_dbl(t ,"<" ,ray->t) || ft_cmp_dbl(ray->t, "<" ,0)))
		{
			ft_hit_assign(t, ray, obj);
			ft_plane_normal(ray, obj);
		}
		return (t);
	}
	return (ft_hit_plane_limited(obj, ray, t));
}

double	ft_hit_sphere(t_obj *obj, t_ray *ray)
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
	if (ft_cmp_dbl( t, ">=" ,0) && (ft_cmp_dbl(t ,"<" ,ray->t) || ft_cmp_dbl(ray->t, "<" ,0)))
	{
		ft_hit_assign(t, ray, obj);
		ft_sphere_normal(ray, obj);
	}
	return (t);
}

double	ft_hit_cylinder(t_obj *obj, t_ray *ray)
{
	t_vec3 oc = ft_vec3_sub(ray->o, obj->pos);
	double dir_dot_axis = ft_dot(ray->dir, obj->dir);
	double oc_dot_axis = ft_dot(oc, obj->dir);
	t_vec3 proj = {ray->dir.x - dir_dot_axis * obj->dir.x, ray->dir.y - dir_dot_axis * obj->dir.y, ray->dir.z - dir_dot_axis * obj->dir.z};
	t_vec3 oc_proj = {oc.x - oc_dot_axis * obj->dir.x, oc.y - oc_dot_axis * obj->dir.y, oc.z - oc_dot_axis * obj->dir.z};
	double a = ft_dot(proj, proj);
	double b = 2.0 * ft_dot(proj, oc_proj);
	double c = ft_dot(oc_proj, oc_proj) - obj->radius * obj->radius;
	double delta = b * b - 4.0 * a * c;
	double t = -1, z;

	if (ft_cmp_dbl(delta, ">=", 0) && ft_cmp_dbl(a, ">=", 1e-6))
	{
		t = (-b - sqrt(delta)) / (2.0 * a);
		z = oc_dot_axis + t * dir_dot_axis;
		if (ft_cmp_dbl(t, "<", 0) || ft_cmp_dbl(fabs(z), ">=", obj->len / 2))
		{
			t = (-b + sqrt(delta)) / (2.0 * a);
			z = oc_dot_axis + t * dir_dot_axis;
			if (ft_cmp_dbl(t, "<", 0) || ft_cmp_dbl(fabs(z), ">=", obj->len / 2))
				t = -1;
		}
	}
	if (ft_cmp_dbl( t, ">=" ,0) && (ft_cmp_dbl(t ,"<" ,ray->t) || ft_cmp_dbl(ray->t, "<" ,0)))
	{
		ft_hit_assign(t, ray, obj);
		ft_cylinder_normal(ray, obj);
	}
	return (t - EPSILON);
}

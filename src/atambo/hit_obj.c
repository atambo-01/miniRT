/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 01:03:40 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

double	ft_hit_cube(t_vec3 origin, t_vec3 dir, t_obj *obj, t_hit *hit)
{
	t_vec3 v = {
		obj->dir.y * obj->u.z - obj->dir.z * obj->u.y,
		obj->dir.z * obj->u.x - obj->dir.x * obj->u.z,
		obj->dir.x * obj->u.y - obj->dir.y * obj->u.x
	}; // v = dir × u (local Y-axis)

	// Transform ray to local space
	t_vec3 local_origin = {
		ft_dot((t_vec3){origin.x - obj->pos

.x, origin.y - obj->pos

.y, origin.z - obj->pos

.z}, obj->u),
		ft_dot((t_vec3){origin.x - obj->pos

.x, origin.y - obj->pos

.y, origin.z - obj->pos

.z}, v),
		ft_dot((t_vec3){origin.x - obj->pos

.x, origin.y - obj->pos

.y, origin.z - obj->pos

.z}, obj->dir)
	};
	t_vec3 local_dir = {
		ft_dot(dir, obj->u),
		ft_dot(dir, v),
		ft_dot(dir, obj->dir)
	};

	double t_min = -INFINITY, t_max = INFINITY;
	double radius = obj->radius;
	int i = 0;

	while (i < 3)
	{
		double o = (&local_origin.x)[i];
		double d = (&local_dir.x)[i];
		if (fabs(d) < 1e-6) // Ray parallel to axis
		{
			if (o < -radius || o > radius)
				return (-1);
			i++;
			continue;
		}
		double t1 = (-radius - o) / d;
		double t2 = (radius - o) / d;
		if (t1 > t2)
		{
			double tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		t_min = fmax(t_min, t1);
		t_max = fmin(t_max, t2);
		if (t_min > t_max)
			return (-1);
		i++;
	}

	if (t_min < 0)
		return (-1); // Behind ray origin
	return (t_min);
}

double	ft_hit_plane(t_vec3 origin, t_vec3 dir, t_obj *obj, t_hit *hit_o)
{
	double denom, t;
	t_vec3 hit, u, v, p;

	denom = ft_dot(obj->dir, dir);
	if (denom == 0.0)
		return (-1);
	t = (ft_dot(obj->pos, obj->dir) - ft_dot(origin, obj->dir)) / denom;
	if (t < 0.0)
		return (-1);
	if (obj->radius <= 0.0)
		return (t);
	hit.x = origin.x + t * dir.x;
	hit.y = origin.y + t * dir.y;
	hit.z = origin.z + t * dir.z;
	u = obj->u;
	v = (t_vec3){
		obj->dir.y * u.z - obj->dir.z * u.y,
		obj->dir.z * u.x - obj->dir.x * u.z,
		obj->dir.x * u.y - obj->dir.y * u.x
	};
	ft_normalize(&v);
	p.x = ft_dot(hit, u) - ft_dot(obj->pos

, u);
	p.y = ft_dot(hit, v) - ft_dot(obj->pos

, v);
	if (p.x < -obj->radius || p.x > obj->radius || p.y < -obj->radius || p.y > obj->radius)
		return (-1);
	hit_o->n = obj->dir;
	hit_o->u = obj->u;
	return (t);
}

double	ft_hit_sphere(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit)
{
	t_vec3 oc = {ray_o.x - obj->pos.x, ray_o.y - obj->pos.y, ray_o.z - obj->pos.z};
	double a = ft_dot(ray_dir, ray_dir);
	double b = 2.0 * ft_dot(oc, ray_dir);
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
	hit->n = obj->dir;
	hit->u = obj->u;
	return (t);
}

double	ft_hit_cylinder(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit)
{
	t_vec3 oc = {ray_o.x - obj->pos.x, ray_o.y - obj->pos.y, ray_o.z - obj->pos.z};
	double dir_dot_axis = ft_dot(ray_dir, obj->dir);
	double oc_dot_axis = ft_dot(oc, obj->dir);
	t_vec3 proj = {ray_dir.x - dir_dot_axis * obj->dir.x, ray_dir.y - dir_dot_axis * obj->dir.y, ray_dir.z - dir_dot_axis * obj->dir.z};
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
	return (t - EPSILON);
}

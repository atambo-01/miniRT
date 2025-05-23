/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:21:37 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 20:30:32 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"


static t_vec3 ft_vec_AB(t_vec3 *A, t_vec3 *B)
{
	t_vec3	AB;
	float	mag;

	AB.x = B->x - A->x;
	AB.y = B->y - A->y;
	AB.z = B->z - A->z;
	mag = sqrt(pow(AB.x, 2) + pow(AB.y, 2) + pow(AB.z, 2));
	// if (mag is cloose to zero)
	// 	handle edge case
	AB.x /= mag;
	AB.y /= mag;
	AB.z /= mag;
	return (AB);
}

// static double	ft_calc_hit_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
// {
// 	if (!ft_strcmp(obj->type, "pl"))
// 		return (ft_hit_plane(ray_o, ray_dir, obj));
// 	else if (!ft_strcmp(obj->type, "sp"))
// 		return (ft_hit_sphere(ray_o, ray_dir, obj));
// 	else if (!ft_strcmp(obj->type, "cy"))
// 		return (ft_hit_cylinder(ray_o, ray_dir, obj));
// 	else if (!ft_strcmp(obj->type, "cub"))
// 		return (ft_hit_cube(ray_o, ray_dir, obj));
// 	else
// 		return (-1);
// }

double	ft_in_shadow(t_ray ray, t_obj *obj)
{
	double	t;

	t = 0;
	while (obj) // instead of for each obj we need a BVH logic to optimize
	{
		t = ft_calc_hit_2(ray.o, ray.dir, obj);
		if (t > 0) // if > 0 then is in shadow
			return (t);
		obj = obj->next;
	}
	return (0);
}

int ft_hit_light(t_data *data, t_ray ray, t_hit *hit, t_light *lum)
{
	t_vec3 oc = {ray.o.x - lum->center.x, ray.o.y - lum->center.y, ray.o.z - lum->center.z};
	double a = ft_dot(ray.dir, ray.dir);
	double b = 2.0 * ft_dot(oc, ray.dir);
	double c = ft_dot(oc, oc) - lum->radius * lum->radius;
	double discriminant = b * b - 4.0 * a * c;

	if (discriminant < 0)
		return (0);
	double t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
	{
		t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (t < 0)
			return (0);
	}
	return (t > 0);
}

double	ft_hit_obj_light(t_data *data, t_ray ray, t_hit hit, t_light *lum)
{
	double	t;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	
	t = 0;
	//init ray
	t_vec3 v1 = hit.p;
	if (!hit.obj)
		printf("is NULL\n");
	t_vec3 dir = hit.obj->dir;
	t_vec3 v2 = ft_scalar(dir, 0.0001);
	ray.o = ft_vec3_add(v1, v2);
	ray.dir = ft_vec_AB(&(ray.o), &(lum->center));

	//check against light
	oc = (t_vec3){ray.o.x - lum->center.x, ray.o.y - lum->center.y, ray.o.z - lum->center.z};
	a = ft_dot(ray.dir, ray.dir);
	b = 2.0 * ft_dot(oc, ray.dir);
	c = ft_dot(oc, oc) - lum->radius * lum->radius;
	discriminant = b * b - 4.0 * a * c;

	if (discriminant < 0)
		return (-1);
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 0)
	{
		t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (t < 0)
			return (-1);
	}
	//check against objects and return if hit
	if (ft_in_shadow(ray, data->obj))
		return (-1);
	return(t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:21:37 by atambo            #+#    #+#             */
/*   Updated: 2025/06/05 15:27:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

static t_vec3 ft_vec_AB(t_vec3 *A, t_vec3 *B)
{
	t_vec3	AB;
	double	mag;

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

// static double	ft_hit_obj_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
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

int	ft_in_shadow(t_ray ray, t_obj *obj, double light_d)
{
	double	t;
	t = 0;

	while (obj) // instead of for each obj we need a BVH logic to optimize
	{
		t = ft_hit_obj_2(&ray, obj);
		if (ft_cmp_dbl(t, ">=" ,0) && ft_cmp_dbl(t, "<", light_d)) // if > 0 then is in shadow
			return (1);
		obj = obj->next;
	}
	return (0);
}

int ft_hit_light(t_data *data, t_ray *ray, t_light *lum)
{
	t_vec3 oc = ft_vec3_sub(ray->o, lum->pos);

	double a = ft_dot(ray->dir, ray->dir);
	double b = 2.0 * ft_dot(oc, ray->dir);
	double c = ft_dot(oc, oc) - lum->radius * lum->radius;
	double delta = b * b - 4.0 * a * c;

	if (ft_cmp_dbl(fabs(a), "<", 0.0))
		return (0);
	if (ft_cmp_dbl(delta, "<", 0))
		return (0);
	double t = (-b - sqrt(delta)) / (2.0 * a);
	if (ft_cmp_dbl(t, "<" ,0))
	{
		t = (-b + sqrt(delta)) / (2.0 * a);
		if (ft_cmp_dbl(t, "<" ,0))
			return (0);
	}
	if (ft_cmp_dbl(t, ">=" ,0.0) && ft_cmp_dbl(t, "<" ,ray->t) || ft_cmp_dbl(ray->t, "<" ,0.0))
	{
		ray->t = t;
		ray->color = lum->color;
		ray->obj = NULL;
	}
	return (t > 0);
}

double ft_hit_obj_light(t_data *data, t_ray ray, t_light *lum)
{
    double d = 0.0;

    // Initialize shadow ray origin
    t_vec3 cam_dir = ft_vec_AB(&ray.p, &data->cam.pos); // Vector from hit point to camera
    t_vec3 offset = ft_scalar(cam_dir, 0.001); // Small offset toward camera
    ray.o = ft_vec3_add(ray.p, offset); // Move origin slightly toward camera
    ray.dir = ft_vec_AB(&ray.o, &lum->pos); // Direction from new origin to light

    // Check against light
    ft_hit_light(data, &ray, lum);
    d = ray.t;

    // Check for objects in shadow
    if (ft_in_shadow(ray, data->obj, ray.t))
        return (-1);
    return (d);
}

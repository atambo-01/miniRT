/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/05/02 01:27:34 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float ft_intersect_cube(t_vec3 origin, t_vec3 dir, t_obj *obj)
{
    t_vec3 v = {
        obj->dir.y * obj->u.z - obj->dir.z * obj->u.y,
        obj->dir.z * obj->u.x - obj->dir.x * obj->u.z,
        obj->dir.x * obj->u.y - obj->dir.y * obj->u.x
    }; // v = dir × u (local Y-axis)

    // Transform ray to local space
    t_vec3 local_origin = {
        ft_dot((t_vec3){origin.x - obj->center.x, origin.y - obj->center.y, origin.z - obj->center.z}, obj->u),
        ft_dot((t_vec3){origin.x - obj->center.x, origin.y - obj->center.y, origin.z - obj->center.z}, v),
        ft_dot((t_vec3){origin.x - obj->center.x, origin .y - obj->center.y, origin.z - obj->center.z}, obj->dir)
    };
    t_vec3 local_dir = {
        ft_dot(dir, obj->u),
        ft_dot(dir, v),
        ft_dot(dir, obj->dir)
    };

    // AABB intersection
    float t_min = -INFINITY, t_max = INFINITY;
    float radius = obj->radius;

    for (int i = 0; i < 3; i++)
    {
        float o = (&local_origin.x)[i];
        float d = (&local_dir.x)[i];
        if (fabs(d) < 1e-6) // Ray parallel to axis
        {
            if (o < -radius || o > radius)
                return (-1);
            continue;
        }
        float t1 = (-radius - o) / d;
        float t2 = (radius - o) / d;
        if (t1 > t2)
        {
            float tmp = t1;
            t1 = t2;
            t2 = tmp;
        }
        t_min = fmax(t_min, t1);
        t_max = fmin(t_max, t2);
        if (t_min > t_max)
            return (-1);
    }

    if (t_min < 0)
        return (-1); // Behind ray origin
    return (t_min);
}

float ft_intersect_plane(t_vec3 origin, t_vec3 dir, t_obj *obj)
{
    float denom, t;
    t_vec3 hit, u, v, p;

    denom = ft_dot(obj->dir, dir);
    if (denom == 0.0)
        return (-1);
    t = (ft_dot(obj->center, obj->dir) - ft_dot(origin, obj->dir)) / denom;
    if (t < 0.0)
        return (-1);
    if (obj->radius == 0.0)
        return (t);
    hit.x = origin.x + t * dir.x;
    hit.y = origin.y + t * dir.y;
    hit.z = origin.z + t * dir.z;
    u = obj->u; // Use stored local X-axis
    v = (t_vec3){
        obj->dir.y * u.z - obj->dir.z * u.y,
        obj->dir.z * u.x - obj->dir.x * u.z,
        obj->dir.x * u.y - obj->dir.y * u.x
    }; // v = dir × u (local Y-axis)
    ft_normalize(&v);
    p.x = ft_dot(hit, u) - ft_dot(obj->center, u);
    p.y = ft_dot(hit, v) - ft_dot(obj->center, v);
    if (p.x < -obj->radius || p.x > obj->radius || p.y < -obj->radius || p.y > obj->radius)
        return (-1);
    // if (sqrt(p.x * p.x + p.y * p.y) <= 3.0)
    //     return (-1);
    return (t);
}
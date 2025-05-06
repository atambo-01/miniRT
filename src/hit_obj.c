/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:47:34 by atambo            #+#    #+#             */
/*   Updated: 2025/05/06 23:30:05 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float ft_hit_cube(t_vec3 origin, t_vec3 dir, t_obj *obj)
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
        ft_dot((t_vec3){origin.x - obj->center.x, origin.y - obj->center.y, origin.z - obj->center.z}, obj->dir)
    };
    t_vec3 local_dir = {
        ft_dot(dir, obj->u),
        ft_dot(dir, v),
        ft_dot(dir, obj->dir)
    };

    // AABB intersection
    float t_min = -INFINITY, t_max = INFINITY;
    float radius = obj->radius;
    int i = 0;

    while (i < 3)
    {
        float o = (&local_origin.x)[i];
        float d = (&local_dir.x)[i];
        if (fabs(d) < 1e-6) // Ray parallel to axis
        {
            if (o < -radius || o > radius)
                return (-1);
            i++;
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
        i++;
    }

    if (t_min < 0)
        return (-1); // Behind ray origin
    return (t_min);
}

float ft_hit_plane(t_vec3 origin, t_vec3 dir, t_obj *obj)
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
    u = obj->u;
    v = (t_vec3){
        obj->dir.y * u.z - obj->dir.z * u.y,
        obj->dir.z * u.x - obj->dir.x * u.z,
        obj->dir.x * u.y - obj->dir.y * u.x
    };
    ft_normalize(&v);
    p.x = ft_dot(hit, u) - ft_dot(obj->center, u);
    p.y = ft_dot(hit, v) - ft_dot(obj->center, v);
    if (p.x < -obj->radius || p.x > obj->radius || p.y < -obj->radius || p.y > obj->radius)
        return (-1);
    return (t);
}

float ft_hit_sphere(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
    t_vec3 oc = {ray_o.x - obj->center.x, ray_o.y - obj->center.y, ray_o.z - obj->center.z};
    float a = ft_dot(ray_dir, ray_dir);
    float b = 2.0 * ft_dot(oc, ray_dir);
    float c = ft_dot(oc, oc) - obj->radius * obj->radius;
    float discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0)
        return (-1);
    float t = (-b - sqrt(discriminant)) / (2.0 * a);
    if (t < 0)
    {
        t = (-b + sqrt(discriminant)) / (2.0 * a);
        if (t < 0)
            return (-1);
    }
    return (t);
}

float ft_hit_cylinder(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
    t_vec3 oc = {ray_o.x - obj->center.x, ray_o.y - obj->center.y, ray_o.z - obj->center.z};
    float dir_dot_axis = ft_dot(ray_dir, obj->dir);
    float oc_dot_axis = ft_dot(oc, obj->dir);
    t_vec3 proj = {ray_dir.x - dir_dot_axis * obj->dir.x, ray_dir.y - dir_dot_axis * obj->dir.y, ray_dir.z - dir_dot_axis * obj->dir.z};
    t_vec3 oc_proj = {oc.x - oc_dot_axis * obj->dir.x, oc.y - oc_dot_axis * obj->dir.y, oc.z - oc_dot_axis * obj->dir.z};
    float a = ft_dot(proj, proj);
    float b = 2.0 * ft_dot(proj, oc_proj);
    float c = ft_dot(oc_proj, oc_proj) - obj->radius * obj->radius;
    float discriminant = b * b - 4.0 * a * c;
    float t = -1, z, t_cap;
    t_obj cap = *obj;

    if (discriminant >= 0 && a >= 1e-6)
    {
        t = (-b - sqrt(discriminant)) / (2.0 * a);
        z = oc_dot_axis + t * dir_dot_axis;
        if (t < 0 || fabs(z) > obj->len / 2)
        {
            t = (-b + sqrt(discriminant)) / (2.0 * a);
            z = oc_dot_axis + t * dir_dot_axis;
            if (t < 0 || fabs(z) > obj->len / 2)
                t = -1;
        }
    }
    cap.center = (t_vec3){obj->center.x + obj->len / 2 * obj->dir.x, obj->center.y + obj->len / 2 * obj->dir.y, obj->center.z + obj->len / 2 * obj->dir.z};
    t_cap = ft_hit_plane(ray_o, ray_dir, &cap);
    if (t_cap > 0)
    {
        t_vec3 hit = {ray_o.x + t_cap * ray_dir.x - cap.center.x, ray_o.y + t_cap * ray_dir.y - cap.center.y, ray_o.z + t_cap * ray_dir.z - cap.center.z};
        if (ft_dot(hit, hit) > obj->radius * obj->radius)
            t_cap = -1;
    }
    if (t_cap > 0 && (t < 0 || t_cap < t))
        return (t_cap);
    return (t);
}

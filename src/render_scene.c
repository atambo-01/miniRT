/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 12:55:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float ft_intersect_plane(t_vec3 orig, t_vec3 dir, t_vec3 center, t_vec3 normal, float size)
{
    float denom, t;
    t_vec3 hit, u, v, p;

    denom = ft_dot(normal, dir);
    if (denom == 0.0) // Ray parallel to plane
        return (-1);
    t = (ft_dot(center, normal) - ft_dot(orig, normal)) / denom;
    if (t < 0.0) // Intersection behind ray origin
        return (-1);
    if (size == 0.0) // Infinite plane
        return (t);
    hit.x = orig.x + t * dir.x;
    hit.y = orig.y + t * dir.y;
    hit.z = orig.z + t * dir.z;
    u = (t_vec3){-normal.z, 0, normal.x}; // Local X-axis perpendicular to normal
    ft_normalize(&u);
    v = (t_vec3){-normal.y * u.z, normal.z * u.z - normal.x * u.x, normal.x * u.y}; // Local Y-axis
    ft_normalize(&v);
    p.x = ft_dot(hit, u) - ft_dot(center, u);
    p.y = ft_dot(hit, v) - ft_dot(center, v);
    if (p.x < -size || p.x > size || p.y < -size || p.y > size) // Outside square
        return (-1);
    return (t);
}

void ft_render_scene(t_data *data)
{
    int x = 0;
    int y = 0;
    t_vec3 plane_center = {0, 0, 10}; // Center of plane
    t_vec3 plane_normal = {0.7071, 0, 0.7071}; // Normal (45° tilt)
    float plane_size = 50.0; // Half-size (10x10 square)
    t_vec3 ray_dir = data->cam.dir;

    while (y < IM_HEIGHT)
    {
        x = 0;
        while (x < IM_WIDTH)
        {
            t_vec3 ray_pos = data->cam.pos;
            ray_pos.x += (x - IM_WIDTH / 2);
            ray_pos.y += (IM_HEIGHT / 2 - y);
            float t = ft_intersect_plane(ray_pos, ray_dir, plane_center, plane_normal, plane_size);
            if (t > 0)
                ft_pixel_put_img(&data->img, x, y, 0xFFFFFF); // White for hit
            else
                ft_pixel_put_img(&data->img, x, y, 0x000000); // Black for miss
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 17:40:11 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float ft_intersect_plane(t_vec3 origin, t_vec3 dir, t_obj *obj)
{
    float denom, t;
    t_vec3 hit, u, v, p;

    denom = ft_dot(obj->dir, dir);
    if (denom == 0.0) // Ray parallel to plane
        return (-1);
    t = (ft_dot(obj->center, obj->dir) - ft_dot(origin, obj->dir)) / denom;
    if (t < 0.0) // Intersection behind ray origin
        return (-1);
    if (obj->radius == 0.0) // Infinite plane
        return (t);
    hit.x = origin.x + t * dir.x;
    hit.y = origin.y + t * dir.y;
    hit.z = origin.z + t * dir.z;
    u = (t_vec3){-obj->dir.z, 0, obj->dir.x}; // Local X-axis
    ft_normalize(&u);
    v = (t_vec3){-obj->dir.y * u.z, obj->dir.z * u.z - obj->dir.x * u.x, obj->dir.x * u.y}; // Local Y-axis
    ft_normalize(&v);
    p.x = ft_dot(hit, u) - ft_dot(obj->center, u);
    p.y = ft_dot(hit, v) - ft_dot(obj->center, v);
    if (p.x < -obj->radius || p.x > obj->radius || p.y < -obj->radius || p.y > obj->radius) // Outside square
        return (-1);
    if (sqrt(p.x * p.x + p.y * p.y) <= 3.0) // Black circle, radius 3
        return (-1);
    return (t);
}

void ft_render_scene(t_data *data)
{
    int x = 0;
    int y = 0;
    float fov = data->cam.fov * M_PI / 180.0; // 60 degrees to radians
    float aspect = (float)IM_WIDTH / IM_HEIGHT; // 1.5
    float tan_half_fov = tan(fov / 2.0);

    while (y < IM_HEIGHT)
    {
        x = 0;
        while (x < IM_WIDTH)
        {
            t_vec3 ray_pos = data->cam.pos;
            float px = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * tan_half_fov * aspect;
            float py = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * tan_half_fov;
            t_vec3 ray_dir = {px, py, 1.0};
            ft_normalize(&ray_dir);
            float t = ft_intersect_plane(ray_pos, ray_dir, data->obj);
            if (t > 0)
            {
                float intensity = 60.0 / t;
                int green = (int)(intensity * 255);
                int color = (green << 8); // 0x00GG00
                ft_pixel_put_img(&data->img, x, y, color);
            }
            else
                ft_pixel_put_img(&data->img, x, y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
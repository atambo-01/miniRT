/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/01 16:09:22 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
// ortogonal
// void ft_render_scene(t_data *data)
// {
//     int x = 0;
//     int y = 0;
//     float view_width = 20.0;  // View plane width (matches plane size)
//     float view_height = view_width * (float)IM_HEIGHT / IM_WIDTH; // Maintain aspect

//     while (y < IM_HEIGHT)
//     {
//         x = 0;
//         while (x < IM_WIDTH)
//         {
//             // Map pixel to world coords in view plane
//             float u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * view_width / 2.0;
//             float v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * view_height / 2.0;
//             t_vec3 ray_pos = {
//                 data->cam.pos.x + u,
//                 data->cam.pos.y + v,
//                 data->cam.pos.z
//             };
//             t_vec3 ray_dir = data->cam.dir; // Parallel rays
//             float t = ft_intersect_plane(ray_pos, ray_dir, data->obj);
//             if (t > 0)
//             {
//                 float intensity = 60.0 / (t + 1e-6); // Avoid division by zero
//                 if (intensity > 1.0)
//                     intensity = 1.0;
//                 if (intensity < 0.0)
//                     intensity = 0.0;
//                 int green = (int)(intensity * 255);
//                 int color = (green << 8); // 0x00GG00
//                 ft_pixel_put_img(&data->img, x, y, color);
//             }
//             else
//                 ft_pixel_put_img(&data->img, x, y, 0x000000);
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
// }

void ft_render_scene(t_data *data)
{
    int x = 0;
    int y = 0;
    float aspect_ratio = (float)IM_WIDTH / IM_HEIGHT;
    float tan_half_fov = tan(data->cam.fov * M_PI / 360.0); // Half FOV in radians
    float view_width = 2.0 * tan_half_fov; // View plane width at z=1
    float view_height = view_width / aspect_ratio; // Adjust for aspect

    while (y < IM_HEIGHT)
    {
        x = 0;
        while (x < IM_WIDTH)
        {
            // Map pixel to view plane at z=1
            float u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * tan_half_fov;
            float v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * view_height / 2.0;
            t_vec3 ray_dir = {
                u,
                v,
                1.0 // View plane at z=1
            };
            ft_normalize(&ray_dir); // Normalize for ft_intersect_plane
            float t = ft_intersect_plane(data->cam.pos, ray_dir, data->obj);
            if (t > 0)
            {
                float intensity = 12 / t;
                if (intensity > 1.0)
                    intensity = 1.0;
                if (intensity < 0.2)
                    intensity = 0.2;
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


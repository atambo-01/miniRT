/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/01 15:40:27 by atambo           ###   ########.fr       */
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
void ft_render_scene(t_data *data)
{
    int x = 0;
    int y = 0;
    float view_width = 20.0;  // View plane width (matches plane size)
    float view_height = view_width * (float)IM_HEIGHT / IM_WIDTH; // Maintain aspect

    while (y < IM_HEIGHT)
    {
        x = 0;
        while (x < IM_WIDTH)
        {
            // Map pixel to world coords in view plane
            float u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * view_width / 2.0;
            float v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * view_height / 2.0;
            t_vec3 ray_pos = {
                data->cam.pos.x + u,
                data->cam.pos.y + v,
                data->cam.pos.z
            };
            t_vec3 ray_dir = data->cam.dir; // Parallel rays
            float t = ft_intersect_plane(ray_pos, ray_dir, data->obj);
            if (t > 0)
            {
                float intensity = 60.0 / (t + 1e-6); // Avoid division by zero
                if (intensity > 1.0)
                    intensity = 1.0;
                if (intensity < 0.0)
                    intensity = 0.0;
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

// void ft_render_scene(t_data *data)
// {
//     int x = 0;
//     int y = 0;
//     float fov = data->cam.fov * M_PI / 180.0; // 60 degrees to radians
//     float aspect = (float)IM_WIDTH / IM_HEIGHT; // 1.5
//     float tan_half_fov = tan(fov / 2.0);

//     while (y < IM_HEIGHT)
//     {
//         x = 0;
//         while (x < IM_WIDTH)
//         {
//             t_vec3 ray_pos = data->cam.pos;
//             float px = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * tan_half_fov * aspect;
//             float py = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * tan_half_fov;
//             t_vec3 ray_dir = {px, py, 1.0};
//             ft_normalize(&ray_dir);
//             float t = ft_intersect_plane(ray_pos, ray_dir, data->obj);
//             if (t > 0)
//             {
//                 // float intensity = 60.0 / t; //so we can paint in relation to distance
//                 float intensity = 1.0;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/02 01:41:51 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ft_render_scene(t_data *data)
{
    int x = 0;
    int y = 0;
    float aspect_ratio = (float)IM_WIDTH / IM_HEIGHT;
    float tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
    float view_width = 2.0 * tan_half_fov;
    float view_height = view_width / aspect_ratio;

    while (y < IM_HEIGHT)
    {
        x = 0;
        while (x < IM_WIDTH)
        {
            float u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * tan_half_fov;
            float v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * view_height / 2.0;
            t_vec3 ray_dir = {u, v, 1.0};
            ft_normalize(&ray_dir);
            float t = -1;
            if (data->obj->type == 'p')
                t = ft_intersect_plane(data->cam.pos, ray_dir, data->obj);
            else if (data->obj->type == 'c')
                t = ft_intersect_cube(data->cam.pos, ray_dir, data->obj);
            if (t > 0)
            {
                float intensity = 12 / t;
                if (intensity > 1.0)
                    intensity = 1.0;
                if (intensity < 0.2)
                    intensity = 0.2;
                int green = (int)(intensity * 255);
                int color = (green << 8);
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


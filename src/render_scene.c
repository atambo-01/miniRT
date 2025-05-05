/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/05 12:57:58 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit *ft_calc_hit(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
    t_hit   *hit;

    hit = malloc(sizeof(t_hit));
    while(obj)
    {
        hit->obj = obj;
        if (!ft_strcmp(obj->type, "pl"))
            hit->t = ft_hit_plane(ray_o, ray_dir, obj);
        else if (!ft_strcmp(obj->type, "cub"))
            hit->t = ft_hit_cube(ray_o, ray_dir, obj);
        obj = obj->next;
    }
    return (hit);
}

void ft_ray_color(t_hit *hit, t_data *data, float x, float y)
{
    if (hit->t > 0)
    {
        int color = (int)(hit->obj->color);
        ft_pixel_put_img(&(data->img), x, y, color);
    }
    else
        ft_pixel_put_img(&(data->img), x, y, 0x000000);
}

void ft_render_scene(t_data *data)
{
    t_hit   *hit;
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
            hit = ft_calc_hit(data->cam.pos, ray_dir, data->obj);
            ft_ray_color(hit, data, x, y);
            free(hit);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

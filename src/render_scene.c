/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/05 14:10:28 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit *ft_calc_hit(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
    float   t1;
    float   t2;
    t_hit   *hit;

    hit = malloc(sizeof(t_hit));
    if (!hit)
        return (NULL);
    hit->t = -1;
    hit->obj = NULL;
    t1 = -1;
    while (obj)
    {
        if (obj->type[0] == 'p') // "pl"
            t2 = ft_hit_plane(ray_o, ray_dir, obj);
        else if (obj->type[0] == 'c') // "cub"
            t2 = ft_hit_cube(ray_o, ray_dir, obj);
        else
            t2 = -1;
        if (t2 >= 0 && (t2 < t1 || t1 < 0))
        {
            t1 = t2;
            hit->obj = obj;
        }
        obj = obj->next;
    }
    hit->t = t1;
    return (hit);
}

void ft_ray_color(t_hit *hit, t_data *data, float x, float y)
{
    int color;

    if (hit && hit->t >= 0 && hit->obj)
    {
        color = hit->obj->color;
        ft_pixel_put_img(&data->img, x, y, color);
    }
    else
        ft_pixel_put_img(&data->img, x, y, 0x000000);
}

void ft_render_scene(t_data *data)
{
    t_hit   *hit;
    int     x;
    int     y;
    float   aspect_ratio = (float)IM_WIDTH / IM_HEIGHT;
    float   tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
    float   view_width = 2.0 * tan_half_fov;
    float   view_height = view_width / aspect_ratio;

    y = 0;
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
            if (hit)
            {
                ft_ray_color(hit, data, x, y);
                free(hit);
            }
            else
                ft_pixel_put_img(&data->img, x, y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

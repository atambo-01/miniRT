/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/15 16:03:40 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_hit *ft_calc_hit(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
    float   t[2];
    t_hit   *hit;

    hit = malloc(sizeof(t_hit));
    if (!hit)
        return (NULL);
    hit->obj = NULL;
    t[0] = -1;
    while (obj)
    {
        if		(!ft_strcmp(obj->type, "pl"))
            t[1] = ft_hit_plane(ray_o, ray_dir, obj);
		else if (!ft_strcmp(obj->type, "sp"))
            t[1] = ft_hit_sphere(ray_o, ray_dir, obj);
		else if (!ft_strcmp(obj->type, "cy"))
            t[1] = ft_hit_cylinder(ray_o, ray_dir, obj);
		else if (!ft_strcmp(obj->type, "cub"))
            t[1] = ft_hit_cube(ray_o, ray_dir, obj);
        else
            t[1] = -1;
        if (t[1] >= 0 && (t[1] < t[0] || t[0] < 0))
        {
            t[0] = t[1];
            hit->obj = obj;
        }
        obj = obj->next;
    }
    hit->t = t[0];
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
    t_ray   ray;
    int     xy[2];
    
	gettimeofday(&(data->start), NULL);
    xy[1] = 0;
	ft_init_ray(data, xy[0], xy[1], &ray);
    while (xy[1] < IM_HEIGHT)
    {
        xy[0] = 0;
        while (xy[0] < IM_WIDTH)
        {
            ft_calc_ray(data, xy[0], xy[1], &ray);
            if (hit = ft_calc_hit(ray.o, ray.dir, data->obj))
            {
				ft_ray_color(hit, data, xy[0], xy[1]);
				free(hit);
			}
            else
                ft_pixel_put_img(&data->img, xy[0], xy[1], 0x000000);
            xy[0]++;
        }
        xy[1]++;
    }
    // ft_upscale_img(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	gettimeofday(&(data->end), NULL);
}

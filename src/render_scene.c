/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 12:31:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	ft_calc_hit_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj)
{
	if (!ft_strcmp(obj->type, "pl"))
		return (ft_hit_plane(ray_o, ray_dir, obj));
	else if (!ft_strcmp(obj->type, "sp"))
		return (ft_hit_sphere(ray_o, ray_dir, obj));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_hit_cylinder(ray_o, ray_dir, obj));
	else if (!ft_strcmp(obj->type, "cub"))
		return (ft_hit_cube(ray_o, ray_dir, obj));
	else
		return (-1);
}

t_hit	ft_calc_hit(t_ray ray, t_obj *obj)
{
	double	t;
	t_hit	hit;

	hit.obj = NULL;
	hit.t = -1;
	while (obj) // instead of for each obj we need a BVH logic to optimize
	{
		t = ft_calc_hit_2(ray.o, ray.dir, obj);
		if (t >= 0 && (t < hit.t || hit.t < 0))
		{
			hit.t = t;
			hit.obj = obj;
		}
		obj = obj->next;
	}
	hit.p = ft_vec3_add(ray.o, ft_scalar(ray.dir, hit.t));
	return (hit);
}

void ft_ray_color(t_hit *hit, t_data *data, double x, double y)
{
    int color;

    if (hit && hit->t >= 0 && hit->obj)
    {
        // Simple attenuation: brighter when closer, dimmer when farther
        double attenuation = 1.0 / (1.0 + 0.1 * hit->d); // Adjust 0.1 to control falloff

        // Combine with light ratio to scale intensity
        double intensity = data->light.ratio * attenuation;
        intensity = fmin(1.0, fmax(0.0, intensity)); // Clamp to [0, 1]

        // Extract RGB components of object and light colors
        int obj_r = (hit->obj->color >> 16) & 0xFF;
        int obj_g = (hit->obj->color >> 8) & 0xFF;
        int obj_b = hit->obj->color & 0xFF;

        int light_r = (data->light.color >> 16) & 0xFF;
        int light_g = (data->light.color >> 8) & 0xFF;
        int light_b = (data->light.color & 0xFF);

        // Calculate final color by scaling object color with light color and intensity
        int final_r = (int)(obj_r * light_r / 255.0 * intensity);
        int final_g = (int)(obj_g * light_g / 255.0 * intensity);
        int final_b = (int)(obj_b * light_b / 255.0 * intensity);

        // Clamp RGB values to [0, 255]
        final_r = fmin(255, fmax(0, final_r));
        final_g = fmin(255, fmax(0, final_g));
        final_b = fmin(255, fmax(0, final_b));

        // Combine into final color
        color = (final_r << 16) | (final_g << 8) | final_b;

        ft_pixel_put_img(&data->img, x, y, color);
    }
    else
    {
        // Background color (black)
        ft_pixel_put_img(&data->img, x, y, 0x000000);
    }
}

void	ft_render_scene(t_data *data)
{
	t_hit	hit;
	t_ray	ray;
	int		xy[2];
	
	xy[1] = 0;
	ft_init_ray(data, &(ray));
	while (xy[1] < IM_HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < IM_WIDTH)
		{
			ft_calc_ray(xy[0], xy[1], &(ray));
			if (!ft_hit_light(data, ray, &hit, &(data->light)))
			{	hit = ft_calc_hit(ray, data->obj);
				if (hit.t > 0 || hit.d)
				{
					hit.d = ft_hit_obj_light(data, ray, hit, &(data->light));
					ft_ray_color(&hit, data, xy[0], xy[1]);
				}
			}
			xy[0]++;
		}
		xy[1]++;
	}
}

void	ft_render_and_upscale(t_data *data, int upscale)
{
	gettimeofday(&(data->start), NULL); // remove later
	ft_render_scene(data);
	gettimeofday(&(data->end), NULL); //remove later
	if (upscale)
	{
		ft_upscale_img(data);
		mlx_put_image_to_window(data->mlx, data->win, data->s_img.ptr, 0, 0);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

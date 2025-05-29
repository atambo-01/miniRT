/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 12:50:19 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

double	ft_calc_hit_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit)
{
	if (!ft_strcmp(obj->type, "pl"))
		return (ft_hit_plane(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "sp"))
		return (ft_hit_sphere(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_hit_cylinder(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "cub"))
		return (ft_hit_cube(ray_o, ray_dir, obj, hit));
	else
		return (-1);
}

int	ft_calc_hit(t_ray ray, t_obj *obj, t_hit *hit)
{
	double	t;

	while (obj) // instead of for each obj we need a BVH logic to optimize
	{
		t = ft_calc_hit_2(ray.o, ray.dir, obj, hit);
		if (t >= 0 && (t < hit->t || hit->t < 0))
		{
			hit->t = t;
			hit->color = obj->color;
			hit->obj = obj;
			hit->n = obj->dir;
			hit->u = obj->u;
		}
		obj = obj->next;
	}
	hit->p = ft_vec3_add(ray.o, ft_scalar(ray.dir, hit->t));
	return (hit->t > 1);

}

int	ft_ray_color_aux(int color, double intensity)
{
	int	r;
	int shift;

		r = (color >> shift) & 0xFF;
		r = (int)(r * intensity);
		if (r > 255)
			r = 255;
		if (r < 0)
			r = 0;
	return (r);
}

// Compute the contribution of a light source (ambient or direct) to an object's color
void ft_light_effect(int color, int light, double ratio, int *rgb)
{
    // Extract object color components
    int obj_rgb[3];
    obj_rgb[0] = (color >> 16) & 0xFF; // Red
    obj_rgb[1] = (color >> 8) & 0xFF;  // Green
    obj_rgb[2] = color & 0xFF;         // Blue

    // Extract light color components
    int light_rgb[3];
    light_rgb[0] = (light >> 16) & 0xFF; // Red
    light_rgb[1] = (light >> 8) & 0xFF;  // Green
    light_rgb[2] = light & 0xFF;         // Blue

    // Scale light by ratio and multiply by object color
    rgb[0] = (int)(obj_rgb[0] * (light_rgb[0] / 255.0) * ratio);
    rgb[1] = (int)(obj_rgb[1] * (light_rgb[1] / 255.0) * ratio);
    rgb[2] = (int)(obj_rgb[2] * (light_rgb[2] / 255.0) * ratio);
}

void ft_ray_color(t_hit *hit, t_data *data, double x, double y)
{
    int rgb[3] = {0, 0, 0}; // Accumulated RGB values
    int temp_rgb[3];        // Temporary RGB for each light contribution

    if (hit->d >= 0)
    {
        int color = hit->color; // Object color
        // Direct light contribution
        int light = data->light.color;
        double intensity = data->light.ratio * 1.0 / (1.0 + KAPPA * hit->d * hit->d);
        ft_light_effect(color, light, intensity, temp_rgb);
        rgb[0] += temp_rgb[0];
        rgb[1] += temp_rgb[1];
        rgb[2] += temp_rgb[2];
    }

    // Ambient light contribution
    int light = data->alight.color;
    double intensity = data->alight.ratio;
    ft_light_effect(hit->color, light, intensity, temp_rgb);
    rgb[0] += temp_rgb[0];
    rgb[1] += temp_rgb[1];
    rgb[2] += temp_rgb[2];

    // Clamp to [0, 255]
    for (int i = 0; i < 3; i++)
    {
        if (rgb[i] > 255)
            rgb[i] = 255;
        if (rgb[i] < 0)
            rgb[i] = 0;
    }

    // Combine into final color
    int final_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
    ft_pixel_put_img(&data->img, x, y, final_color);
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
			ft_hit_init(&hit);
			ft_calc_ray(xy[0], xy[1], &(ray));
			ft_calc_hit(ray, data->obj, &hit);
			ft_hit_light(data, ray, &hit, &(data->light));
			if (hit.t > 0 && hit.obj)
				hit.d = ft_hit_obj_light(data, ray, hit, &(data->light));
			ft_ray_color(&hit, data, xy[0], xy[1]);
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

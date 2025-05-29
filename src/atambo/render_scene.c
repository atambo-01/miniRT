/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 11:20:55 by atambo           ###   ########.fr       */
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

int	ft_ray_color_aux(int color, int shift, double intensity)
{
	int	r;

	r = (color >> shift) & 0xFF;
	r = (int)(r * intensity);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	return (r);
}

int ft_add_alight(int color_1, t_alight lum)
{
    int rgb[3];

    // Extract base color components
    rgb[0] = (color_1 >> 16) & 0xFF; // Red
    rgb[1] = (color_1 >> 8) & 0xFF;  // Green
    rgb[2] = color_1 & 0xFF;         // Blue

    // Add scaled ambient light components
    rgb[0] += ft_ray_color_aux(lum.color, 16, lum.ratio); // Red + ambient red
    rgb[1] += ft_ray_color_aux(lum.color, 8, lum.ratio);  // Green + ambient green
    rgb[2] += ft_ray_color_aux(lum.color, 0, lum.ratio);  // Blue + ambient blue

    // Clamp to [0, 255]
    for (int i = 0; i < 3; i++)
    {
        if (rgb[i] > 255)
            rgb[i] = 255;
        if (rgb[i] < 0)
            rgb[i] = 0;
    }

    // Combine into final color
    return (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
}


void ft_ray_color(t_hit *hit, t_data *data, double x, double y)
{
	int		color;
	double	intensity;
	int		rgb[3];
	int		final_color;

	if (hit->d >= 0)
	{
		color = hit->color;

		intensity = data->light.ratio * 1.0 / (1.0
				+ KAPPA * hit->d * hit->d);
		rgb[0] = ft_ray_color_aux(color, 16, intensity);
		rgb[1] = ft_ray_color_aux(color, 8, intensity);
		rgb[2] = ft_ray_color_aux(color, 0, intensity);
		final_color = (rgb[0]  << 16) | (rgb[1] << 8) | rgb[2];
		final_color = ft_add_alight(final_color, data->alight);
		ft_pixel_put_img(&data->img, x, y, final_color);
	}
	else
		ft_pixel_put_img(&data->img, x, y, 0x000000);
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

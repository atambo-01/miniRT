/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:17 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 20:45:56 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_ray_color(t_color *rgb, t_color ray, t_color light, double effect)
{
	rgb->r += (int)(ray.r * (light.r / 255.0) * effect);
	rgb->g += (int)(ray.g * (light.g / 255.0) * effect);
	rgb->b += (int)(ray.b * (light.b / 255.0) * effect);
}

void	ft_ray_color(t_ray *ray, t_data *data, double x, double y)
{
	t_color	rgb;
	double	dim;
	double	surface;

	rgb = (t_color){0, 0, 0};
	if (ray->d >= 0)
	{
		surface = ft_dot(ray->n, ray->l);
		if (ft_cmp_dbl(surface, "<", 0))
			surface = 0.0;
		dim = data->light.ratio / (1.0 + KAPPA * GAMMA * ray->d * ray->d);
		ft_ray_color(&rgb, ray->color, data->light.color, dim * surface);
	}
	if (ray->obj)
		ft_ray_color(&rgb, ray->color, data->alight.color, data->alight.ratio);
	else
		rgb = ray->color;
	rgb.r = (int)fmin(255.0, fmax(0.0, rgb.r));
	rgb.g = (int)fmin(255.0, fmax(0.0, rgb.g));
	rgb.b = (int)fmin(255.0, fmax(0.0, rgb.b));
	ft_pixel_put_img(&data->img, x, y, t_color_to_int(rgb));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:17 by atambo            #+#    #+#             */
/*   Updated: 2025/06/05 16:49:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_ray_color(t_ray *ray, t_data *data, double x, double y)
{
    t_color rgb = {0, 0, 0};

    if (ray->d >= 0)
    {
		double surface = ft_dot(ray->n, ray->l);
		if (ft_cmp_dbl(surface, "<", 0))
			surface = 0.0;
        double attenuation = data->light.ratio / (1.0 + KAPPA * ray->d * ray->d);
        rgb.r += (int)(ray->color.r * (data->light.color.r / 255.0) * attenuation * surface);
        rgb.g += (int)(ray->color.g * (data->light.color.g / 255.0) * attenuation * surface);
        rgb.b += (int)(ray->color.b * (data->light.color.b / 255.0) * attenuation * surface);
		
    }
	if (ray->obj)
	{
		rgb.r += (int)(ray->color.r * (data->alight.color.r / 255.0) * data->alight.ratio);
		rgb.g += (int)(ray->color.g * (data->alight.color.g / 255.0) * data->alight.ratio);
		rgb.b += (int)(ray->color.b * (data->alight.color.b / 255.0) * data->alight.ratio);
	}
	else
		rgb = ray->color;
	rgb.r = (int)fmin(255.0, fmax(0.0, rgb.r));
    rgb.g = (int)fmin(255.0, fmax(0.0, rgb.g));
    rgb.b = (int)fmin(255.0, fmax(0.0, rgb.b));
    ft_pixel_put_img(&data->img, x, y, t_color_to_int(rgb));
}

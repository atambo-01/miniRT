/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:17 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 15:10:09 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

t_color t_color_clamp(t_color color)
{
	t_color res;

	res = color;
	if (res.r > 255)
		res.r = 255;
	if (res.g > 255)
		res.g = 255;
	if (res.b > 255)
		res.b = 255;
	return (res);
}

int t_color_to_int(t_color color)
{
    t_color	clamped;

	clamped = t_color_clamp(color);
    return ((clamped.r << 16) | (clamped.g << 8) | (clamped.b));
}

void ft_ray_color(t_hit *hit, t_data *data, double x, double y)
{
    t_color rgb = {0, 0, 0};

    if (hit->d >= 0)
    {
        // Direct light contribution
        double intensity = data->light.ratio / (1.0 + KAPPA * hit->d * hit->d);
        rgb.r = (int)(hit->color.r * (data->light.color.r / 255.0) * intensity);
        rgb.g = (int)(hit->color.g * (data->light.color.g / 255.0) * intensity);
        rgb.b = (int)(hit->color.b * (data->light.color.b / 255.0) * intensity);
    }

    // Ambient light contribution
    rgb.r += (int)(hit->color.r * (data->alight.color.r / 255.0) * data->alight.ratio);
    rgb.g += (int)(hit->color.g * (data->alight.color.g / 255.0) * data->alight.ratio);
    rgb.b += (int)(hit->color.b * (data->alight.color.b / 255.0) * data->alight.ratio);

    // Output to image with clamping
    ft_pixel_put_img(&data->img, x, y, t_color_to_int(rgb));
}
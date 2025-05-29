/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:17 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 13:33:26 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

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
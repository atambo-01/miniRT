/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:21:59 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 15:22:08 by atambo           ###   ########.fr       */
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
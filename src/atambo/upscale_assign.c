/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscale_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:28:07 by atambo            #+#    #+#             */
/*   Updated: 2025/06/13 11:44:34 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_assign_src_coords(t_upscale *up, int x, int y)
{
	double	scale_x;
	double	scale_y;

	scale_x = (double)IM_WIDTH / W_WIDTH;
	scale_y = (double)IM_HEIGHT / W_HEIGHT;
	up->src_x = x * scale_x;
	up->src_y = y * scale_y;
	up->fx = up->src_x - (int)up->src_x;
	up->fy = up->src_y - (int)up->src_y;
}

void	ft_assign_corner_pixels(t_data *data, t_upscale *up)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = (int)up->src_x;
	y0 = (int)up->src_y;
	if (x0 + 1 < IM_WIDTH)
		x1 = x0 + 1;
	else
		x1 = x0;
	if (y0 + 1 < IM_HEIGHT)
		y1 = y0 + 1;
	else
		y1 = y0;
	up->p00 = (int *)(data->img.addr + y0 * data->img.line_len + x0
			* (data->img.bpp / 8));
	up->p10 = (int *)(data->img.addr + y0 * data->img.line_len + x1
			* (data->img.bpp / 8));
	up->p01 = (int *)(data->img.addr + y1 * data->img.line_len + x0
			* (data->img.bpp / 8));
	up->p11 = (int *)(data->img.addr + y1 * data->img.line_len + x1
			* (data->img.bpp / 8));
}

void	ft_assign_rgb_values(t_upscale *up)
{
	up->r00 = (*up->p00 >> 16) & 0xFF;
	up->g00 = (*up->p00 >> 8) & 0xFF;
	up->b00 = *up->p00 & 0xFF;
	up->r10 = (*up->p10 >> 16) & 0xFF;
	up->g10 = (*up->p10 >> 8) & 0xFF;
	up->b10 = *up->p10 & 0xFF;
	up->r01 = (*up->p01 >> 16) & 0xFF;
	up->g01 = (*up->p01 >> 8) & 0xFF;
	up->b01 = *up->p01 & 0xFF;
	up->r11 = (*up->p11 >> 16) & 0xFF;
	up->g11 = (*up->p11 >> 8) & 0xFF;
	up->b11 = *up->p11 & 0xFF;
}

void	ft_init_neighbor(t_upscale *up, t_neighbor *nb)
{
	nb->r_sum = up->r;
	nb->g_sum = up->g;
	nb->b_sum = up->b;
	nb->count = 1;
	nb->x0 = (int)up->src_x;
	nb->y0 = (int)up->src_y;
	nb->dy = -1;
	nb->dx = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscale_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:24:21 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 16:17:41 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"

static void	ft_bilinear_interpolate(t_upscale *up)
{
	ft_assign_rgb_values(up);
	up->r = (1 - up->fx) * (1 - up->fy) * up->r00 + up->fx * (1 - up->fy)
		* up->r10 + (1 - up->fx) * up->fy * up->r01 + up->fx * up->fy * up->r11;
	up->g = (1 - up->fx) * (1 - up->fy) * up->g00 + up->fx * (1 - up->fy)
		* up->g10 + (1 - up->fx) * up->fy * up->g01 + up->fx * up->fy * up->g11;
	up->b = (1 - up->fx) * (1 - up->fy) * up->b00 + up->fx * (1 - up->fy)
		* up->b10 + (1 - up->fx) * up->fy * up->b01 + up->fx * up->fy * up->b11;
}

static void	ft_process_neighbor(t_data *data, t_neighbor *nb)
{
	nb->nx = nb->x0 + nb->dx;
	nb->ny = nb->y0 + nb->dy;
	if (nb->nx >= 0 && nb->nx < IM_WIDTH && nb->ny >= 0 && nb->ny < IM_HEIGHT)
	{
		nb->p = (int *)(data->img.addr + nb->ny * data->img.line_len + nb->nx
				* (data->img.bpp / 8));
		nb->r_sum += (*nb->p >> 16) & 0xFF;
		nb->g_sum += (*nb->p >> 8) & 0xFF;
		nb->b_sum += *nb->p & 0xFF;
		nb->count++;
	}
}

static void	ft_finalize_neighbor(t_upscale *up, t_neighbor *nb)
{
	up->r = nb->r_sum / nb->count;
	up->g = nb->g_sum / nb->count;
	up->b = nb->b_sum / nb->count;
}

static void	ft_average_neighbors(t_data *data, t_upscale *up)
{
	t_neighbor	nb;

	ft_init_neighbor(up, &nb);
	while (nb.dy <= 1)
	{
		nb.dx = -1;
		while (nb.dx <= 1)
		{
			if (nb.dx != 0 || nb.dy != 0)
				ft_process_neighbor(data, &nb);
			nb.dx++;
		}
		nb.dy++;
	}
	ft_finalize_neighbor(up, &nb);
}

void	ft_upscale_img(t_data *data)
{
	t_upscale	up;
	int			color;
	int			y;
	int			x;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			ft_assign_src_coords(data, &up, x, y);
			ft_assign_corner_pixels(data, &up);
			ft_bilinear_interpolate(&up);
			ft_average_neighbors(data, &up);
			color = ((int)up.r << 16) | ((int)up.g << 8) | (int)up.b;
			ft_pixel_put_img(&data->s_img, x, y, color);
			x++;
		}
		y++;
	}
}

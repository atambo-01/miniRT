/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:42:33 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 20:52:04 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

double	ft_get_speed(struct timeval start, struct timeval end)
{
	double	sec_diff;
	double	usec_diff ;

	sec_diff = (double)((end.tv_sec - start.tv_sec) * 1000.0);
	usec_diff = (double)(end.tv_usec - start.tv_usec) / 1000.0;
	return (sec_diff + usec_diff);
}

void	ft_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_count_obj(t_obj *obj)
{
	int	i;

	i = 0;
	while (obj)
	{
		i++;
		obj = obj->next;
	}
	return (i);
}

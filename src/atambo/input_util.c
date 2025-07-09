/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:17:13 by atambo            #+#    #+#             */
/*   Updated: 2025/07/09 15:28:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.ptr);
	mlx_destroy_image(data->mlx, data->s_img.ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	ft_obj_size(int key, t_data *data, double i)
{
	if (!data->curr)
		return ;
	if (ft_strcmp(data->curr->type, "pl") == 0)
	{
		if (key == 'i' || key == 'k')
		{
			if (data->curr->radius == 0.0)
				data->curr->radius = 1;
			else
				data->curr->radius += (i / 100) * data->curr->radius;
		}
		else if (key == 'o' || key == 'l')
		{
			if (data->curr->radius <= 0.0)
				data->curr->radius = 0;
			else
				data->curr->radius += (i / 100) * data->curr->radius;
		}
	}
	if (key == 'i' || key == 'k')
		data->curr->radius += (i / 100) * data->curr->radius;
	else if (key == 'o' || key == 'l')
		data->curr->len += (i / 100) * data->curr->radius;
}

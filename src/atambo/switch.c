/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:43:14 by atambo            #+#    #+#             */
/*   Updated: 2025/06/09 19:19:43 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_switch_obj_point(t_data *data, int x, int y)
{
	t_ray	ray;

	x = x * ((double)IM_WIDTH / W_WIDTH);
	y = y * ((double)IM_HEIGHT / W_HEIGHT);
	ft_init_ray(data, &ray);
	ft_calc_ray(x, y, &ray, &data->cam);
	ft_hit_obj(&ray, data->obj);
	if (ray.t > 0)
	{
		data->curr = ray.obj;
		data->curr_light = NULL;
	}
	else
		data->curr = NULL;
}

void	ft_switch_obj(t_data *data)
{
	if (!data->curr)
		data->curr = data->obj;
	else if (data->curr->next)
		data->curr = data->curr->next;
	else
		data->curr = data->obj;
	data->curr_light = NULL;
}

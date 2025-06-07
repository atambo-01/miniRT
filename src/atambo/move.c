/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:25:39 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 09:05:37 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_move_x(t_data *data, double i)
{
	if (data->curr)
	{
		data->curr->pos.x += i;
		if (data->focus)
			data->cam.pos.x += i;
	}
	else if (data->curr_light)
	{
		data->curr_light->pos.x += i;
		if (data->focus)
			data->cam.pos.x += i;
	}
	else
		data->cam.pos.x += i;
}

void	ft_move_y(t_data *data, double i)
{
	if (data->curr)
	{
		data->curr->pos.y += i;
		if (data->focus)
			data->cam.pos.y += i;
	}
	else if (data->curr_light)
	{
		data->curr_light->pos.y += i;
		if (data->focus)
			data->cam.pos.y += i;
	}
	else
		data->cam.pos.y += i;
}

void	ft_move_z(t_data *data, double i)
{
	if (data->curr)
	{
		data->curr->pos.z += i;
		if (data->focus)
			data->cam.pos.z += i;
	}
	else if (data->curr_light)
	{
		data->curr_light->pos.z += i;
		if (data->focus)
			data->cam.pos.z += i;
	}
	else
		data->cam.pos.z += i;
}

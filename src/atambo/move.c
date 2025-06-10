/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:25:39 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 12:55:26 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_move_x(t_data *data, double i)
{
	t_vec3	temp;

	if (!data)
		return ;
	temp = ft_scalar_mult(data->cam.right, i);
	if (data->curr)
	{
		data->curr->pos = ft_vec3_add(data->curr->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr->pos, temp);
	}
	else if (data->curr_light)
	{
		data->curr_light->pos = ft_vec3_add(data->curr_light->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr_light->pos, temp);
	}
	else
		data->cam.pos = ft_vec3_add(data->cam.pos, temp);
}

void	ft_move_y(t_data *data, double i)
{
	t_vec3	temp;

	if (!data)
		return ;
	temp = ft_scalar_mult(data->cam.up, i);
	if (data->curr)
	{
		data->curr->pos = ft_vec3_add(data->curr->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr->pos, temp);
	}
	else if (data->curr_light)
	{
		data->curr_light->pos = ft_vec3_add(data->curr_light->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr_light->pos, temp);
	}
	else
		data->cam.pos = ft_vec3_add(data->cam.pos, temp);
}

void	ft_move_z(t_data *data, double i)
{
	t_vec3	temp;

	if (!data)
		return ;
	temp = ft_scalar_mult(data->cam.dir, i);
	if (data->curr)
	{
		data->curr->pos = ft_vec3_add(data->curr->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr->pos, temp);
	}
	else if (data->curr_light)
	{
		data->curr_light->pos = ft_vec3_add(data->curr_light->pos, temp);
		if (data->focus)
			data->cam.pos = ft_vec3_add(data->curr_light->pos, temp);
	}
	else
		data->cam.pos = ft_vec3_add(data->cam.pos, temp);
}

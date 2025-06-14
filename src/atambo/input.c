/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/06/15 00:25:23 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_key_hook_3(int key, t_data *data)
{
	if (key == '`')
	{
		if (data->curr_light)
			data->curr_light = NULL;
		else
		{
			data->curr = NULL;
			data->curr_light = &data->light;
		}
	}
	else if (key == 'f')
	{
		if (data->focus)
			data->focus = 0;
		else
			data->focus = 1;
	}
	return (0);
}

int	ft_key_hook_2(int key, t_data *data)
{
	if (key == 32)
		ft_switch_obj(data);
	else if (key == 'i')
		ft_obj_size(key, data, 25.0);
	else if (key == 'k')
		ft_obj_size(key, data, -25.0);
	else if (key == 'o')
		ft_obj_size(key, data, 25.0);
	else if (key == 'l')
		ft_obj_size(key, data, -25.0);
	else if (key == '0')
		ft_export_scene(data);
	else if (key == TAB || key == SHIFT)
		ft_color_switch(data, key);
	else if (key == 'r')
	{
		if (data->ray_info)
			data->ray_info = 0;
		else
			data->ray_info = 1;
	}
	else
		ft_key_hook_3(key, data);
	return (0);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == '.')
	{
		data->curr = NULL;
		data->curr_light = NULL;
	}
	else if (key == 65307)
		ft_exit_minirt(data);
	else if (key == 'w')
		ft_move_y(data, +1.0);
	else if (key == 's')
		ft_move_y(data, -1.0);
	else if (key == 'a')
		ft_move_x(data, -1.0);
	else if (key == 'd')
		ft_move_x(data, +1.0);
	else
		ft_key_hook_2(key, data);
	ft_rotate_cam(key, &data->cam);
	ft_rotate_obj(key, data->curr);
	ft_print_data(data);
	ft_render_and_upscale(data);
	printf("key = %d (%c)\n", key, key);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (!data)
		return (1);
	if (button == 4)
		ft_move_z(data, +1.0);
	if (button == 5)
		ft_move_z(data, -1.0);
	if (button == 1)
	{
		ft_switch_obj_point(data, x, y);
		if (data->ray_info)
		{
			ft_ray_info(x, y, data);
			printf("mouse_hook = %d\n", button);
			return (0);
		}
	}
	ft_print_data(data);
	ft_render_and_upscale(data);
	printf("mouse_hook = %d\n", button);
	return (0);
}

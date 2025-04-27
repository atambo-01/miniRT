/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 07:41:13 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// void	key_hook_2(int keycode, t_data *data)
// {
// }

// int	key_hook(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 		close_window(data);
// 	if (keycode == DOWN)
// 	if (keycode == UP)
// 	if (keycode == LEFT)
// 	if (keycode == RIGHT)
// 	key_hook_2(keycode, data);
// 	return (0);
// }

int ft_p_cam(t_data *data)
{
	system("clear");
	printf("\t\tx\ty\tz\n");
	printf("cam_pos =\t%0.4f\t%0.4f\t%0.4f \n", data->cam.pos.x, data->cam.pos.y, data->cam.pos.z);
	printf("cam_dir =\t%0.4f\t%0.4f\t%0.4f \n", data->cam.dir.x, data->cam.dir.y, data->cam.dir.z);
	printf("---------------------------------------------------\n");
}

int ft_key_hook(int keycode, t_data *data)
{
	printf("key = %d\n", keycode);
	if (keycode == 65307)
		ft_close_window(data);
	if (keycode == 119)
		data->cam.pos.y += 1;
	if (keycode == 115)
		data->cam.pos.y -= 1;
	if (keycode == 97)
		data->cam.pos.x -= 1;
	if (keycode == 100)
		data->cam.pos.x += 1;
	if (keycode == 113)
	{
		float tmp = data->cam.dir.x;
		data->cam.dir.x = tmp * cos(0.1) + data->cam.dir.z * sin(0.1);
		data->cam.dir.z = -tmp * sin(0.1) + data->cam.dir.z * cos(0.1);
		ft_normalize(&data->cam.dir);
	}
	if (keycode == 101)
	{
		float tmp = data->cam.dir.x;
		data->cam.dir.x = tmp * cos(-0.1) + data->cam.dir.z * sin(-0.1);
		data->cam.dir.z = -tmp * sin(-0.1) + data->cam.dir.z * cos(-0.1);
		ft_normalize(&data->cam.dir);
	}
    ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	ft_p_cam(data);
    return (0);
}

int ft_mouse_hook(int button, int x, int y, t_data *data)
{
    if (button == 4) // Scroll up
        data->cam.pos.z += 1.0;
    if (button == 5) // Scroll down
        data->cam.pos.z -= 1.0;
	ft_render_scene(data);
	ft_p_cam(data);
    return (0);
}
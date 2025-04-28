/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/04/28 07:29:27 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ft_rotate_obj_z(int keycode, t_data *data)
{
    float angle = 15.0 * M_PI / 180.0; // 15 degrees
    float tmp = data->obj->dir.x;
    if (keycode == 65436) // z: +15° (clockwise)
    {
        data->obj->dir.x = tmp * cos(angle) - data->obj->dir.y * sin(angle);
        data->obj->dir.y = tmp * sin(angle) + data->obj->dir.y * cos(angle);
    }
    else if (keycode == 65435) // x: -15° (counterclockwise)
    {
        data->obj->dir.x = tmp * cos(angle) + data->obj->dir.y * sin(angle);
        data->obj->dir.y = -tmp * sin(angle) + data->obj->dir.y * cos(angle);
    }
    if (keycode == 65436 || keycode == 65435)
    {
        ft_normalize(&data->obj->dir);
        ft_print_vec3(&data->obj->dir);
    }
}

void ft_rotate_obj_y(int keycode, t_data *data)
{
    float angle = 15.0 * M_PI / 180.0; // 15 degrees
    float tmp = data->obj->dir.x;
    if (keycode == 65430) // c: +15°
    {
        data->obj->dir.x = tmp * cos(angle) - data->obj->dir.z * sin(angle);
        data->obj->dir.z = tmp * sin(angle) + data->obj->dir.z * cos(angle);
    }
    else if (keycode == 65432) // v: -15°
    {
        data->obj->dir.x = tmp * cos(angle) + data->obj->dir.z * sin(angle);
        data->obj->dir.z = -tmp * sin(angle) + data->obj->dir.z * cos(angle);
    }
    if (keycode == 65430 || keycode == 65432)
    {
        ft_normalize(&data->obj->dir);
        ft_print_vec3(&data->obj->dir);
    }
}
void ft_rotate_obj_x(int keycode, t_data *data)
{
    float angle = 15.0 * M_PI / 180.0; // 15 degrees in radians
    float tmp = data->obj->dir.x;
    if (keycode == 65429) // z: +15° (clockwise)
    {
        data->obj->dir.x = tmp * cos(angle) - data->obj->dir.y * sin(angle);
        data->obj->dir.y = tmp * sin(angle) + data->obj->dir.y * cos(angle);
    }
    else if (keycode == 65434) // x: -15° (counterclockwise)
    {
        data->obj->dir.x = tmp * cos(angle) + data->obj->dir.y * sin(angle);
        data->obj->dir.y = -tmp * sin(angle) + data->obj->dir.y * cos(angle);
    }
    if (keycode == 65429 || keycode == 65434)
    {
        ft_normalize(&data->obj->dir); // Normalize after rotation
        ft_print_vec3(&data->obj->dir); // Debug
    }
}
void ft_rotate_obj(int keycode, t_data *data)
{
	ft_rotate_obj_x(keycode, data);
    ft_rotate_obj_y(keycode, data);
    ft_rotate_obj_z(keycode, data);
}

void ft_rotate_cam(int keycode, t_data *data)
{
	if (keycode == 113)
	{
		float tmp = data->cam.dir.x;
		data->cam.dir.x = tmp * cos(0.1) + data->cam.dir.z * sin(0.1);
		data->cam.dir.z = -tmp * sin(0.1) + data->cam.dir.z * cos(0.1);
	}
	if (keycode == 113) // Q
    {
        float tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(0.157) + data->cam.dir.z * sin(0.157);
        data->cam.dir.z = -tmp * sin(0.157) + data->cam.dir.z * cos(0.157);
    }
    if (keycode == 101) // E
    {
        float tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(-0.157) + data->cam.dir.z * sin(-0.157);
        data->cam.dir.z = -tmp * sin(-0.157) + data->cam.dir.z * cos(-0.157);
    }
    ft_normalize(&data->cam.dir);
}

int ft_key_hook(int keycode, t_data *data)
{
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
	ft_rotate_cam(keycode, data);
	ft_rotate_obj(keycode, data);
	ft_print_data(data);
	ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
    printf("key = %d\n", keycode);
    return (0);
}

int ft_mouse_hook(int button, int x, int y, t_data *data)
{
    if (button == 4) // Scroll upc
        data->cam.pos.z += 1.0;
    if (button == 5) // Scroll down
        data->cam.pos.z -= 1.0;
	ft_print_data(data);
	ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
    return (0);
}
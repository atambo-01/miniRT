/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 17:46:42 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int ft_print_vec3(t_vec3 *vec)
{
    printf("\t\t%.4f\t%.4f\t%.4f\n", vec->x, vec->y, vec->z);
    return (0);
}

int ft_print_cam(t_cam *cam)
{
    printf("Camera:\n");
    printf("  Pos:\t");
    ft_print_vec3(&cam->pos);
    printf("  Dir:\t");
    ft_print_vec3(&cam->dir);
    printf("  FOV:\t%.2f degrees\n", cam->fov);
    return (0);
}

int ft_print_obj(t_obj *obj)
{
    printf("Objects:\n");
    while (obj)
    {
        printf("  Type:\t%c\n", obj->type);
        printf("  Center:");
        ft_print_vec3(&obj->center);
        printf("  Dir:\t");
        ft_print_vec3(&obj->dir);
        printf("  Radius:\t%.2f\n", obj->radius);
        printf("  Length:\t%.2f\n", obj->len);
        printf("  Color:\t0x%06X\n", obj->color);
        obj = obj->next;
    }
    return (0);
}

int ft_print_data(t_data *data)
{
    system("clear");
    printf("-----------------------------------------\n");
    printf("\t\t\tx\ty\tz\n");
    ft_print_cam(&data->cam);
    ft_print_obj(data->obj);
    printf("-----------------------------------------\n");
    return (0);
}

int ft_rotate_obj(int keycode, t_data *data)
{
	float angle = 15.0 * M_PI / 180; // 5 degrees in radians
	if (keycode == 120) // x
    {
        data->obj->dir.x += 0.1;
        ft_normalize(&data->obj->dir);
        ft_print_vec3(&data->obj->dir); // Debug
    }
    if (keycode == 121) // y
    {
        data->obj->dir.y += 0.1;
        ft_normalize(&data->obj->dir);
        ft_print_vec3(&data->obj->dir); // Debug
    }
	if (keycode == 122) // z (rotate around Z-axis)
    {
        float tmp = data->obj->dir.x;
        data->obj->dir.x = tmp * cos(angle) - data->obj->dir.y * sin(angle);
        data->obj->dir.y = tmp * sin(angle) + data->obj->dir.y * cos(angle);
        ft_normalize(&data->obj->dir);
        ft_print_vec3(&data->obj->dir);
	}
}
int ft_rotate_cam(int keycode, t_data *data)
{
	if (keycode == 113)
	{
		float tmp = data->cam.dir.x;
		data->cam.dir.x = tmp * cos(0.1) + data->cam.dir.z * sin(0.1);
		data->cam.dir.z = -tmp * sin(0.1) + data->cam.dir.z * cos(0.1);
		ft_normalize(&data->cam.dir);
	}
	if (keycode == 113) // Q
    {
        float tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(0.157) + data->cam.dir.z * sin(0.157);
        data->cam.dir.z = -tmp * sin(0.157) + data->cam.dir.z * cos(0.157);
        ft_normalize(&data->cam.dir);
    }
    if (keycode == 101) // E
    {
        float tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(-0.157) + data->cam.dir.z * sin(-0.157);
        data->cam.dir.z = -tmp * sin(-0.157) + data->cam.dir.z * cos(-0.157);
        ft_normalize(&data->cam.dir);
    }
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
	ft_rotate_cam(keycode, data);
	ft_rotate_obj(keycode, data);
	ft_print_data(data);
	ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
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
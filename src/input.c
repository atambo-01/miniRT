/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/05/06 15:34:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ft_rotate_obj_z(int keycode, t_obj *obj)
{
    float angle = 15.0 * M_PI / 180.0;
    float tmp_x, tmp_ux;

    if (keycode == 'b') // Numpad 1: +15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) - obj->dir.y * sin(angle);
        obj->dir.y = tmp_x * sin(angle) + obj->dir.y * cos(angle);
        obj->u.x = tmp_ux * cos(angle) - obj->u.y * sin(angle);
        obj->u.y = tmp_ux * sin(angle) + obj->u.y * cos(angle);
    }
    else if (keycode == 'm') // Numpad 3: -15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) + obj->dir.y * sin(angle);
        obj->dir.y = -tmp_x * sin(angle) + obj->dir.y * cos(angle);
        obj->u.x = tmp_ux * cos(angle) + obj->u.y * sin(angle);
        obj->u.y = -tmp_ux * sin(angle) + obj->u.y * cos(angle);
    }
    if (keycode == 65436 || keycode == 65435)
    {
        ft_normalize(&obj->dir);
        ft_normalize(&obj->u);
        ft_print_vec3(&obj->dir);
    }
}

void ft_rotate_obj_y(int keycode, t_obj *obj)
{
    float angle = 15.0 * M_PI / 180.0;
    float tmp_x, tmp_ux;

    if (keycode == 'g') // Numpad 4: +15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) - obj->dir.z * sin(angle);
        obj->dir.z = tmp_x * sin(angle) + obj->dir.z * cos(angle);
        obj->u.x = tmp_ux * cos(angle) - obj->u.z * sin(angle);
        obj->u.z = tmp_ux * sin(angle) + obj->u.z * cos(angle);
    }
    else if (keycode == 'j') // Numpad 6: -15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) + obj->dir.z * sin(angle);
        obj->dir.z = -tmp_x * sin(angle) + obj->dir.z * cos(angle);
        obj->u.x = tmp_ux * cos(angle) + obj->u.z * sin(angle);
        obj->u.z = -tmp_ux * sin(angle) + obj->u.z * cos(angle);
    }
    if (keycode == 65430 || keycode == 65432)
    {
        ft_normalize(&obj->dir);
        ft_normalize(&obj->u);
        ft_print_vec3(&obj->dir);
    }
}

void ft_rotate_obj_x(int keycode, t_obj *obj)
{
    float angle = 15.0 * M_PI / 180.0;
    float tmp_y, tmp_uy;

    if (keycode == 't') // Numpad 7: +15°
    {
        tmp_y = obj->dir.y;
        tmp_uy = obj->u.y;
        obj->dir.y = tmp_y * cos(angle) - obj->dir.z * sin(angle);
        obj->dir.z = tmp_y * sin(angle) + obj->dir.z * cos(angle);
        obj->u.y = tmp_uy * cos(angle) - obj->u.z * sin(angle);
        obj->u.z = tmp_uy * sin(angle) + obj->u.z * cos(angle);
    }
    else if (keycode == 'u') // Numpad 9: -15°
    {
        tmp_y = obj->dir.y;
        tmp_uy = obj->u.y;
        obj->dir.y = tmp_y * cos(angle) + obj->dir.z * sin(angle);
        obj->dir.z = -tmp_y * sin(angle) + obj->dir.z * cos(angle);
        obj->u.y = tmp_uy * cos(angle) + obj->u.z * sin(angle);
        obj->u.z = -tmp_uy * sin(angle) + obj->u.z * cos(angle);
    }
    if (keycode == 65429 || keycode == 65434)
    {
        ft_normalize(&obj->dir);
        ft_normalize(&obj->u);
        ft_print_vec3(&obj->dir);
    }
}

void ft_rotate_obj(int keycode, t_obj *obj)
{
	if (!obj)
		return ;
    ft_rotate_obj_x(keycode, obj);
    ft_rotate_obj_y(keycode, obj);
    ft_rotate_obj_z(keycode, obj);
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
void ft_switch_obj(t_data *data, int x, int y)
{
    float   tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
    float   view_width = 2.0 * tan_half_fov;
    float   aspect_ratio = (float)IM_WIDTH / IM_HEIGHT;
    float   view_height = view_width / aspect_ratio;
    t_hit   *hit;

	hit = NULL;
    if (x < 0 || y < 0) // Cycle through objects
    {
        if (!data->curr) // Reset to head if NULL
            data->curr = data->obj;
        else if (data->curr->next)
            data->curr = data->curr->next;
        else
            data->curr = data->obj;
    }
	else
	{
		float u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * tan_half_fov;
		float v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * view_height / 2.0;
		t_vec3 ray_dir = {u, v, 1.0};
		ft_normalize(&ray_dir);
		hit = ft_calc_hit(data->cam.pos, ray_dir, data->obj);
		if (hit != NULL) // Valid hit
			data->curr = hit->obj;
		free(hit);
	}
}

void	ft_obj_size(t_data *data, float i)
{
	if (!data->curr)
		return ;
	data->curr->radius += (i / 100) * data->curr->radius;
}


int ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_window(data);
	if (keycode == 'w')
		data->cam.pos.y += 1;
	if (keycode == 's')
		data->cam.pos.y -= 1;
	if (keycode == 'a')
		data->cam.pos.x -= 1;
	if (keycode == 'd')
		data->cam.pos.x += 1;
	if (keycode == 32)
		ft_switch_obj(data, -1, -1);
	if (keycode == 'i')
		ft_obj_size(data, 10.0);
	if (keycode == 'k')
		ft_obj_size(data, -10.0);
	ft_rotate_cam(keycode, data);
	ft_rotate_obj(keycode, data->curr);
	ft_print_data(data);
	ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
    printf("key = %d (%c)\n", keycode, keycode);
    return (0);
}

int ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4) // Scroll upc
		data->cam.pos.z += 1.0;
    if (button == 5) // Scroll down
		data->cam.pos.z -= 1.0;
	if (button == 1)
		ft_switch_obj(data, x, y);
	if (button == 3);
	ft_print_data(data);
	ft_render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	printf("mouse_hook = %d\n", button);
    return (0);
}


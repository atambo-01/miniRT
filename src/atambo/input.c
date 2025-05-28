/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/05/28 14:59:12 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_rotate_obj_z(int key, t_obj *obj)
{
    double angle = 15.0 * M_PI / 180.0;
    double tmp_x, tmp_ux;

    if (key == 'b' || key == 65436) // Numpad 1: +15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) - obj->dir.y * sin(angle);
        obj->dir.y = tmp_x * sin(angle) + obj->dir.y * cos(angle);
        obj->u.x = tmp_ux * cos(angle) - obj->u.y * sin(angle);
        obj->u.y = tmp_ux * sin(angle) + obj->u.y * cos(angle);
    }

    else if (key == 'm' || key == 65435) // Numpad 3: -15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) + obj->dir.y * sin(angle);
        obj->dir.y = -tmp_x * sin(angle) + obj->dir.y * cos(angle);
        obj->u.x = tmp_ux * cos(angle) + obj->u.y * sin(angle);
        obj->u.y = -tmp_ux * sin(angle) + obj->u.y * cos(angle);
    }
}

void ft_rotate_obj_y(int key, t_obj *obj)
{
    double angle = 15.0 * M_PI / 180.0;
    double tmp_x, tmp_ux;

    if (key == 'g' || key == 65430) // Numpad 4: +15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) - obj->dir.z * sin(angle);
        obj->dir.z = tmp_x * sin(angle) + obj->dir.z * cos(angle);
        obj->u.x = tmp_ux * cos(angle) - obj->u.z * sin(angle);
        obj->u.z = tmp_ux * sin(angle) + obj->u.z * cos(angle);
    }
    else if (key == 'j' || key == 65432) // Numpad 6: -15°
    {
        tmp_x = obj->dir.x;
        tmp_ux = obj->u.x;
        obj->dir.x = tmp_x * cos(angle) + obj->dir.z * sin(angle);
        obj->dir.z = -tmp_x * sin(angle) + obj->dir.z * cos(angle);
        obj->u.x = tmp_ux * cos(angle) + obj->u.z * sin(angle);
        obj->u.z = -tmp_ux * sin(angle) + obj->u.z * cos(angle);
    }
}

void ft_rotate_obj_x(int key, t_obj *obj)
{
    double angle = 15.0 * M_PI / 180.0;
    double tmp_y, tmp_uy;

    if (key == 't' || key == 65429) // Numpad 7: +15°
    {
        tmp_y = obj->dir.y;
        tmp_uy = obj->u.y;
        obj->dir.y = tmp_y * cos(angle) - obj->dir.z * sin(angle);
        obj->dir.z = tmp_y * sin(angle) + obj->dir.z * cos(angle);
        obj->u.y = tmp_uy * cos(angle) - obj->u.z * sin(angle);
        obj->u.z = tmp_uy * sin(angle) + obj->u.z * cos(angle);
    }
    else if (key == 'u' || key == 65434) // Numpad 9: -15°
    {
        tmp_y = obj->dir.y;
        tmp_uy = obj->u.y;
        obj->dir.y = tmp_y * cos(angle) + obj->dir.z * sin(angle);
        obj->dir.z = -tmp_y * sin(angle) + obj->dir.z * cos(angle);
        obj->u.y = tmp_uy * cos(angle) + obj->u.z * sin(angle);
        obj->u.z = -tmp_uy * sin(angle) + obj->u.z * cos(angle);
    }
}

void ft_rotate_obj(int key, t_obj *obj)
{
	if (!obj)
		return ;
    ft_rotate_obj_x(key, obj);
    ft_rotate_obj_y(key, obj);
    ft_rotate_obj_z(key, obj);
	ft_normalize(&obj->dir);
	ft_normalize(&obj->u);
	ft_print_vec3(&obj->dir);
}

void ft_rotate_cam(int keycode, t_data *data)
{
	if (keycode == 113)
	{
		double tmp = data->cam.dir.x;
		data->cam.dir.x = tmp * cos(0.1) + data->cam.dir.z * sin(0.1);
		data->cam.dir.z = -tmp * sin(0.1) + data->cam.dir.z * cos(0.1);
	}
	if (keycode == 113) // Q
    {
        double tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(0.157) + data->cam.dir.z * sin(0.157);
        data->cam.dir.z = -tmp * sin(0.157) + data->cam.dir.z * cos(0.157);
    }
    if (keycode == 101) // E
    {
		double tmp = data->cam.dir.x;
        data->cam.dir.x = tmp * cos(-0.157) + data->cam.dir.z * sin(-0.157);
        data->cam.dir.z = -tmp * sin(-0.157) + data->cam.dir.z * cos(-0.157);
    }
    ft_normalize(&data->cam.dir);
}

void ft_switch_obj_point(t_data *data, int x, int y, t_ray *ray)
{
    x = x * ((double)IM_WIDTH / W_WIDTH);
    y = y * ((double)IM_HEIGHT / W_HEIGHT);
    ft_init_ray(data, ray);
    ft_calc_ray(x, y, ray);
    t_hit hit;

    ray->dir.x = ray->u;
    ray->dir.y = ray->v;
    ray->dir.z = 1.0;
    ft_normalize(&(ray->dir));
	ft_hit_init(&hit);
    ft_calc_hit(*ray, data->obj, &hit);
    if (hit.t > 0) // Valid hit
        data->curr = hit.obj;
	else
		data->curr = NULL;
}

void ft_switch_obj(t_data *data, int x, int y)
{
	t_ray	ray;
	
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
		ft_switch_obj_point(data, x, y, &ray);
}

void	ft_obj_size(int key, t_data *data, double i)
{
	if (!data->curr)
		return ;
	if (key == 'i' || key == 'k')
		data->curr->radius += (i / 100) * data->curr->radius;
	else if (key == 'o' || key == 'l')
		data->curr->len += (i / 100) * data->curr->radius;
}
void ft_move_x(t_data *data, double i)
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

void ft_move_y(t_data *data, double i)
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

void ft_move_z(t_data *data, double i)
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

int ft_key_hook_3(int key, t_data *data)
{
	if (key == '1')
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

int ft_key_hook_2(int key, t_data *data)
{
	if (key == 32)
		ft_switch_obj(data, -42.0, -42.0);
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
	else
		ft_key_hook_3(key, data);
	return (0);
}

int ft_key_hook(int key, t_data *data)
{
	if (key == '.')
		data->curr = NULL;
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
	ft_rotate_cam(key, data);
	ft_rotate_obj(key, data->curr);
	ft_print_data(data);
	ft_render_and_upscale(data, UPSCALE);
    printf("key = %d (%c)\n", key, key);
    return (0);
}

int ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4) // Scroll upc
		ft_move_z(data, +1.0);
    if (button == 5) // Scroll down
		ft_move_z(data, -1.0);
	if (button == 1)
		ft_switch_obj(data, x, y);
	if (button == 3);
		ft_print_data(data);
	ft_render_and_upscale(data, UPSCALE);
	printf("mouse_hook = %d\n", button);
    return (0);
}


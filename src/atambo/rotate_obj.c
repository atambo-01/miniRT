/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:22:49 by atambo            #+#    #+#             */
/*   Updated: 2025/06/09 18:56:15 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_rotate_obj_z(int key, t_obj *obj)
{
	double	angle;
	double	tmp_z;
	double	tmp_uz;

	angle = 15.0 * M_PI / 180.0;
	tmp_z = obj->dir.x;
	tmp_uz = obj->u.x;
	if (key == 'b' || key == NUMPAD_1)
	{
		obj->dir.x = tmp_z * cos(angle) - obj->dir.y * sin(angle);
		obj->dir.y = tmp_z * sin(angle) + obj->dir.y * cos(angle);
		obj->u.x = tmp_uz * cos(angle) - obj->u.y * sin(angle);
		obj->u.y = tmp_uz * sin(angle) + obj->u.y * cos(angle);
	}
	else
	{
		obj->dir.x = tmp_z * cos(angle) + obj->dir.y * sin(angle);
		obj->dir.y = -tmp_z * sin(angle) + obj->dir.y * cos(angle);
		obj->u.x = tmp_uz * cos(angle) + obj->u.y * sin(angle);
		obj->u.y = -tmp_uz * sin(angle) + obj->u.y * cos(angle);
	}
	ft_normalize(&obj->dir);
	ft_normalize(&obj->u);
}

void	ft_rotate_obj_y(int key, t_obj *obj)
{
	double	angle;
	double	tmp_x;
	double	tmp_ux;

	angle = 15.0 * M_PI / 180.0;
	tmp_x = obj->dir.x;
	tmp_ux = obj->u.x;
	if (key == 'g' || key == NUMPAD_4)
	{
		obj->dir.x = tmp_x * cos(angle) - obj->dir.z * sin(angle);
		obj->dir.z = tmp_x * sin(angle) + obj->dir.z * cos(angle);
		obj->u.x = tmp_ux * cos(angle) - obj->u.z * sin(angle);
		obj->u.z = tmp_ux * sin(angle) + obj->u.z * cos(angle);
	}
	else
	{
		obj->dir.x = tmp_x * cos(angle) + obj->dir.z * sin(angle);
		obj->dir.z = -tmp_x * sin(angle) + obj->dir.z * cos(angle);
		obj->u.x = tmp_ux * cos(angle) + obj->u.z * sin(angle);
		obj->u.z = -tmp_ux * sin(angle) + obj->u.z * cos(angle);
	}
	ft_normalize(&obj->dir);
	ft_normalize(&obj->u);
}

void	ft_rotate_obj_x(int key, t_obj *obj)
{
	double	angle;
	double	tmp_y;
	double	tmp_uy;

	angle = 15.0 * M_PI / 180.0;
	tmp_y = obj->dir.y;
	tmp_uy = obj->u.y;
	if (key == 't' || key == NUMPAD_7)
	{
		obj->dir.y = tmp_y * cos(angle) - obj->dir.z * sin(angle);
		obj->dir.z = tmp_y * sin(angle) + obj->dir.z * cos(angle);
		obj->u.y = tmp_uy * cos(angle) - obj->u.z * sin(angle);
		obj->u.z = tmp_uy * sin(angle) + obj->u.z * cos(angle);
	}
	else
	{
		obj->dir.y = tmp_y * cos(angle) + obj->dir.z * sin(angle);
		obj->dir.z = -tmp_y * sin(angle) + obj->dir.z * cos(angle);
		obj->u.y = tmp_uy * cos(angle) + obj->u.z * sin(angle);
		obj->u.z = -tmp_uy * sin(angle) + obj->u.z * cos(angle);
	}
	ft_normalize(&obj->dir);
	ft_normalize(&obj->u);
}

void	ft_rotate_obj(int key, t_obj *obj)
{
	if (!obj)
		return ;
	if (key == 't' || key == NUMPAD_7 || key == 'u' || key == NUMPAD_9)
		ft_rotate_obj_x(key, obj);
	else if (key == 'g' || key == NUMPAD_4 || key == 'j' || key == NUMPAD_6)
		ft_rotate_obj_y(key, obj);
	if (key == 'b' || key == NUMPAD_1 || key == 'm' || key == NUMPAD_3)
		ft_rotate_obj_z(key, obj);
}

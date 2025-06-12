/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:38:59 by atambo            #+#    #+#             */
/*   Updated: 2025/06/12 19:58:44 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	print_debug_sp(t_obj *obj)
{
	printf(
		"/---- Sphere ----/\n"
		"COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"Radius = %.1lf\n"
		"COLOR = %d,%d,%d\n\n",
		obj->pos.x, obj->pos.y, obj->pos.z,
		obj->radius,
		obj->color.r, obj->color.g, obj->color.b);
}

void	print_debug_pl(t_obj *obj)
{
	printf(
		"/---- Plane ----/\n"
		"COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"COLOR = %d,%d,%d\n\n",
		obj->pos.x, obj->pos.y, obj->pos.z,
		obj->dir.x, obj->dir.y, obj->dir.z,
		obj->color.r, obj->color.g, obj->color.b);
}

void	print_debug_cy(t_obj *obj)
{
	printf(
		"/---- Cylinder ----/\n"
		"COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n",
		"DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n",
		"Radius = %.1lf\n",
		"Height = %.1lf\n",
		"COLOR = %d,%d,%d\n\n",
		obj->pos.x, obj->pos.y, obj->pos.z,
		obj->dir.x, obj->dir.y, obj->dir.z,
		obj->radius,
		obj->len,
		obj->color.r, obj->color.g, obj->color.b);
}

void	print_debug_obj(t_obj *obj)
{
	while (obj)
	{
		if (!ft_strcmp(obj->type, "pl"))
			print_debug_pl(obj);
		else if (!ft_strcmp(obj->type, "sp"))
			print_debug_sp(obj);
		else if (!ft_strcmp(obj->type, "cy"))
			print_debug_cy(obj);
		obj = obj->next;
	}
}

void	print_debug_info(t_data data)
{
	printf(
		"Good Map\n\n/-------- Ambient Lighting --------/\n"
		"Ratio = %.1lf\n"
		"COLOR = %d,%d,%d\n\n"
		"/-------- Camera --------/\n"
		"COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"FOV = %f\n\n"
		"/-------- Light --------/\n"
		"COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n"
		"Light Brightness ratio = %.1lf\n"
		"COLOR = %d,%d,%d\n\n"
		"/-------------- OBJECTS --------------/\n",
		data.alight.ratio,
		data.alight.color.r, data.alight.color.g, data.alight.color.b,
		data.cam.pos.x, data.cam.pos.y, data.cam.pos.z,
		data.cam.dir.x, data.cam.dir.y, data.cam.dir.z,
		data.cam.fov,
		data.light.pos.x, data.light.pos.y, data.light.pos.z,
		data.light.ratio,
		data.light.color.r, data.light.color.g, data.light.color.b);
	print_debug_obj(data.obj);
	printf("\n");
}

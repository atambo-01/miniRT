/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:38:59 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 14:21:39 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void print_debug_sp(t_obj *obj)
{
	printf("/---- Sphere ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("Radius = %.1lf\n", obj->radius);
	printf("COLOR = %d,%d,%d\n", obj->color.r,obj->color.g, obj->color.b);
	printf("\n");
}

void print_debug_pl(t_obj *obj)
{
	printf("/---- Plane ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->dir.x,
		   obj->dir.y, obj->dir.z);
	printf("COLOR = %d,%d,%d\n", obj->color.r,obj->color.g, obj->color.b);
	printf("\n");
}

void print_debug_cy(t_obj *obj)
{
	printf("/---- Cylinder ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->dir.x,
		   obj->dir.y, obj->dir.z);
	printf("Radius = %.1lf\n", obj->radius);
	printf("Height = %.1lf\n", obj->len);
	printf("COLOR = %d,%d,%d\n", obj->color.r,obj->color.g, obj->color.b);
	printf("\n");
}

void print_debug_obj(t_obj *obj)
{
	while(obj)
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

void print_debug_info(t_data data)
{
    printf("Good Map\n");
    printf("\n");
    printf("/-------- Ambient Lighting --------/\n");
    printf("Ratio = %.1lf\n", data.alight.ratio);
	printf("COLOR = %d,%d,%d\n", data.alight.color.r, data.alight.color.g, data.alight.color.b);
    printf("\n");
    printf("/-------- Camera --------/\n");
    printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.pos.x,
           data.cam.pos.y, data.cam.pos.z);
    printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.dir.x,
           data.cam.dir.y, data.cam.dir.z);
    printf("FOV = %f\n", data.cam.fov);
    printf("\n");
    printf("/-------- Light --------/\n");
    printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.light.pos.x,
           data.light.pos.y, data.light.pos.z);
    printf("Light Brightness ratio = %.1lf\n", data.light.ratio);
	printf("COLOR = %d,%d,%d\n", data.light.color.r, data.light.color.g, data.light.color.b);
    printf("\n");
    printf("/-------------- OBJECTS --------------/\n");
	print_debug_obj(data.obj);
	printf("\n");
}
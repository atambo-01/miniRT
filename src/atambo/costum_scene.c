/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costum_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:35:42 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 20:39:24 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"

    // t_obj *obj_3 = malloc(sizeof(t_obj));
    // if (!obj_3)
    //     return (-1);
    // obj_3->type = ft_strdup("sp"); // Sphere (bottom-left)
    // ft_setvec3(&obj_3->center, -0.5, -0.375, 15);
    // ft_setvec3(&obj_3->dir, 0, 0, 1);
    // ft_setvec3(&obj_3->u, 0, 1, 0);
    // ft_normalize(&obj_3->dir);
    // obj_3->radius = 0.3;
    // obj_3->len = 0;
    // obj_3->color = 0xab2929; // Red
    // obj_3->next = NULL;
    // obj_2->next = obj_3;

int ft_init_light(t_data *data)
{
	ft_setvec3(&data->light.center, -0.5, -0.375, 1500000);
	data->light.ratio = 1.0;
	data->light.color = 0xffffff;
	data->light.radius = 0.5;
	return (0);
}

int ft_init_room_planes(t_obj *obj_4, t_data *data)
{
    t_obj *obj_5 = malloc(sizeof(t_obj));
    if (!obj_5)
        return (-1);
    obj_5->type = ft_strdup("pl"); // Right wall
    ft_setvec3(&obj_5->center, 5, 0, 15);
    ft_setvec3(&obj_5->dir, -1, 0, 0);
    ft_setvec3(&obj_5->u, 0, 1, 0);
    ft_normalize(&obj_5->dir);
    obj_5->radius = 10;
    obj_5->len = 0;
    obj_5->color = 0x717575; // Grey
    obj_5->next = NULL;
    obj_4->next = obj_5;

	t_obj *obj_6 = malloc(sizeof(t_obj));
    if (!obj_6)
        return (-1);
    obj_6->type = ft_strdup("pl"); // Right wall
    ft_setvec3(&obj_6->center, -5, 0, 15);
    ft_setvec3(&obj_6->dir, 1, 0, 0);
    ft_setvec3(&obj_6->u, 0, 1, 0);
    ft_normalize(&obj_6->dir);
    obj_6->radius = 10;
    obj_6->len = 0;
    obj_6->color = 0x717575; // Grey
    obj_6->next = NULL;
    obj_5->next = obj_6;

	t_obj *obj_7 = malloc(sizeof(t_obj));
    if (!obj_7)
        return (-1);
    obj_7->type = ft_strdup("pl"); // Right wall
    ft_setvec3(&obj_7->center, 0, 0, 15);
    ft_setvec3(&obj_7->dir, 0, 0, -1);
    ft_setvec3(&obj_7->u, 0, 1, 0);
    ft_normalize(&obj_7->dir);
    obj_7->radius = 10;
    obj_7->len = 0;
    obj_7->color = 0x5d6161; // Grey
    obj_7->next = NULL;
    obj_6->next = obj_7;

    // data->curr = data->obj;
	return(ft_init_light(data));
}

int ft_init_obj(t_data *data)
{
	t_obj *obj_2 = malloc(sizeof(t_obj));
    if (!obj_2)
		return (-1);
    obj_2->type = ft_strdup("cub"); // Cube (top-right)
    ft_setvec3(&obj_2->center, 0.5, 0.375, 10);
    ft_setvec3(&obj_2->dir, 0, 0, 1);
    ft_setvec3(&obj_2->u, 0, 1, 0);
    ft_normalize(&obj_2->dir);
    obj_2->radius = 0.25;
    obj_2->len = 0;
    obj_2->color = 0x29c261; // Blue
    obj_2->next = NULL;
	
    data->obj = obj_2;

	return (ft_init_room_planes(obj_2, data));
}
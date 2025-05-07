/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:15:19 by atambo            #+#    #+#             */
/*   Updated: 2025/05/07 02:39:30 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_count_obj(t_obj *obj)
{
	int	i;

	i = 0;
	while (obj)
	{
		i++;
		obj = obj->next;
	}
	return (i);
}

int	ft_print_vec3(t_vec3 *vec)
{
	printf("\t%.4f\t%.4f\t%.4f\n", vec->x, vec->y, vec->z);
	return (0);
}

int ft_print_cam(t_cam *cam)
{
	printf("Camera:\n");
	printf("  Pos:\t");
	ft_print_vec3(&cam->pos);
	printf("  Dir:\t");
	ft_print_vec3(&cam->dir);
	printf("  FOV:\t\t%.2f degrees\n", cam->fov);
	return (0);
}

int ft_print_obj(t_obj *obj)
{
    printf("Object:\n");
	printf("  Type:\t%s\n", obj->type);
	printf("  Center:");
	ft_print_vec3(&obj->center);
	printf("  Dir:\t");
	ft_print_vec3(&obj->dir);
	printf("  U:\t");
	ft_print_vec3(&obj->u);
	printf("  Radius:\t%.2f\n", obj->radius);
	printf("  Length:\t%.2f\n", obj->len);
	printf("  Color:\t0x%06X\n", obj->color);
    return (0);
}

int ft_print_data(t_data *data)
{
    system("clear");
    printf("-----------------------------------------\n");
    printf("\t\tx\ty\tz\n");
    ft_print_cam(&data->cam);
	if (data->curr)
		ft_print_obj(data->curr);
	printf("obj_count = \t%d\n",ft_count_obj(data->obj));
    printf("-----------------------------------------\n");
	printf("Render time: %.2f ms\n", ft_get_speed(data->start, data->end));
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:15:19 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 16:51:04 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_print_obj(t_obj *obj)
{
	printf("Object:\n");
	printf("  Type:\t\t%s\n", obj->type);
	printf("  pos:\t");
	ft_print_vec3(&obj->pos);
	printf("  Dir:\t");
	ft_print_vec3(&obj->dir);
	printf("  U:\t");
	ft_print_vec3(&obj->u);
	printf("  Radius:\t%.2f\n", obj->radius);
	printf("  Length:\t%.2f\n", obj->len);
	ft_print_t_color(obj->color);
	return (0);
}

int	ft_print_vec3(t_vec3 *vec)
{
	printf("\t%+06.2f  %+06.2f  %+06.2f\n", vec->x, vec->y, vec->z);
	return (0);
}

int	ft_print_data(t_data *data)
{
	system("clear");
	printf("-----------------------------------------\n");
	printf("\t\tx\ty\tz\n");
	ft_print_alight(&data->alight);
	ft_print_cam(&data->cam);
	ft_print_light(&data->light);
	printf("obj_count = \t%d\n", ft_count_obj(data->obj));
	if (data->curr)
		ft_print_obj(data->curr);
	printf("-----------------------------------------\n");
	printf(" Focus = %d\n", data->focus);
	printf(" Curr = %p\n", data->curr);
	printf(" Curr_ligth = %p\n", data->curr_light);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:09:44 by atambo            #+#    #+#             */
/*   Updated: 2025/05/06 17:09:25 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	ft_free_obj(t_obj *obj)
{
	t_obj	*temp;

	temp = NULL;
	while (obj)
	{
		temp = obj;
		obj = obj->next;
		free(temp->type);
		free(temp);
	}
	obj = NULL;
}

void ft_quit_mlx(t_data *data)
{
    if (!data || !data->mlx)
        return;
    if (data->img.ptr)
        mlx_destroy_image(data->mlx, data->img.ptr);
    if (data->s_img.ptr)
        mlx_destroy_image(data->mlx, data->s_img.ptr);
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    data->mlx = NULL;
    data->win = NULL;
    data->img.ptr = NULL;
    data->s_img.ptr = NULL;
}

int	ft_exit_minirt(t_data *data)
{
	ft_free_obj(data->obj);
	ft_quit_mlx(data);
	if (data->err)
		ft_minirt_error(data->err, 1);
	exit(0);
}

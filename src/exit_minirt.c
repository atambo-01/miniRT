/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:09:44 by atambo            #+#    #+#             */
/*   Updated: 2025/05/05 19:47:37 by atambo           ###   ########.fr       */
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

void	ft_quit_mlx(t_data *data)
{
	if (&(data->img))
		mlx_destroy_image(data->mlx, &(data->img));
	if (&(data->s_img))
		mlx_destroy_image(data->mlx, &(data->s_img));
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_exit_minirt(t_data *data, char *err)
{
	ft_free_obj(data->obj);
	ft_quit_mlx(data);
	ft_minirt_error(err, 1);
	exit(0);
}
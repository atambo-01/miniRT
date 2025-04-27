/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:13:05 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 17:33:41 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_init_obj(t_data *data)
{	
	t_obj *obj;

	obj = malloc(sizeof(t_obj));
	data->obj = obj;
	data->obj->type = 'P';
	ft_setvec3(&data->obj->center, 0, 0, 15);
	ft_setvec3(&data->obj->dir, 0.7, 0, 0.7);
	data->obj->radius = 10;
	data->obj->len = 10;
	data->obj->color = 0x2d57cc;
	data->obj->next = NULL;
	return (0);
}

int ft_init_cam(t_data *data)
{
	ft_setvec3(&data->cam.pos, 0, 0, -10);
	ft_setvec3(&data->cam.dir, 0, 0, 1);
    data->cam.fov = 60.0;
	return (ft_init_obj(data));
}

int ft_init_data(t_data *data, int fd)
{
	data->fd = fd;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "fract-ol");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data);
		exit(1);
	}
	data->img.ptr = mlx_new_image(data->mlx, IM_WIDTH, IM_HEIGHT);
	data->s_img.ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
    if (!data->img.ptr || !data->s_img.ptr)
        exit(ft_perror("Failed to create render image", 1));
    data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, 
		&data->img.line_len, &data->img.endian);
	data->s_img.addr = mlx_get_data_addr(data->s_img.ptr, &data->s_img.bpp, 
		&data->s_img.line_len, &data->s_img.endian);
	return(ft_init_cam(data));
}

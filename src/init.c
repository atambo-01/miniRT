/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:13:05 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 04:05:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	return (0);
}

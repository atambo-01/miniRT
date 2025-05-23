/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:13:05 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 16:17:41 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"

int	ft_init_cam(t_data *data)
{
	ft_setvec3(&data->cam.pos, 0, 0, -15);
	ft_setvec3(&data->cam.dir, 0, 0, 1);
	data->cam.fov = 60.0;
	return (ft_init_obj(data));
}

int	ft_init_data(t_data *data, int fd)
{
	data->fd = fd;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(ft_perror("Failed to init mlw connection\n", 1));
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "miniRT");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(ft_perror("Failed to init mlw window\n", 1));
	}
	data->img.ptr = mlx_new_image(data->mlx, IM_WIDTH, IM_HEIGHT);
	data->s_img.ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img.ptr || !data->s_img.ptr)
		exit(ft_perror("Failed to create mlx image\n", 1));
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->s_img.addr = mlx_get_data_addr(data->s_img.ptr, &data->s_img.bpp,
			&data->s_img.line_len, &data->s_img.endian);
	data->curr = NULL;
	data->err = NULL;
	return (ft_init_cam(data));
}

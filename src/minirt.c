/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:58 by atambo            #+#    #+#             */
/*   Updated: 2025/05/01 16:24:36 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int ft_loop_hook(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
    mlx_put_image_to_window(data->mlx, data->win, data->s_img.ptr, 0, 0);
    return (0);
}

int main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = ft_check_file(ac, av);
	ft_init_data(&data, fd);
	close(fd);
	ft_render_scene(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.ptr, 0, 0);
	mlx_mouse_hook(data.win, ft_mouse_hook, &data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_close_window, &data);
	mlx_loop (data.mlx);
	return (0);
}

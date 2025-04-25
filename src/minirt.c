/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:58 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 04:39:38 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int loop_hook(t_data *data)
{
    static int state = 0;
    static int time = 0;

    time++;
    if (time >= 20000) // ~1 second at 60 FPS
    {
        time = 0;
        state = (state + 1) % 3; // Cycle: 0 (color), 1 (small), 2 (upscaled)
        if (state == 0)
            fill_color(data, 0xFFeb3471); // Fill with color
        else if (state == 1)
            mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
        else
            mlx_put_image_to_window(data->mlx, data->win, data->s_img.ptr, 0, 0);
    }
    return (0);
}

int main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = ft_check_file(ac, av);
	ft_init_data(&data, fd);
	fill_tiled(&data.img, &data);
	upscale_img(&data);

	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook (data.win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop (data.mlx);
	return (0);
}

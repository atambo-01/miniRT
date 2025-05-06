/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:58 by atambo            #+#    #+#             */
/*   Updated: 2025/05/06 18:04:43 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = ft_check_file(ac, av);
	ft_init_data(&data, fd);
	close(fd);
	ft_render_scene(&data);
	mlx_mouse_hook(data.win, ft_mouse_hook, &data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_exit_minirt, &data);
	mlx_loop (data.mlx);
	return (0);
}

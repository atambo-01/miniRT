/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/26 11:38:47 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/miniRT_atambo.h"
#include "../inc/miniRT_mchingi.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.obj = NULL;
	if (ac == 2)
	{
		
		fd = file_management(av[1], &data);
		if (fd > 0)
		{
			ft_init_data(&data, fd);
			print_debug_info(data);
			ft_render_and_upscale(&data, UPSCALE);
			mlx_mouse_hook(data.win, ft_mouse_hook, &data);
			mlx_key_hook(data.win, ft_key_hook, &data);
			mlx_hook(data.win, 17, 0, ft_exit_minirt, &data);
			mlx_loop (data.mlx);		}
		else 
			printf("Error reading file\n");
	}
	else
		printf("invalid number of args\n");
	return (0);
}


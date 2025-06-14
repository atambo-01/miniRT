/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/14 19:01:06 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/miniRT_atambo.h"
#include "../inc/miniRT_mchingi.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.obj = NULL;
	if (ac == 2)
	{
		if (file_management(av[1], &data))
		{
			ft_init_data_mlx(&data);
			ft_init_data_extra(&data);
			print_debug_info(data);
			ft_render_and_upscale(&data);
			mlx_mouse_hook(data.win, ft_mouse_hook, &data);
			mlx_key_hook(data.win, ft_key_hook, &data);
			mlx_hook(data.win, 17, 0, ft_exit_minirt, &data);
			mlx_loop (data.mlx);
		}
		else
			return (ft_minirt_error(E_READFILE, 1));
	}
	else if (ac > 1)
		return (ft_minirt_error(E_PARAM, 1));
	else
		return (ft_minirt_error(E_NEEDFILE, 1));
	return (0);
}

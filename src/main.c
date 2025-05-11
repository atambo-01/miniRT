/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/11 16:01:24 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
/*
int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_mlx	mlx;
	t_img	img;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, 960, 540, "Hello World!");
	
	img.init = mlx_new_image(mlx.init, 480, 270);
	img.addr = mlx_get_data_addr(img.init, &img.bpp, &img.line, &img.endian);
	ft_put_pixels(&img, 50, 50, 200, 0x0000FF);
	// draw_gradient(&img, 400, 270);
	mlx_put_image_to_window(mlx.init, mlx.window, img.init, 0, 0);
	mlx_key_hook(mlx.window, input_keys, &mlx);

	mlx_loop(mlx.init);
	return (0);
}
*/
// ------------------------------------------------------------------------

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (file_management(av[1]))
			printf("Good Map\n");
	}
	else
		printf("invalid av\n");
	return (0);
}
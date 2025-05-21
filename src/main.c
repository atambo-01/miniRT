/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/21 12:24:34 by mchingi          ###   ########.fr       */
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
	t_data data;
	
	if (ac == 2)
	{
		if (file_management(av[1], &data))
			printf("Good Map\n");
		printf("\n");
		printf("/-------- Ambient Lighting --------/\n");
		printf("Ratio = %.1lf\n", data.scenario.ambient_light.light_ratio);
		printf("COLOR\nR = %d\nB = %d\nG = %d\n", data.scenario.ambient_light.color.r, \
			data.scenario.ambient_light.color.b, data.scenario.ambient_light.color.g);
		printf("\n");
		printf("/-------- Camera --------/\n");
		printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.scenario.cam.pos.x, \
			data.scenario.cam.pos.y,data.scenario.cam.pos.z);
		printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.scenario.cam.dir.x, \
			data.scenario.cam.dir.y, data.scenario.cam.dir.z);
		printf("FOV = %d\n", data.scenario.cam.fov);
		printf("\n");
		printf("/-------- Light --------/\n");
		printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.scenario.light.pos.x, \
			data.scenario.light.pos.y, data.scenario.light.pos.z);
		printf("Light Brightness ratio = %.1lf\n", data.scenario.light.bright_ratio);
		printf("\n");
	}
	else
		printf("invalid av\n");
	return (0);
}

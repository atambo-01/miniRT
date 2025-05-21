/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/21 19:27:50 by mchingi          ###   ########.fr       */
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
		{
			printf("Good Map\n");
			printf("\n");
			printf("/-------- Ambient Lighting --------/\n");
			printf("Ratio = %.1lf\n", data.ambient_light.light_ratio);
			printf("COLOR\nR = %d\nB = %d\nG = %d\n", data.ambient_light.color.r, \
				data.ambient_light.color.b, data.ambient_light.color.g);
			printf("\n");
			printf("/-------- Camera --------/\n");
			printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.pos.x, \
				data.cam.pos.y,data.cam.pos.z);
			printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.dir.x, \
				data.cam.dir.y, data.cam.dir.z);
			printf("FOV = %d\n", data.cam.fov);
			printf("\n");
			printf("/-------- Light --------/\n");
			printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.light.pos.x, \
				data.light.pos.y, data.light.pos.z);
			printf("Light Brightness ratio = %.1lf\n", data.light.bright_ratio);
			printf("\n");
			printf("\n");
			printf("/---- OBJECTS ----/\n");
			printf("\n");
			printf("/---- Sphere ----/\n");
			printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.objects.sp.center.x, 
				 data.objects.sp.center.y, data.objects.sp.center.z);
			printf("Diameter = %.1lf\n", data.objects.sp.diameter);
			printf("COLOR\nR = %d\nB = %d\nG = %d\n", data.objects.sp.colors.r, 
				data.objects.sp.colors.b, data.objects.sp.colors.g);
			printf("\n");
			printf("/---- Plane ----/\n");
			printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.objects.pl.pos.x, 
				data.objects.pl.pos.y, data.objects.pl.pos.z);
			printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.objects.pl.dir.x, 
				data.objects.pl.dir.y, data.objects.pl.dir.z);
			printf("COLOR\nR = %d\nB = %d\nG = %d\n", data.objects.pl.colors.r, 
				data.objects.pl.colors.b, data.objects.pl.colors.g);
			printf("\n");
			printf("/---- Cylinder ----/\n");
			printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.objects.cy.center.x, 
				data.objects.cy.center.y, data.objects.cy.center.z);
			printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.objects.cy.dir.x, 
				data.objects.cy.dir.y, data.objects.cy.dir.z);
			printf("Diameter = %.1lf\n", data.objects.cy.diameter);
			printf("Height = %.1lf\n", data.objects.cy.height);
			printf("COLOR\nR = %d\nB = %d\nG = %d\n", data.objects.cy.colors.r, 
				data.objects.cy.colors.b, data.objects.cy.colors.g);
		}
		else 
			printf("This shitty stink\n");
	}
	else
		printf("invalid av\n");
	return (0);
}

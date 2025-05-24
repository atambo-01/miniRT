/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 12:28:43 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_mchingi.h"

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

void print_debug_info(t_data data)
{
    printf("Good Map\n");
    printf("\n");
    printf("/-------- Ambient Lighting --------/\n");
    printf("Ratio = %.1lf\n", data.ambient_light.light_ratio);
    printf("COLOR\nR = %d\nG = %d\nB = %d\n", data.ambient_light.color.r,
           data.ambient_light.color.g, data.ambient_light.color.b);
    printf("\n");
    printf("/-------- Camera --------/\n");
    printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.pos.x,
           data.cam.pos.y, data.cam.pos.z);
    printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.cam.dir.x,
           data.cam.dir.y, data.cam.dir.z);
    printf("FOV = %f\n", data.cam.fov);
    printf("\n");
    printf("/-------- Light --------/\n");
    printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", data.light.pos.x,
           data.light.pos.y, data.light.pos.z);
    printf("Light Brightness ratio = %.1lf\n", data.light.bright_ratio);
    printf("COLOR\nR = %d\nG = %d\nB = %d\n", data.light.color.r,
           data.light.color.g, data.light.color.b);
    printf("\n");
    printf("/-------------- OBJECTS --------------/\n");
    printf("\n");

    // Print all spheres
    t_sphere *current_sp = data.objects.sp;
    int sp_count = 1;
    while (current_sp != NULL)
    {
        printf("/---- Sphere %d ----/\n", sp_count++);
        printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", current_sp->center.x,
               current_sp->center.y, current_sp->center.z);
        printf("Diameter = %.1lf\n", current_sp->diameter);
        printf("COLOR\nR = %d\nG = %d\nB = %d\n", current_sp->colors.r,
               current_sp->colors.g, current_sp->colors.b);
        printf("\n");
        current_sp = current_sp->next;
    }

    // Print all planes
    t_plane *current_pl = data.objects.pl;
    int pl_count = 1;
    while (current_pl != NULL)
    {
        printf("/---- Plane %d ----/\n", pl_count++);
        printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", current_pl->pos.x,
               current_pl->pos.y, current_pl->pos.z);
        printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", current_pl->dir.x,
               current_pl->dir.y, current_pl->dir.z);
        printf("COLOR\nR = %d\nG = %d\nB = %d\n", current_pl->colors.r,
               current_pl->colors.g, current_pl->colors.b);
        printf("\n");
        current_pl = current_pl->next;
    }

    // Print all cylinders
    t_cylinder *current_cy = data.objects.cy;
    int cy_count = 1;
    while (current_cy != NULL)
    {
        printf("/---- Cylinder %d ----/\n", cy_count++);
        printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", current_cy->center.x,
               current_cy->center.y, current_cy->center.z);
        printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", current_cy->dir.x,
               current_cy->dir.y, current_cy->dir.z);
        printf("Diameter = %.1lf\n", current_cy->diameter);
        printf("Height = %.1lf\n", current_cy->height);
        printf("COLOR\nR = %d\nG = %d\nB = %d\n", current_cy->colors.r,
               current_cy->colors.g, current_cy->colors.b);
        printf("\n");
        current_cy = current_cy->next;
    }
}

int	main(int ac, char **av)
{
	t_data data;
	
	data.objects.sp = NULL;
	data.objects.pl = NULL;
	data.objects.cy = NULL;
	if (ac == 2)
	{
		if (file_management(av[1], &data))
		{
			print_debug_info(data);
			// free(data.objects.sp);
			// free(data.objects.pl);
			// free(data.objects.cy);
		}	
		else 
			printf("This shitty stink\n");
	}
	else
		printf("invalid av\n");
	return (0);
}

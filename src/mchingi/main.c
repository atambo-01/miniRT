/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:08 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 14:45:13 by atambo           ###   ########.fr       */
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

void print_debug_sp(t_obj *obj)
{
	printf("/---- Sphere ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("Radius = %.1lf\n", obj->radius);
	printf("COLOR = %d\n", obj->color);
	printf("\n");
}

void print_debug_pl(t_obj *obj)
{
	printf("/---- Plane ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->dir.x,
		   obj->dir.y, obj->dir.z);
	printf("COLOR = %d\n", obj->color);
	printf("\n");
}

void print_debug_cy(t_obj *obj)
{
	printf("/---- Cylinder ----/\n");
	printf("COORDINATES\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->pos.x,
		   obj->pos.y, obj->pos.z);
	printf("DIRECTION\nx = %.1lf\ny = %.1lf\nz = %.1lf\n", obj->dir.x,
		   obj->dir.y, obj->dir.z);
	printf("Radius = %.1lf\n", obj->radius);
	printf("Height = %.1lf\n", obj->len);
	printf("COLOR = %d\n", obj->color);
	printf("\n");
}

void print_debug_obj(t_obj *obj)
{
	while(obj)
	{
		if (!ft_strcmp(obj->type, "pl"))
			print_debug_pl(obj);
		else if (!ft_strcmp(obj->type, "sp"))
			print_debug_sp(obj);
		else if (!ft_strcmp(obj->type, "cy"))
			print_debug_cy(obj);
		obj = obj->next;
	}
}

void print_debug_info(t_data data)
{
    printf("Good Map\n");
    printf("\n");
    printf("/-------- Ambient Lighting --------/\n");
    printf("Ratio = %.1lf\n", data.alight.ratio);
    printf("COLOR\n = %d\n", data.alight.color);
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
    printf("Light Brightness ratio = %.1lf\n", data.light.ratio);
    printf("COLOR = %d\n", data.light.color);
    printf("\n");
    printf("/-------------- OBJECTS --------------/\n");
	print_debug_obj(data.obj);
	printf("\n");
}

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac == 2)
	{
		if (file_management(av[1], &data))
			print_debug_info(data);
		else 
			printf("Error reading file\n");
	}
	else
		printf("invalid av\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/12 19:59:47 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_init_ray(t_data *data, t_ray *ray)
{
	double	view_width;
	double	asp_ratio;

	ray->o = data->cam.pos;
	ray->tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
	view_width = 2.0 * ray->tan_half_fov;
	asp_ratio = (double)IM_WIDTH / IM_HEIGHT;
	ray->view_height = view_width / asp_ratio;
	ray->lum = &data->light;
}

void	ft_calc_ray(int x, int y, t_ray *ray, t_cam *cam)
{
	double	u;
	double	v;

	u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * ray->tan_half_fov;
	v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * (ray->view_height / 2.0);
	ray->dir = cam->dir;
	ray->dir.x += u * cam->right.x + v * cam->up.x;
	ray->dir.y += u * cam->right.y + v * cam->up.y;
	ray->dir.z += u * cam->right.z + v * cam->up.z;
	ft_normalize(&ray->dir);
	ray->obj = NULL;
	ray->color = (t_color){0, 0, 0};
	ray->t = -1.0;
	ray->d = 0.0;
	ray->n = (t_vec3){1.0, 0.0, 0.0};
	ray->l = (t_vec3){1.0, 0.0, 0.0};
}

void	ft_print_ray(int x, int y, t_ray *ray)
{
	system("clear");
	printf("-----------------------------------------\n"
		"\t\t  x\t   y\t    z\n"
		"Ray:\n"
		"  Screen_pos:\t%d\t %d\n", x, y);
	printf("  3d pos:");
	ft_print_vec3(&ray->o);
	printf("  Dir:\t");
	ft_print_vec3(&ray->dir);
	printf("-----------------------------------------\n"
		"  Cam_obj(t):\t  %.2f\n",
		"  Obj_lum(d):\t  %.2f\n", ray->t, ray->d);
	if (ray->obj != NULL)
		ft_print_obj(ray->obj);
	else
		printf("  Obj = NA\n");
}

void	ft_ray_info(int x, int y, t_data *data)
{
	t_ray	ray;

	x = x * ((double)IM_WIDTH / W_WIDTH);
	y = y * ((double)IM_HEIGHT / W_HEIGHT);
	ft_init_ray(data, &ray);
	ft_calc_ray(x, y, &ray, &data->cam);
	ft_hit_obj(&ray, data->obj);
	ft_hit_light(data, &ray, &data->light);
	ray.d = ft_hit_obj_light(data, ray, &data->light);
	ft_print_ray(x, y, &ray);
}

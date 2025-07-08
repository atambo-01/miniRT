/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/07/08 17:27:47 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_init_ray(t_data *data, t_ray *ray)
{
	double	view_heigth;
	double	asp_ratio;

	ray->o = data->cam.pos;
	ray->dir = data->cam.dir;
	ray->tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
	view_heigth = 2.0 * ray->tan_half_fov;
	asp_ratio = (double)IM_WIDTH / IM_HEIGHT;
	ray->view_heigth = view_heigth / asp_ratio;
	ray->lum = &data->light;
	ray->h_fov = data->cam.fov * M_PI / 180.0f; // Horizontal FOV
	ray->v_fov = ray->h_fov / asp_ratio; // Vertical FOV
}

// void	ft_calc_ray(int x, int y, t_ray *ray, t_cam *cam)
// {
// 	double	u;
// 	double	v;

// 	u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * ray->tan_half_fov;
// 	v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * (ray->view_heigth / 2.0);
// 	ray->dir = cam->dir;
// 	ray->dir.x += u * cam->right.x + v * cam->up.x;
// 	ray->dir.y += u * cam->right.y + v * cam->up.y;
// 	ray->dir.z += u * cam->right.z + v * cam->up.z;
// 	ft_normalize(&ray->dir);
// 	ray->obj = NULL;
// 	ray->color = (t_color){0, 0, 0};
// 	ray->t = -42.0;
// 	ray->d = -42.0;
// 	ray->n = (t_vec3){1.0, 0.0, 0.0};
// 	ray->l = (t_vec3){1.0, 0.0, 0.0};
// }

void	ft_calc_ray(int x, int y, t_ray *ray, t_cam *cam)
{
    float width = (float)IM_WIDTH;
    float height = (float)IM_HEIGHT;
    
    
    // Angle for x-z plane (horizontal)
    float angle_x = ((width - 1.0f) - 2.0f * x) / (width - 1.0f) * (ray->h_fov / 2.0f);
    
    // Angle for y-z plane (vertical)
    float angle_y = ((height - 1.0f) - 2.0f * y) / (height - 1.0f) * (ray->v_fov / 2.0f);
  
    // The rotation matrix for rotating around the y-axis by θ radians is:
    // |cos(θ)	0		sin(θ)	|
    // |0		1		0		|
    // |-sin(θ)	0		cos(θ)	|

    ray->dir.x = ray->dir.x * cosf(angle_x) + ray->dir.z * sinf(angle_x);
    ray->dir.y = ray->dir.y;
    ray->dir.z = -(ray->dir.x) * sinf(angle_x) + ray->dir.z * cosf(angle_x);

    // The rotation matrix for rotating around the x-axis by θ radians is:
    // |1		0		0		|
    // |0		cos(θ)	-sin(θ)	|
    // |0		sin(θ)	cos(θ)	|

    ray->dir.x = ray->dir.x;
    ray->dir.y = ray->dir.y * cosf(angle_y) - ray->dir.z * sinf(angle_y);
    ray->dir.z = (ray->dir.y) * sinf(angle_y) + ray->dir.z * cosf(angle_y);
    
    ft_normalize(&ray->dir);
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
		"  Cam_obj(t):\t  %.2f\n"
		"  Obj_lum(d):\t  %.2f\n", ray->t, ray->d);
	if (ray->obj != NULL)
		ft_print_obj(ray->obj);
	else
		printf("  Obj = NA\n");
}

void	ft_ray_info(int x, int y, t_data *data)
{
	t_ray	ray;

	if (!data)
		return ;
	x = x * ((double)IM_WIDTH / WIDTH);
	y = y * ((double)IM_HEIGHT / HEIGTH);
	ft_init_ray(data, &ray);
	ft_calc_ray(x, y, &ray, &data->cam);
	ft_hit_obj(&ray, data->obj);
	ft_hit_light(&ray, &data->light);
	ray.d = ft_hit_obj_light(data, ray, &data->light);
	ft_print_ray(x, y, &ray);
}

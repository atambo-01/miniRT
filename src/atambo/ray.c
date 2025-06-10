/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 13:53:26 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_init_ray(t_data *data, t_ray *ray)
{
    double view_width;
    double asp_ratio;

    ray->o = data->cam.pos;
    ray->tan_half_fov = tan(data->cam.fov * M_PI / 360.0); // Note: fov/2 for half FOV
    view_width = 2.0 * ray->tan_half_fov;
    asp_ratio = (double)IM_WIDTH / IM_HEIGHT;
    ray->view_height = view_width / asp_ratio;
    ray->lum = &data->light;
}

void ft_calc_ray(int x, int y, t_ray *ray, t_cam *cam)
{
    double u, v;

	ft_memset(ray, 0, sizeof(t_ray));
    // Compute normalized device coordinates (u, v) in [-1, 1]
    u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * ray->tan_half_fov; // Scale by tan(FOV/2)
    v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * (ray->view_height / 2.0); // Scale by view_height/2

    // Compute ray direction in camera coordinate system
    ray->dir = cam->dir; // Start with view direction
    ray->dir.x += u * cam->right.x + v * cam->up.x; // Add right and up contributions
    ray->dir.y += u * cam->right.y + v * cam->up.y;
    ray->dir.z += u * cam->right.z + v * cam->up.z;

    // Normalize the ray direction
    ft_normalize(&ray->dir);

    // Initialize other ray properties
    ray->t = -1.0;
    ray->d = 0.0;
    ray->n = (t_vec3){1.0, 0.0, 0.0}; // Default normal (may be unused)
    ray->l = (t_vec3){1.0, 0.0, 0.0}; // Default light dir (may be unused)
}

void ft_print_ray(t_ray *ray)
{
	printf("Ray:\n");
	printf("  Pos:\t");
	ft_print_vec3(&ray->o);
	printf("  Dir:\t");
	ft_print_vec3(&ray->dir);
	printf("  Dist_to_obj(t):\t\t%.2f\n", ray->t);
	printf("  obj_to_light(d):\t\t%.2f\n", ray->d);
	printf("  Obj = %p\n", ray->obj);
}

void ft_ray_info(int x, int y, t_data *data)
{
	t_ray ray;

	ft_init_ray(data, &ray);
	ft_calc_ray(x, y, &ray, &data->cam);
	ft_hit_obj(&ray, data->obj);
	ft_hit_light(data, &ray, &(data->light));
	ft_print_ray(&ray);
}

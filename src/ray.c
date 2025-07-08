/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/07/08 16:18:09 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	ft_init_ray(t_data *data,int x, int y, t_ray *ray)
{
	ray->o = data->cam.pos;
	ray->tan_half_fov = tan(data->cam.fov * M_PI / 360.0);
	ray->view_width = 2.0 * ray->tan_half_fov;
	ray->asp_ratio = (float)IM_WIDTH / IM_HEIGHT;
	ray->view_height = ray->view_width / ray->asp_ratio;
}

void ft_calc_ray(t_data *data, int x, int y, t_ray *ray) {
    float width = (float)IM_WIDTH;
    float height = (float)IM_HEIGHT;
    
	ray->dir = data->cam.dir;
    // Convert FOV to radians
    float h_fov = data->cam.fov * M_PI / 180.0f; // Horizontal FOV
    float v_fov = h_fov / ray->asp_ratio; // Vertical FOV
    
    // Angle for x-z plane (horizontal)
    float angle_x = ((width - 1.0f) - 2.0f * x) / (width - 1.0f) * (h_fov / 2.0f);
    
    // Angle for y-z plane (vertical)
    float angle_y = ((height - 1.0f) - 2.0f * y) / (height - 1.0f) * (v_fov / 2.0f);
  
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
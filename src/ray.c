/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/07/06 12:06:56 by atambo           ###   ########.fr       */
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
    
    // Convert FOV to radians
    float fov_rad = data->cam.fov * M_PI / 180.0f; // Horizontal FOV
    float vertical_fov_rad = fov_rad / ray->asp_ratio; // Vertical FOV
    
    // Angle for x-z plane (horizontal)
    float angle_x = ((width - 1.0f) - 2.0f * x) / (width - 1.0f) * (fov_rad / 2.0f);
    
    // Angle for y-z plane (vertical)
    float angle_y = ((height - 1.0f) - 2.0f * y) / (height - 1.0f) * (vertical_fov_rad / 2.0f);
    
    // Rotate in z-x plane, then z-y plane

    // temp.x = 0 * cos(angle_x) + 1 * sin(angle_x) = sin(angle_x)
    // temp.y = 0 = 0
    // temp.z = 0 * (-sin(angle_x)) + 1 * cos(angle_x) = cos(angle_x)
    // ray->dir.x = -sinf(angle_x);
    // ray->dir.y = cosf(angle_x) * sinf(angle_y);
    // ray->dir.z = cosf(angle_x) * cosf(angle_y);

    ray->dir.x = -sin(angle_x);
    ray->dir.y = cos(angle_x) * sin(angle_y);
    ray->dir.z = cos(angle_x) * cos(angle_y);
    
    ft_normalize(&ray->dir);
}
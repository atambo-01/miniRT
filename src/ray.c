/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/05/07 12:04:46 by atambo           ###   ########.fr       */
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
void	ft_calc_ray(t_data *data,int x, int y, t_ray *ray)
{
	ray->u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * ray->tan_half_fov;
	ray->v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * ray->view_height / 2.0;
	ray->dir = (t_vec3){ray->u, ray->v, 1.0};
	ft_normalize(&(ray->dir));
}
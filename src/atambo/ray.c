/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:34 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 08:23:39 by atambo           ###   ########.fr       */
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

void	ft_calc_ray(int x, int y, t_ray *ray)
{
	ray->u = (2.0 * (x + 0.5) / IM_WIDTH - 1.0) * ray->tan_half_fov;
	ray->v = (1.0 - 2.0 * (y + 0.5) / IM_HEIGHT) * ray->view_height / 2.0;
	ray->dir = (t_vec3){ray->u, ray->v, -1.0};
	ft_normalize(&(ray->dir));
	ray->obj = NULL;
	ray->color = (t_color){0, 0, 0};
	ray->t = -1.0;
	ray->d = 0.0;
	ray->n = (t_vec3){1.0, 0.0, 0.0};
	ray->l = (t_vec3){1.0, 0.0, 0.0};
}

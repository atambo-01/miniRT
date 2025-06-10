/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 14:38:43 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_hit_obj_2(t_ray *ray, t_obj *obj)
{
	if (!ft_strcmp(obj->type, "pl"))
		ft_hit_plane(obj, ray);
	else if (!ft_strcmp(obj->type, "sp"))
		ft_hit_sphere(obj, ray);
	else if (!ft_strcmp(obj->type, "cy"))
		ft_hit_cylinder(obj, ray);
}

void	ft_hit_obj(t_ray *ray, t_obj *obj)
{
	while (obj)
	{
		ft_hit_obj_2(ray, obj);
		obj = obj->next;
	}
}

void	ft_render_scene(t_data *data)
{
	t_ray	ray;
	int		xy[2];

	xy[1] = 0;
	ft_init_ray(data, &(ray));
	while (xy[1] < IM_HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < IM_WIDTH)
		{
			ft_calc_ray(xy[0], xy[1], &(ray), &data->cam);
			ft_hit_obj(&ray, data->obj);
			ft_hit_light(data, &ray, &(data->light));
			if (ray.t > 0 && ray.obj)
				ray.d = ft_hit_obj_light(data, ray, &(data->light));
			ft_ray_color(&ray, data, xy[0], xy[1]);
			xy[0]++;
		}
		xy[1]++;
	}
}

void	ft_render_and_upscale(t_data *data, int upscale)
{
	ft_render_scene(data);
	if (upscale)
	{
		ft_upscale_img(data);
		mlx_put_image_to_window(data->mlx, data->win, data->s_img.ptr, 0, 0);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

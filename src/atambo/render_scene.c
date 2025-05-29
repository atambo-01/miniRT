/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:38:03 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 13:34:09 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

double	ft_calc_hit_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit)
{
	if (!ft_strcmp(obj->type, "pl"))
		return (ft_hit_plane(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "sp"))
		return (ft_hit_sphere(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "cy"))
		return (ft_hit_cylinder(ray_o, ray_dir, obj, hit));
	else if (!ft_strcmp(obj->type, "cub"))
		return (ft_hit_cube(ray_o, ray_dir, obj, hit));
	else
		return (-1);
}

int	ft_calc_hit(t_ray ray, t_obj *obj, t_hit *hit)
{
	double	t;

	while (obj) // instead of for each obj we need a BVH logic to optimize
	{
		t = ft_calc_hit_2(ray.o, ray.dir, obj, hit);
		if (t >= 0 && (t < hit->t || hit->t < 0))
		{
			hit->t = t;
			hit->color = obj->color;
			hit->obj = obj;
			hit->n = obj->dir;
			hit->u = obj->u;
		}
		obj = obj->next;
	}
	hit->p = ft_vec3_add(ray.o, ft_scalar(ray.dir, hit->t));
	return (hit->t > 1);

}

void	ft_render_scene(t_data *data)
{
	t_hit	hit;
	t_ray	ray;
	int		xy[2];
	
	xy[1] = 0;
	ft_init_ray(data, &(ray));
	while (xy[1] < IM_HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < IM_WIDTH)
		{
			ft_hit_init(&hit);
			ft_calc_ray(xy[0], xy[1], &(ray));
			ft_calc_hit(ray, data->obj, &hit);
			ft_hit_light(data, ray, &hit, &(data->light));
			if (hit.t > 0 && hit.obj)
				hit.d = ft_hit_obj_light(data, ray, hit, &(data->light));
			ft_ray_color(&hit, data, xy[0], xy[1]);
			xy[0]++;
		}
		xy[1]++;
	}
}

void	ft_render_and_upscale(t_data *data, int upscale)
{
	gettimeofday(&(data->start), NULL); // remove later
	ft_render_scene(data);
	gettimeofday(&(data->end), NULL); //remove later
	if (upscale)
	{
		ft_upscale_img(data);
		mlx_put_image_to_window(data->mlx, data->win, data->s_img.ptr, 0, 0);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

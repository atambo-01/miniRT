/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:00:09 by atambo            #+#    #+#             */
/*   Updated: 2025/06/13 11:48:43 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_in_shadow(t_ray ray, t_obj *obj, double light_d)
{
	while (obj)
	{
		ft_hit_obj_2(&ray, obj);
		if (ft_cmp_dbl(ray.t, ">=", 0) && ft_cmp_dbl(ray.t, "<", light_d))
			return (1);
		obj = obj->next;
	}
	return (0);
}

double	ft_hit_obj_light(t_data *data, t_ray ray, t_light *lum)
{
	double	d;
	t_vec3	cam_dir;
	t_vec3	offset;

	d = 0.0;
	cam_dir = ft_vec_ab(&ray.p, &data->cam.pos);
	offset = ft_scalar_mult(cam_dir, 0.00002);
	ray.o = ft_vec3_add(ray.p, offset);
	ray.dir = ft_vec_ab(&ray.o, &lum->pos);
	ft_hit_light(&ray, lum);
	d = ray.t;
	if (ft_in_shadow(ray, data->obj, d))
		return (-1.0);
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vec3_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:23:44 by atambo            #+#    #+#             */
/*   Updated: 2025/06/07 08:53:06 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

t_vec3	ft_vec3_orthogonal(t_vec3 v)
{
	t_vec3	o;

	if (v.x == 0 && v.y == 0 && v.z == 0)
		return ((t_vec3){0, 0, 0});
	if (v.x != 0 || v.y != 0)
	{
		o.x = v.y;
		o.y = -v.x;
		o.z = 0;
	}
	else
	{
		o.x = 1;
		o.y = 0;
		o.z = 0;
	}
	return (o);
}

void	ft_normalize(t_vec3 *v)
{
	double	len;

	len = sqrt(ft_dot(*v, *v));
	if (len > 0)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
}

t_vec3	ft_scalar_mult(t_vec3 v1, double r)
{
	t_vec3	result;

	result.x = v1.x * r;
	result.y = v1.y * r;
	result.z = v1.z * r;
	return (result);
}

t_vec3	ft_vec3_invert(t_vec3 v)
{
	return ((t_vec3){-v.x, -v.y, -v.z});
}

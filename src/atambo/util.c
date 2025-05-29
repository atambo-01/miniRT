/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:23:44 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 13:51:20 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_setvec3(t_vec3 *v, double a, double b, double c)
{
	v->x = a;
	v->y = b;
	v->z = c;
}

void	ft_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

double	ft_dot(t_vec3 a, t_vec3 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec3 ft_scalar(t_vec3 v1, double r)
{
	t_vec3	result;

	result.x = v1.x * r;
	result.y = v1.y * r;
	result.z = v1.z * r;
	return (result);
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

double ft_get_speed(struct timeval start, struct timeval end)
{
	double sec_diff = (double)(end.tv_sec - start.tv_sec) * 1000.0;
	double usec_diff = (double)(end.tv_usec - start.tv_usec) / 1000.0;
	return (sec_diff + usec_diff);
}

void	ft_hit_init(t_hit *hit)
{
	hit->obj = NULL;
	hit->color = (t_color){0, 0, 0};
	hit->t = -1.0;
	hit->d = 0.0;
	hit->n = (t_vec3){0.0, 0.0, 0.0};
	hit->u = (t_vec3){0.0, 0.0, 0.0};
}

t_vec3 ft_vec3_orthogonal(t_vec3 v)
{
    t_vec3 o;

    // Handle case where v = (0, 0, 0)
    if (v.x == 0 && v.y == 0 && v.z == 0)
        return (t_vec3){0, 0, 0}; // Undefined, return zero vector

    // If cx or cy is non-zero, use o = (cy, -cx, 0)
    if (v.x != 0 || v.y != 0)
    {
        o.x = v.y;
        o.y = -v.x;
        o.z = 0;
    }
    // If cx = cy = 0, use o = (1, 0, 0)
    else
    {
        o.x = 1;
        o.y = 0;
        o.z = 0;
    }

    return o;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:23:44 by atambo            #+#    #+#             */
/*   Updated: 2025/04/27 15:13:31 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ft_setvec3(t_vec3 *v, float a, float b, float c)
{
    v->x = a;
    v->y = b;
    v->z = c;
}

void ft_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

float ft_dot(t_vec3 a, t_vec3 b)
{
    float result;

    result = a.x * b.x + a.y * b.y + a.z * b.z;
    return (result);
}

void ft_normalize(t_vec3 *v)
{
    float len;

    len = sqrt(ft_dot(*v, *v));
    if (len > 0)
    {
        v->x /= len;
        v->y /= len;
        v->z /= len;
    }
}
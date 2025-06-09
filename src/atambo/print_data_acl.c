/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_acl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:15:24 by atambo            #+#    #+#             */
/*   Updated: 2025/06/09 17:03:08 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_print_t_color(t_color color)
{
	printf("  Color:\t%d,%d,%d\n", color.r, color.g, color.b);
}

int	ft_print_cam(t_cam *cam)
{
	printf("Camera:\n");
	printf("  Pos:\t");
	ft_print_vec3(&cam->pos);
	printf("  Dir:\t");
	ft_print_vec3(&cam->dir);
	printf("  Right: ");
	ft_print_vec3(&cam->right);
	printf("  Up:\t");
	ft_print_vec3(&cam->up);
	printf("  FOV:\t\t%.2f degrees\n", cam->fov);
	return (0);
}

int	ft_print_light(t_light *lum)
{
	printf("Light:\n");
	printf("  Pos:\t");
	ft_print_vec3(&lum->pos);
	printf("  Ratio:\t%.2f%%\n", lum->ratio * 100);
	printf("  Radius:\t%.2f\n", lum->radius);
	ft_print_t_color(lum->color);
	return (0);
}

int	ft_print_alight(t_alight *lum)
{
	printf("Ambient_Light:\n");
	printf("  Ratio:\t%.2f%%\n", lum->ratio * 100);
	ft_print_t_color(lum->color);
	return (0);
}

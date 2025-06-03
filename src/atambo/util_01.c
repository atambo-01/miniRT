/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:42:33 by atambo            #+#    #+#             */
/*   Updated: 2025/06/03 19:24:58 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

double	ft_get_speed(struct timeval start, struct timeval end)
{
	double	sec_diff;
	double	usec_diff ;
	
	sec_diff = (double)((end.tv_sec - start.tv_sec) * 1000.0);
	usec_diff = (double)(end.tv_usec - start.tv_usec) / 1000.0;
	return (sec_diff + usec_diff);
}

void	ft_hit_init(t_hit *hit)
{
	hit->obj = NULL;
	hit->color = (t_color){0, 0, 0};
	hit->t = -1.0;
	hit->d = 0.0;
	hit->n = (t_vec3){0.0, 0.0, 0.0};
	hit->l = (t_vec3){0.0, 0.0, 0.0};
}

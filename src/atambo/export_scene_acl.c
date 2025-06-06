/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene_acl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:08:26 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 17:10:06 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_write_cam(t_cam *cam, int fd)
{
	ft_putstr_fd("C", fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(cam->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(cam->dir, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_ftoa(cam->fov), fd);
	ft_putchar_fd('\n', fd);
}

void	ft_write_light(t_light *lum, int fd)
{
	ft_putstr_fd("L", fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(lum->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_ftoa(lum->ratio), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(lum->color, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_write_alight(t_alight *alum, int fd)
{
	ft_putstr_fd("A", fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_ftoa(alum->ratio), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(alum->color, fd);
	ft_putchar_fd('\n', fd);
}

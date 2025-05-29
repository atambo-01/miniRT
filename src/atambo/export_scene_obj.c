/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:09:36 by atambo            #+#    #+#             */
/*   Updated: 2025/05/29 02:35:10 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_write_plane(t_obj *obj, int fd)
{
	ft_putstr_fd(obj->type, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(obj->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(obj->dir, fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(obj->color, fd);
}

void	ft_write_sphere(t_obj *obj, int fd)
{
	ft_putstr_fd(obj->type, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(obj->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(obj->radius * 2), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(obj->color, fd);
}

void	ft_write_cylinder(t_obj *obj, int fd)
{
	ft_putstr_fd(obj->type, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(obj->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(obj->dir, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(obj->radius * 2), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(obj->len), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(obj->color, fd);
}

void	ft_write_obj(t_obj *obj, int fd)
{
	while (obj)
	{
		if (!ft_strcmp(obj->type, "pl"))
			ft_write_plane(obj, fd);
		else if (!ft_strcmp(obj->type, "sp"))
			ft_write_sphere(obj, fd);
		else if (!ft_strcmp(obj->type, "cy"))
			ft_write_cylinder(obj, fd);
		ft_putchar_fd('\n', fd);
		obj = obj->next;
	}
}
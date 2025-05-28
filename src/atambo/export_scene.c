/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:47:48 by atambo            #+#    #+#             */
/*   Updated: 2025/05/28 13:22:14 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_write_vec3(t_vec3 v, int fd)
{
	ft_putstr_fd(ft_itoaf(v.x), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoaf(v.y), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoaf(v.z), fd);
}

void ft_write_color(int color, int fd)
{
	int r;
	int g;
	int b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	ft_putstr_fd(ft_itoa(r), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(g), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(b), fd);
}

void ft_write_cam(t_cam *cam, int fd)
{
	ft_putstr_fd("C", fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(cam->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(cam->dir, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(cam->fov), fd);
	ft_putchar_fd('\n', fd);
}

void ft_write_light(t_light *lum, int fd)
{
	ft_putstr_fd("L", fd);
	ft_putstr_fd(" ", fd);
	ft_write_vec3(lum->pos, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(lum->ratio), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(lum->color, fd);
	ft_putchar_fd('\n', fd);

}

void ft_write_alight(t_alight *alum, int fd)
{
	ft_putstr_fd("A", fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(alum->ratio), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(alum->color, fd);
	ft_putchar_fd('\n', fd);
}
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
	ft_putstr_fd(ft_itoaf(obj->radius), fd);
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
	ft_putstr_fd(ft_itoaf(obj->radius), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoaf(obj->len), fd);
	ft_putstr_fd(" ", fd);
	ft_write_color(obj->color, fd);
}

void ft_write_obj(t_obj *obj, int fd)
{
	while(obj)
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

void ft_export_scene(t_data *data)
{
	int	fd;

	if (!data)
		return;
	fd = open("./saved_scene.rt", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	if (!fd)
		ft_minirt_error(E_EXPORT, 2);
	ft_write_alight(&data->alight, fd);
	ft_write_light(&data->light, fd);
	ft_write_cam(&data->cam, fd);
	ft_write_obj(data->obj, fd);
	close(fd);
	system("clear");
    printf("-----------------------------------------\n");
	printf("Scene saved in ./saved_scene.rt\n");
	printf("-----------------------------------------\n");
	ft_sleep(2);
}

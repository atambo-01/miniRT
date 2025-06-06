/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:47:48 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 17:10:06 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_write_vec3(t_vec3 v, int fd)
{
	ft_putstr_fd(ft_ftoa(v.x), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_ftoa(v.y), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_ftoa(v.z), fd);
}

void	ft_write_color(t_color color, int fd)
{
	ft_putstr_fd(ft_itoa(color.r), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(color.g), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(color.b), fd);
}

void	ft_export_scene(t_data *data)
{
	int	fd;

	if (!data)
		return ;
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

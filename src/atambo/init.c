/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:13:05 by atambo            #+#    #+#             */
/*   Updated: 2025/06/13 12:26:58 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

static void	ft_init_data_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(ft_perror("Failed to init mlw connection\n", 1));
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "miniRT");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(ft_perror("Failed to init mlw window\n", 1));
	}
	data->img.ptr = mlx_new_image(data->mlx, IM_WIDTH, IM_HEIGHT);
	data->s_img.ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img.ptr || !data->s_img.ptr)
		exit(ft_perror("Failed to create mlx image\n", 1));
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->s_img.addr = mlx_get_data_addr(data->s_img.ptr, &data->s_img.bpp,
			&data->s_img.line_len, &data->s_img.endian);
}

static void	ft_init_data_acl(t_data *data)
{
	data->cam.dir = (t_vec3){0.0, 0.0, 0.0};
	data->cam.pos = (t_vec3){0.0, 0.0, 0.0};
	data->cam.right = (t_vec3){0.0, 0.0, 0.0};
	data->cam.up = (t_vec3){0.0, 0.0, 0.0};
	data->cam.fov = 0.0;
	data->light.pos = (t_vec3){0.0, 0.0, 0.0};
	data->light.color = (t_color){0, 0, 0};
	data->light.radius = 0.0;
	data->light.ratio = 0.0;
	data->alight.color = (t_color){0, 0, 0};
	data->alight.ratio = 0.0;
}

static void	ft_init_data_extra(t_data *data)
{
	data->curr = NULL;
	data->curr_light = NULL;
	data->err = NULL;
	data->focus = 0;
}

int	ft_init_data(t_data *data, int fd)
{
	data->fd = fd;
	ft_init_data_mlx(data);
	ft_init_data_acl(data);
	ft_init_data_extra(data);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:22:49 by atambo            #+#    #+#             */
/*   Updated: 2025/06/14 16:34:59 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_cam_normalize(t_cam *cam)
{
	ft_normalize(&cam->dir);
	ft_normalize(&cam->up);
	cam->right = ft_cross(cam->up, cam->dir);
	ft_normalize(&cam->right);
}

void	ft_rotate_cam_radial(int key, t_cam *cam, double angle)
{
	t_vec3	tmp_right;
	t_vec3	tmp_up;

	if (!cam)
		return ;
	tmp_right = cam->right;
	tmp_up = cam->up;
	if (key == 'q')
	{
		cam->right = ft_vec3_add(ft_scalar_mult(tmp_right, cos(angle)),
				ft_scalar_mult(tmp_up, sin(angle)));
		cam->up = ft_vec3_add(ft_scalar_mult(tmp_right, -sin(angle)),
				ft_scalar_mult(tmp_up, cos(angle)));
	}
	else if (key == 'e')
	{
		cam->right = ft_vec3_sub(ft_scalar_mult(tmp_right, cos(angle)),
				ft_scalar_mult(tmp_up, sin(angle)));
		cam->up = ft_vec3_add(ft_scalar_mult(tmp_right, sin(angle)),
				ft_scalar_mult(tmp_up, cos(angle)));
	}
}

void	ft_rotate_cam_vertical(int key, t_cam *cam, double angle)
{
	t_vec3	tmp_right;
	t_vec3	tmp_dir;

	tmp_right = cam->right;
	tmp_dir = cam->dir;
	if (key == LEFT)
	{
		cam->right = ft_vec3_add(ft_scalar_mult(tmp_right, cos(angle)),
				ft_scalar_mult(tmp_dir, sin(angle)));
		cam->dir = ft_vec3_sub(ft_scalar_mult(tmp_dir, cos(angle)),
				ft_scalar_mult(tmp_right, sin(angle)));
	}
	else
	{
		cam->right = ft_vec3_sub(ft_scalar_mult(tmp_right, cos(angle)),
				ft_scalar_mult(tmp_dir, sin(angle)));
		cam->dir = ft_vec3_add(ft_scalar_mult(tmp_dir, cos(angle)),
				ft_scalar_mult(tmp_right, sin(angle)));
	}
}

void	ft_rotate_cam_horizontal(int key, t_cam *cam, double angle)
{
	t_vec3	tmp_dir;
	t_vec3	tmp_up;

	tmp_dir = cam->dir;
	tmp_up = cam->up;
	if (key == UP)
	{
		cam->dir = ft_vec3_add(ft_scalar_mult(tmp_dir, cos(angle)),
				ft_scalar_mult(tmp_up, sin(angle)));
		cam->up = ft_vec3_sub(ft_scalar_mult(tmp_up, cos(angle)),
				ft_scalar_mult(tmp_dir, sin(angle)));
	}
	else
	{
		cam->dir = ft_vec3_sub(ft_scalar_mult(tmp_dir, cos(angle)),
				ft_scalar_mult(tmp_up, sin(angle)));
		cam->up = ft_vec3_add(ft_scalar_mult(tmp_dir, sin(angle)),
				ft_scalar_mult(tmp_up, cos(angle)));
	}
}

void	ft_rotate_cam(int key, t_cam *cam)
{
	double	angle;

	if (!cam)
		return ;
	angle = ANGLE * M_PI / 180.0;
	if (key == 'q' || key == 'e')
		ft_rotate_cam_radial(key, cam, angle);
	else if (key == RIGHT || key == LEFT)
		ft_rotate_cam_vertical(key, cam, angle);
	else if (key == UP || key == DOWN)
		ft_rotate_cam_horizontal(key, cam, angle);
	ft_cam_normalize(cam);
}

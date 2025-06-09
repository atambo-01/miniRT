/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:22:49 by atambo            #+#    #+#             */
/*   Updated: 2025/06/09 19:54:43 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void ft_rotate_cam_dir(int key, t_cam *cam)
{
    double angle = 15.0 * M_PI / 180.0; // 15 degrees in radians
    t_vec3 tmp_right, tmp_up;

    // Store current right and up vectors
    tmp_right = cam->right;
    tmp_up = cam->up;

    if (key == 'q') // Counterclockwise roll
    {
        cam->right.x = tmp_right.x * cos(angle) + tmp_up.x * sin(angle);
        cam->right.y = tmp_right.y * cos(angle) + tmp_up.y * sin(angle);
        cam->right.z = tmp_right.z * cos(angle) + tmp_up.z * sin(angle);
        
        cam->up.x = -tmp_right.x * sin(angle) + tmp_up.x * cos(angle);
        cam->up.y = -tmp_right.y * sin(angle) + tmp_up.y * cos(angle);
        cam->up.z = -tmp_right.z * sin(angle) + tmp_up.z * cos(angle);
    }
    else if (key == 'e') // Clockwise roll
    {
        cam->right.x = tmp_right.x * cos(angle) - tmp_up.x * sin(angle);
        cam->right.y = tmp_right.y * cos(angle) - tmp_up.y * sin(angle);
        cam->right.z = tmp_right.z * cos(angle) - tmp_up.z * sin(angle);
        
        cam->up.x = tmp_right.x * sin(angle) + tmp_up.x * cos(angle);
        cam->up.y = tmp_right.y * sin(angle) + tmp_up.y * cos(angle);
        cam->up.z = tmp_right.z * sin(angle) + tmp_up.z * cos(angle);
    }
    ft_normalize(&cam->right);
    ft_normalize(&cam->up);
    cam->up = ft_cross(cam->dir, cam->right);
    ft_normalize(&cam->up);
}

void ft_rotate_cam_up(int key, t_cam *cam)
{
    double angle = 15.0 * M_PI / 180.0; // 15 degrees in radians
    t_vec3 tmp_right, tmp_dir;

    // Store current right and dir vectors
    tmp_right = cam->right;
    tmp_dir = cam->dir; // Fix: Rotate cam->dir, not cam->up

    if (key == LEFT) // Counterclockwise yaw (e.g., left)
    {
        cam->right.x = tmp_right.x * cos(angle) + tmp_dir.x * sin(angle);
        cam->right.y = tmp_right.y * cos(angle) + tmp_dir.y * sin(angle);
        cam->right.z = tmp_right.z * cos(angle) + tmp_dir.z * sin(angle);
        
        cam->dir.x = -tmp_right.x * sin(angle) + tmp_dir.x * cos(angle);
        cam->dir.y = -tmp_right.y * sin(angle) + tmp_dir.y * cos(angle);
        cam->dir.z = -tmp_right.z * sin(angle) + tmp_dir.z * cos(angle);
    }
    else // Clockwise yaw (e.g., right)
    {
        cam->right.x = tmp_right.x * cos(angle) - tmp_dir.x * sin(angle);
        cam->right.y = tmp_right.y * cos(angle) - tmp_dir.y * sin(angle);
        cam->right.z = tmp_right.z * cos(angle) - tmp_dir.z * sin(angle);
        
        cam->dir.x = tmp_right.x * sin(angle) + tmp_dir.x * cos(angle);
        cam->dir.y = tmp_right.y * sin(angle) + tmp_dir.y * cos(angle);
        cam->dir.z = tmp_right.z * sin(angle) + tmp_dir.z * cos(angle);
    }

    // Normalize to ensure orthonormality
    ft_normalize(&cam->right);
    ft_normalize(&cam->dir);

    // Recompute up to ensure orthogonality
    cam->up = ft_cross(cam->dir, cam->right);
    ft_normalize(&cam->up);
}

void ft_rotate_cam_right(int key, t_cam *cam)
{
    double angle = 15.0 * M_PI / 180.0; // 15 degrees in radians
    t_vec3 tmp_dir, tmp_up;

    // Store current dir and up vectors
    tmp_dir = cam->dir;
    tmp_up = cam->up;

    if (key == UP) // Counterclockwise pitch (pitch up)
    {
        cam->dir.x = tmp_dir.x * cos(angle) + tmp_up.x * sin(angle);
        cam->dir.y = tmp_dir.y * cos(angle) + tmp_up.y * sin(angle);
        cam->dir.z = tmp_dir.z * cos(angle) + tmp_up.z * sin(angle);
        
        cam->up.x = -tmp_dir.x * sin(angle) + tmp_up.x * cos(angle);
        cam->up.y = -tmp_dir.y * sin(angle) + tmp_up.y * cos(angle);
        cam->up.z = -tmp_dir.z * sin(angle) + tmp_up.z * cos(angle);
    }
    else
    {
        cam->dir.x = tmp_dir.x * cos(angle) - tmp_up.x * sin(angle);
        cam->dir.y = tmp_dir.y * cos(angle) - tmp_up.y * sin(angle);
        cam->dir.z = tmp_dir.z * cos(angle) - tmp_up.z * sin(angle);
        
        cam->up.x = tmp_dir.x * sin(angle) + tmp_up.x * cos(angle);
        cam->up.y = tmp_dir.y * sin(angle) + tmp_up.y * cos(angle);
        cam->up.z = tmp_dir.z * sin(angle) + tmp_up.z * cos(angle);
    }

    // Normalize to ensure orthonormality
    ft_normalize(&cam->dir);
    ft_normalize(&cam->up);

    // Recompute right to ensure orthogonality
    cam->right = ft_cross(cam->up, cam->dir);
    ft_normalize(&cam->right);
}

void ft_rotate_cam(int key, t_cam *cam)
{
    if (!cam)
        return;
    if (key == 'q' || key == 'e')
        ft_rotate_cam_dir(key, cam);
    else if (key == RIGHT || key == LEFT)
        ft_rotate_cam_up(key, cam);
    else if (key == UP || key == DOWN)
        ft_rotate_cam_right(key, cam);
}

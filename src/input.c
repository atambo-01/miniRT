/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:38:57 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:49:11 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	key_hook_2(int keycode, t_data *data)
{
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	if (keycode == DOWN)
	if (keycode == UP)
	if (keycode == LEFT)
	if (keycode == RIGHT)
	key_hook_2(keycode, data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
	if (button == 5)
	return (0);
}
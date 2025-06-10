/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_switch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:44:16 by atambo            #+#    #+#             */
/*   Updated: 2025/06/10 19:20:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

const t_color	*get_custom_colors(int *num_colors)
{
	static const t_color	colors[] = {
	{255, 105, 180},
	{21, 174, 194},
	{46, 139, 87},
	{255, 99, 71},
	{64, 224, 208},
	{132, 69, 34}
	};

	*num_colors = 6;
	return (colors);
}

const t_color	*get_basic_colors(int *num_colors)
{
	static const t_color	colors[] = {
	{010, 010, 010},
	{255, 255, 255},
	{000, 000, 255},
	{000, 255, 000},
	{255, 000, 000},
	{000, 255, 255},
	{255, 000, 255},
	{255, 255, 000}
	};

	*num_colors = 8;
	return (colors);
}

void	ft_color_switch(t_data *data, int key)
{
	static int		f_index[2] = {0, 0};
	const t_color	*colors;
	int				num_colors;
	int				*index;
	t_color			*color;

	if (data->curr)
		color = &data->curr->color;
	else if (data->curr_light)
		color = &data->curr_light->color;
	else
		color = &data->alight.color;
	if (key == TAB)
		colors = get_custom_colors(&num_colors);
	else if (key == SHIFT)
		colors = get_basic_colors(&num_colors);
	index = &f_index[key == SHIFT];
	*color = colors[*index];
	*index = (*index + 1) % num_colors;
}

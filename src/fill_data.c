/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/19 20:05:42 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	color_range(int r, int b, int g)
{
	if (r >= 0 && r <= 255)
		return (1);
	if (b >= 0 && b <= 255)
		return (1);
	if (g >= 0 && g <= 255)
		return (1);
	return (0);
}

int	fill_color(char *color, t_color *colors)
{
	char **rbg;
	
	if (!color)
		return (0);
	rbg = ft_split(color, ',');
	if (ft_array_size(rbg) == 3)
	{
		colors->r = ft_atoi(rbg[0]);
		colors->b = ft_atoi(rbg[1]);
		colors->g = ft_atoi(rbg[2]);
		if (!color_range(colors->r, colors->b, colors->g))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	ambient_data(t_amblight *amb, char **data)
{
	// amb->id = 'A';
	printf("%s\n", data[1]);
	printf("%s\n", data[2]);
	printf("A\n");
	amb->light_ratio = ft_atof(data[1]);
	printf("here\n");
	if (!fill_color(data[2], &amb->color))
		return ;
	printf("here 2\n");
}

int	fill_data(char **scene, t_data *data)
{
	int		i;
	char	**arr;
	(void) data;
	
	i = -1;
	while(scene[++i])
	{
		arr = ft_split2(scene[i]);
		if (ft_strncmp(arr[0], "A", 2) == 0)
		{
			
			ambient_data(data->scenario.ambient_light, arr);
			// printf("ID = %c\n", data->scenario.ambient_light->id);
			printf("Ratio = %.2lf\n", data->scenario.ambient_light->light_ratio);
			printf("R = %d\n", data->scenario.ambient_light->color.r);
			printf("B = %d\n", data->scenario.ambient_light->color.b);
			printf("G = %d\n", data->scenario.ambient_light->color.g);
			exit(EXIT_SUCCESS);
		}
		ft_free_array(arr);
	}
	
	return (1);
}

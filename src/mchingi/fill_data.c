/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:27 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/09 16:16:46 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	parse_line(char *line, t_data *data)
{
	int		success;
	char	**tokens;

	success = 0;
	tokens = ft_split2(line);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		success = ambient_data(&data->alight, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		success = camera_data(&data->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		success = light_data(&data->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		success = plane_data(data, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		success = sphere_data(data, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		success = cylinder_data(data, tokens);
	ft_free_array(tokens);
	return (success);
}

int	fill_data(char **scene, t_data *data)
{
	int		i;

	i = -1;
	while (scene[++i])
	{
		if (!parse_line(scene[i], data))
		{
			ft_minirt_error("In line number ", 1);
			ft_putnbr_fd(i + 1, 2);
			ft_perror(" :", 1);
			ft_perror("\n\n", 1);
			ft_perror(scene[i], 1);
			ft_perror("\n\n", 1);
			ft_free_array(scene);
			exit(1);
		}
	}
	ft_free_array(scene);
	return (1);
}

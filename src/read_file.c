/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:37:51 by atambo            #+#    #+#             */
/*   Updated: 2025/05/02 11:37:02 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ft_get_alight(t_data *data, char **tokens)
{
	static int count;
	if (count > 1)
		ft_exit_minirt(data, ERR_ALIGHT);
	count++;
}

void	ft_read_file(t_data *data)
{
	int i;
	char *line = NULL;
	char **tokens = NULL;
	int		info[];

	info = (int []){0, 0, 0, 0, 0};
	while(tokens[i])
	{
		line = ft_get_next_line(data->fd);
		tokens = ft_split(line, ' ');
		if (!ft_strcmp(tokens[i], "A"))
			ft_get_alight(data, tokens);
		// else if (ft_strcmp(token[i][0], "C") == 0)

		// else if (ft_strcmp(token[i][0], "L") == 0)

		// else if (ft_strcmp(token[i][0], "sp") == 0)

		// else if (ft_strcmp(token[i][0], "pl") == 0)
		
		// else if (ft_strcmp(token[i][0], "cy") == 0)
	}
}

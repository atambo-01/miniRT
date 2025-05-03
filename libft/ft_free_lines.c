/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <alex.tambo.15432@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:57:18 by atambo            #+#    #+#             */
/*   Updated: 2025/03/10 11:57:53 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_free_lines(char ***lines)
{
	int	count;

	count = 0;
	if (lines && *lines)
	{
		while ((*lines)[count])
		{
			free((*lines)[count]);
			count++;
		}
		free(*lines);
		*lines = NULL;
	}
	return (count);
}

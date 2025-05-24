/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:29:38 by atambo            #+#    #+#             */
/*   Updated: 2025/05/24 17:32:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_minirt_error(char const *msg, int e)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, (int)ft_strlen(msg));
	}
	return (e);
}

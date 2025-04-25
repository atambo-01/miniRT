/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:29:38 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:05:42 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_perror(char const *msg, int e)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:54:22 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/20 19:57:45 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_size(char **arr)
{
	int		i;
	size_t	counter;

	i = -1;
	counter = 0;
	while (arr[++i] != NULL)
		counter++;
	return (counter);
}

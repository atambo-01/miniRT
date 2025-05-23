/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:23:09 by mchingi           #+#    #+#             */
/*   Updated: 2024/05/18 13:27:02 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	int		area;

	area = (nmemb * size);
	buffer = (char *)malloc(sizeof(char) * area);
	if (!buffer)
		return (NULL);
	while (--area >= 0)
		buffer[area] = '\0';
	return ((void *)buffer);
}

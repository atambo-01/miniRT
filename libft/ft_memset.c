/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:08:46 by mchingi           #+#    #+#             */
/*   Updated: 2024/05/18 11:13:19 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	v;
	size_t			i;

	v = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = v;
		i++;
	}
	return (ptr);
}	

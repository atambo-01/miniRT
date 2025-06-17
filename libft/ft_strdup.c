/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:51 by atambo            #+#    #+#             */
/*   Updated: 2025/06/17 15:30:50 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(char *src)
{
	size_t	n;
	char	*dst;

	if (!src)
		return (NULL);
	n = 0;
	while (src[n])
		n ++;
	dst = ft_malloc((n + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	n = 0;
	while (src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (dst);
}

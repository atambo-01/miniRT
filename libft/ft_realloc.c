/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <alex.tambo.15432@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:17:21 by atambo            #+#    #+#             */
/*   Updated: 2025/03/22 17:58:13 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_helper(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!ptr || !*ptr)
	{
		new_ptr = ft_malloc(new_size);
		if (ptr && new_ptr)
			*ptr = new_ptr;
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
		return (NULL);
	}
	new_ptr = ft_malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size > new_size)
		old_size = new_size;
	ft_memcpy_helper((char *)new_ptr, (char *)*ptr, old_size);
	free(*ptr);
	*ptr = new_ptr;
	return (new_ptr);
}

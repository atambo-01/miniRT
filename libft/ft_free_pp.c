/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <alex.tambo.15432@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:16:36 by atambo            #+#    #+#             */
/*   Updated: 2025/03/10 12:07:55 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_pp(void ***ptr)
{
	void	**curr;

	if (!ptr || !*ptr)
		return ;
	curr = *ptr;
	while (*curr)
	{
		free(*curr);
		*curr = NULL;
		curr++;
	}
	free(*ptr);
	*ptr = NULL;
}

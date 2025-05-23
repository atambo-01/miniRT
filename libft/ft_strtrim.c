/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:02:08 by mchingi           #+#    #+#             */
/*   Updated: 2024/05/18 14:02:09 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = (ft_strlen(s1) - 1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] && ft_strchr(set, s1[j]))
		j--;
	str = ft_substr(s1, i, ((j - i) + 1));
	return (str);
}

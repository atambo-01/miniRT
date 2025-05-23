/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:34:38 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 16:17:41 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"

char	*ft_strchr_1(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_1(char *str, char *buffer)
{
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	new_str = (char *)malloc((1 + ft_strlen(str)) + ft_strlen(buffer)
			* sizeof(char));
	if (!new_str)
		return (NULL);
	new_str = ft_strjoin_2(new_str, str, buffer);
	free(str);
	return (new_str);
}

char	*ft_strjoin_2(char *new_str, char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_substr_1(char *str, int start, int len_str)
{
	int		i;
	char	*subs;
	int		sum;

	i = 0;
	sum = len_str - start;
	if (sum == 0 || !str)
	{
		free(str);
		return (NULL);
	}
	subs = (char *)malloc(sizeof(char) * (sum + 1));
	if (!subs)
		return (NULL);
	while (str[start])
	{
		subs[i] = str[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	free(str);
	return (subs);
}

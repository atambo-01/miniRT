/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:02:50 by atambo            #+#    #+#             */
/*   Updated: 2025/06/12 20:03:29 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			count++;
			i++;
		}
		while (!ft_isspace(s[i]) && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_getword(char const *s, int start)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	len = ft_wordlen(s, start);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (!ft_isspace(s[i]) && s[i] != '\0')
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

char	**ft_split2(char const *s)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	arr = (char **)malloc((sizeof(char *) * (ft_wordcount(s) + 1)));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			arr[++j] = ft_getword(s, i);
			i += ft_wordlen(s, i);
		}
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
	}
	arr[++j] = NULL;
	return (arr);
}

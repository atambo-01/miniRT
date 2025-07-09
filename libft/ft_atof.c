/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:52:25 by mchingi           #+#    #+#             */
/*   Updated: 2025/07/09 13:49:44 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof2_aux(char *dec_str)
{
	int		i;
	double	power;

	i = 0;
	power = 1.0;
	while (dec_str[i] && ft_isdigit(dec_str[i]))
	{
		power = power * 10.0;
		i++;
	}
	return (power);
}

void	ft_assign_parts(char *str, char **int_str, char **decimal_str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '.')
		len++;
	*int_str = malloc(len + 1);
	if (*int_str)
	{
		while (i < len)
		{
			(*int_str)[i] = str[i];
			i++;
		}
		(*int_str)[i] = '\0';
	}
	*decimal_str = malloc(ft_strlen(str) - len);
	if (*decimal_str && str[len] == '.')
		ft_strcpy(*decimal_str, str + len + 1);
	else if (*decimal_str)
		(*decimal_str)[0] = '\0';
}

double	ft_atof(char *str)
{
	char	*int_str;
	char	*decimal_str;
	double	num;

	int_str = NULL;
	decimal_str = NULL;
	num = 0.0;
	ft_assign_parts(str, &int_str, &decimal_str);
	if (!int_str || !decimal_str)
	{
		if (int_str)
			free(int_str);
		if (decimal_str)
			free(decimal_str);
		return (0.0);
	}
	if (int_str[0] != '\0')
		num = ft_atoi(int_str);
	if (decimal_str[0] != '\0')
		num = num + ft_atoi(decimal_str) / ft_atof2_aux(decimal_str);
	if (str[0] == '-' && num > 0)
		num = -num;
	free(int_str);
	free(decimal_str);
	return (num);
}

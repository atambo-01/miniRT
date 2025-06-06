/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:11:13 by atambo            #+#    #+#             */
/*   Updated: 2025/06/06 17:11:47 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_ftoa_02(double frac, char *res, int i, int j)
{
	if (frac != 0.0)
	{
		res[j++] = '.';
		i = 0;
		while (i < 6 && frac != 0.0)
		{
			frac *= 10;
			res[j++] = (long)frac % 10 + '0';
			frac -= (long)frac;
			i++;
		}
	}
	res[j] = 0;
}

void	ft_ftoa_aux_01(double frac, int neg, int int_part, char *res)
{
	int		i;
	int		j;
	char	buf[24];

	i = 0;
	j = 0;
	if (neg)
		res[j++] = '-';
	if (int_part)
	{
		while (int_part)
		{
			buf[i++] = int_part % 10 + '0';
			int_part /= 10;
		}
	}
	else
		buf[i++] = '0';
	while (i > 0)
	{
		i--;
		res[j++] = buf[i];
	}
	ft_ftoa_02(frac, res, i, j);
}

char	*ft_ftoa(double num)
{
	char	*res;
	int		neg;
	long	int_part;
	double	frac;

	neg = num < 0.0;
	int_part = num;
	if (neg)
		int_part = -num;
	frac = num - (long)num;
	if (neg)
		frac = -frac;
	if (num == 0.0)
		return (ft_strdup("0.0"));
	res = malloc(24);
	if (!res)
		return (NULL);
	ft_ftoa_aux_01(frac, neg, int_part, res);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:21:01 by atambo            #+#    #+#             */
/*   Updated: 2025/05/28 12:42:29 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

char	*ft_itoaf(double num)
{
	char	*res;
	char	buf[24];
	int		i;
	int		j;
	int		neg;
	long	int_part;
	double	frac;

	neg = num < 0;
	if (neg)
		int_part = -num;
	else
		int_part = num;
	frac = num - (long)num;
	if (neg)
		frac = -frac;
	if (num == 0.0)
		return (ft_strdup("0.0"));
	res = malloc(24);
	if (!res)
		return (0);
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
	return (res);
}

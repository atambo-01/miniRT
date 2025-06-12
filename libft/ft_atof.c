/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:52:25 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/12 20:02:24 by atambo           ###   ########.fr       */
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
		power *= 10.0;
		i++;
	}
	return (power);
}

double	ft_atof(char *str)
{
	int		int_part;
	double	dec_part;
	double	num;
	char	**tmp;

	num = 0;
	tmp = ft_split(str, '.');
	int_part = ft_atoi(tmp[0]);
	if (ft_array_size(tmp) == 2)
	{
		dec_part = ft_atoi(tmp[1]);
		if (int_part < 0)
			num = (int_part - (dec_part / ft_atof2_aux(tmp[1])));
		else
			num = (int_part + (dec_part / ft_atof2_aux(tmp[1])));
	}
	else if (ft_array_size(tmp) == 1)
		num = int_part;
	else
	{
		ft_free_array(tmp);
		return (-1);
	}
	ft_free_array(tmp);
	return (num);
}

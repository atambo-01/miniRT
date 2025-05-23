/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:52:42 by mchingi           #+#    #+#             */
/*   Updated: 2024/06/17 14:10:56 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_d_i(long number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		number *= -1;
		count += ft_print_c('-');
	}
	if (number < 10)
		count += ft_print_c(number + '0');
	else
	{
		count += ft_print_d_i(number / 10);
		count += ft_print_d_i(number % 10);
	}
	return (count);
}

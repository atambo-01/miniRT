/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:14:30 by mchingi           #+#    #+#             */
/*   Updated: 2024/06/17 13:12:26 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int number)
{
	int	count;

	count = 0;
	if (number < 10)
		count += ft_print_c(number + '0');
	else
	{
		count += ft_print_d_i(number / 10);
		count += ft_print_d_i(number % 10);
	}
	return (count);
}

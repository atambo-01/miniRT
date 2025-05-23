/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:24 by kfaustin          #+#    #+#             */
/*   Updated: 2024/06/17 14:34:33 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_xx(unsigned long number, char c)
{
	char	*basehex;
	int		count;

	count = 0;
	if (c == 'x')
		basehex = "0123456789abcdef";
	else
		basehex = "0123456789ABCDEF";
	if (number < 16)
		count += ft_print_c(*(basehex + number));
	else
	{
		count += ft_print_xx((number / 16), c);
		count += ft_print_xx((number % 16), c);
	}
	return (count);
}

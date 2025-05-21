/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:56:38 by kfaustin          #+#    #+#             */
/*   Updated: 2024/06/17 14:46:31 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(unsigned long number)
{
	int	count;

	count = 0;
	if (!number)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_print_s("0x");
	count += ft_print_xx(number, 'x');
	return (count);
}

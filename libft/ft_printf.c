/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:54:20 by mchingi           #+#    #+#             */
/*   Updated: 2024/06/17 14:34:45 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkpos(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_c(va_arg(args, int));
	else if (c == 's')
		count += ft_print_s(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_print_d_i(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_print_c('%');
	else if (c == 'p')
		count += ft_print_p(va_arg(args, unsigned long));
	else if (c == 'X' || c == 'x')
		count += ft_print_xx(va_arg(args, unsigned int), c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (*(format + i))
	{
		if (*(format + i) == '%')
			count += checkpos(*(format + ++i), args);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

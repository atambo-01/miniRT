/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:08:41 by atambo            #+#    #+#             */
/*   Updated: 2025/05/28 16:27:46 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_cmp_dbl(double n1, char *op, double n2)
{
	double	diff;
	int		result;

	diff = n1 - n2;
	result = 0;
	if (op[0] == '>')
	{
		if (op[1] == '=')
			result = diff > -EPSILON;
		else
			result = diff > EPSILON;
	}
	else if (op[0] == '<')
	{
		if (op[1] == '=')
			result = diff < EPSILON;
		else
			result = diff < -EPSILON;
	}
	else if (op[0] == '=' && op[1] == 0)
	{
		if (diff < EPSILON && diff > -EPSILON)
			result = 1;
	}
	return (result);
}

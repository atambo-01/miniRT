/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:55:19 by atambo            #+#    #+#             */
/*   Updated: 2025/05/28 13:28:46 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

static void ft_sleep_aux(long usec)
{
	volatile long i;

	i = 0;
	while(i < usec * 1000)
		i++;
}

void ft_sleep(int sec)
{
	ft_sleep_aux(sec * 1000000);
}

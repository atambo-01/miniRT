/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:19:09 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/26 13:56:31 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

char	**remove_char(char **array)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_array_size(array) + 1));
	while (array[i])
	{
		arr[i] = ft_strtrim(array[i], " \n\t");
		i++;
	}
	arr[i] = NULL;
	ft_free_array(array);
	return (arr);
}

// double	ft_atof2(char *str)
// {
// 	int		int_part;
// 	double	dec_part;
// 	double	num;
// 	char	**tmp;

// 	num = 0;
// 	tmp = ft_split(str, '.');
// 	int_part = ft_atoi(tmp[0]);
// 	if (ft_array_size(tmp) == 2)
// 	{
// 		dec_part = ft_atoi(tmp[1]);
// 		if (dec_part > 9)
// 			return (-1);
// 		if (int_part < 0)
// 			num = (int_part - (dec_part / 10.0));
// 		else
// 			num = (int_part + (dec_part / 10.0));
// 	}
// 	else if (ft_array_size(tmp) == 1)
// 		num = int_part;
// 	else
// 	{
// 		ft_free_array(tmp);
// 		return (-1);
// 	}
// 	ft_free_array(tmp);
// 	return (num);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:19:09 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/19 19:52:36 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	ft_array_size(char **arr)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (arr[++i] != NULL)
		counter++;
	return (counter);
}

char **remove_char(char **array)
{
    int i = 0;
    int j = 0;
    char **arr;

    arr = (char **)malloc(sizeof(char *) * (ft_array_size(array) + 1));
    while(array[j])
    {
        arr[i] = ft_strtrim(array[j], " \n\t");
        i++;
        j++;
    }
    arr[i] = NULL;
    return (arr);
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
		if (int_part < 0)
			return (-1);
		dec_part = ft_atoi(tmp[1]);
		if (dec_part > 9)
			return (-1);
		num = (int_part + (dec_part / 10.0));
	}
	else if (ft_array_size(tmp) == 1)
		num = int_part;
	else
		return (-1);
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:19:09 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/16 16:16:39 by mchingi          ###   ########.fr       */
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

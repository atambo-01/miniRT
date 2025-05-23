/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:42:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/22 17:14:03 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	check_duplicate_capital_elements_aux(int a, int c, int l)
{
	if (a == 1 && c == 1 && l == 1)
		return (0);
	if (a > 1 || c > 1 || l > 1)
		ft_putstr_fd("Error\nScene: Duplicate ACL element in scene\n", 2);
	return (1);
}

int	check_duplicate_capital_elements(char **arr, int arr_size)
{
	int		i;
	int		a_count;
	int		c_count;
	int		l_count;
	char	**tmp_arr;

	i = -1;
	a_count = 0;
	c_count = 0;
	l_count = 0;
	while (++i < arr_size)
	{
		tmp_arr = ft_split2(arr[i]);
		if (tmp_arr[0] != NULL)
		{
			if (ft_strncmp(tmp_arr[0], "A", 2) == 0)
				a_count++;
			else if (ft_strncmp(tmp_arr[0], "C", 2) == 0)
				c_count++;
			else if (ft_strncmp(tmp_arr[0], "L", 2) == 0)
				l_count++;
		}
		ft_free_array(tmp_arr);
	}
	return (check_duplicate_capital_elements_aux(a_count, c_count, l_count));
}

int	check_identifier(char **arr)
{
	int	x;

	x = ft_array_size(arr);
	if ((ft_strncmp(arr[0], "A", 2) == 0) && (x == 3))
		return (1);
	else if ((ft_strncmp(arr[0], "C", 2) == 0) && (x == 4))
		return (1);
	else if ((ft_strncmp(arr[0], "L", 2) == 0) && (x == 4))
		return (1);
	else if ((ft_strncmp(arr[0], "pl", 3) == 0) && (x == 4))
		return (1);
	else if ((ft_strncmp(arr[0], "sp", 3) == 0) && (x == 4))
		return (1);
	else if ((ft_strncmp(arr[0], "cy", 3) == 0) && (x == 6))
		return (1);
	return (0);
}

int	validate_scene(char **arr, int arr_size)
{
	int		i;
	char	**tmp_arr;

	if (check_duplicate_capital_elements(arr, arr_size))
		return (0);
	i = -1;
	while (++i < arr_size && arr[i])
	{
		tmp_arr = ft_split2(arr[i]);
		if (!check_identifier(tmp_arr))
		{
			ft_putstr_fd("Error\nScene: Invalid Data\n", 2);
			printf("\n%s\n", arr[i]); // Debug
			ft_free_array(tmp_arr);
			return (0);
		}
		ft_free_array(tmp_arr);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:42:01 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/13 12:12:28 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	check_acl_aux(int *acl, char **arr)
{
	if ((acl[0] > 1 || acl[1] > 1 || acl[2] > 1))
	{
		ft_minirt_error(E_ACL, 1);
		ft_free_array(arr);
		exit (1);
	}
	else if (acl[1] != 1)
	{
		ft_minirt_error(E_CAM, 1);
		ft_free_array(arr);
		exit (1);
	}
	return (0);
}

int	check_acl(char **arr, int arr_size)
{
	int		i;
	char	**tmp_arr;
	int		acl[3];

	i = -1;
	ft_bzero(acl, 3 * sizeof(int));
	while (++i < arr_size)
	{
		tmp_arr = ft_split2(arr[i]);
		if (tmp_arr[0] != NULL)
		{
			if (ft_strncmp(tmp_arr[0], "A", 2) == 0)
				acl[0] += 1;
			else if (ft_strncmp(tmp_arr[0], "C", 2) == 0)
				acl[1] += 1;
			else if (ft_strncmp(tmp_arr[0], "L", 2) == 0)
				acl[2] += 1;
		}
		ft_free_array(tmp_arr);
	}
	return (check_acl_aux(acl, arr));
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

	check_acl(arr, arr_size);
	i = -1;
	while (++i < arr_size && arr[i])
	{
		tmp_arr = ft_split2(arr[i]);
		if (!check_identifier(tmp_arr))
		{
			ft_minirt_error(E_SCENE_DATA, 1);
			ft_perror(arr[i], 1);
			ft_free_array(tmp_arr);
			ft_free_array(arr);
			exit (1);
		}
		ft_free_array(tmp_arr);
	}
	return (1);
}

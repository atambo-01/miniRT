/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/10 19:30:08 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	check_empty_line(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (ft_isalnum(str[i]))
			return (1);
	}
	return (0);
}

int	open_file(char *file_name)
{
	int fd;

	fd = -1;
	if (ft_strncmp(ft_strrchr(file_name, '.'), ".rt", 4) == 0)
		fd = open(file_name, O_RDONLY);
	else
		ft_error("Wrong file extension\n");
	return (fd);
}

int	count_lines(int fd)
{
	int		counter;
	char	*str;

	counter = 0;
	str = get_next_line(fd);
	while(str)
	{
		if (check_empty_line(str))
			counter++;
		str = get_next_line(fd);
	}
	return (counter);
}

char	**extract_lines(char *file_name, int arr_size)
{
	int		i;
	int		fd;
	char	*str;
	char	**arr;

	i = -1;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		ft_error("Error opening file\n");
	str = get_next_line(fd);
	arr = malloc(sizeof(char *) * arr_size);
	while (str)
	{
		if (check_empty_line(str))
			arr[++i] = ft_strdup(str);
		str = get_next_line(fd);
	}
	arr[++i] = NULL; 
	return (arr);
}

int	ft_array_size(char **arr)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while(arr[++i] != NULL)
		counter++;
	return (counter);
}

int	check_identifier(char **arr)
{
	int x;
	
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

// void	check_dbl_alc(char **arr)
// {
// 	int	i;

// }

void	valide_scene(char **arr, int arr_size)
{
	int		i;
	char	**tmp_arr;

	i = -1;
	while (++i < arr_size && arr[i])
	{
		tmp_arr = ft_split2(arr[i]);
		if (check_identifier(tmp_arr))
		{
			printf("%d\n", i);
		}
		else 
			ft_error("Invalid Map\n");
		ft_free_array(tmp_arr);
	}
	printf("ALL GOOD!\n");
}

void	file_management(char *file_name/*, t_data *data*/)
{
	int 	fd;
	int		arr_size;
	char	**arr;

	fd = open_file(file_name);
	arr_size = count_lines(fd);
	arr = extract_lines(file_name, arr_size);

	valide_scene(arr, arr_size);
	
	// return (1);
}

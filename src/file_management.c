/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/07 17:02:26 by mchingi          ###   ########.fr       */
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


char	**file_management(char *file_name)
{
	int 	fd;
	char	**arr;

	fd = open_file(file_name);
	arr = extract_lines(file_name, count_lines(fd));
	return (arr);
}

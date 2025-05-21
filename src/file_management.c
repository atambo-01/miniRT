/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/21 14:28:45 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	check_empty_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalnum(str[i]))
			return (1);
	}
	return (0);
}

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int open_file(char *file_name)
{
    int fd = -1;
    char *ext;
    char *last_dot = NULL;

    if (!file_name)
    {
        perror("Error: NULL filename");
        return (-1);
    }
    ext = file_name;
    while (*ext)
    {
        if (*ext == '.')
            last_dot = ext;
        ext++;
    }
    if (!last_dot || (last_dot[1] != 'r' || last_dot[2] != 't' || last_dot[3] != '\0'))
    {
        perror("Error: File must have .rt extension");
        return (-1);
    }
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (-1);
    }

    return (fd);
}

int	count_lines(int fd)
{
	int		counter;
	char	*str;

	counter = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (check_empty_line(str))
			counter++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
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
	arr = (char **)malloc(sizeof(char *) * (arr_size + 1));
	while (str)
	{
		if (check_empty_line(str))
			arr[++i] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	arr[++i] = NULL;
	free(str);
	return (arr);
}

int	file_management(char *file_name, t_data *data)
{
	int		fd;
	int		arr_size;
	char	**arr;

	fd = open_file(file_name);
	if (fd < 0)
		return (0);
	arr_size = count_lines(fd);
	arr = extract_lines(file_name, arr_size);
	if (!validate_scene(arr, arr_size))
	{
		ft_free_array(arr);
		return (0);
	}
	if (!fill_data(remove_char(arr), data))
	{
		ft_free_array(arr);
		return (0);
	}
	ft_free_array(arr);
	return (1);
}

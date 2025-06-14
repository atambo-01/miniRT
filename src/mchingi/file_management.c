/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/14 15:50:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

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

int	open_file(char *filename)
{
	int		fd;
	char	buffer[1];

	fd = -1;
	if (ft_check_filename(filename))
	{
		ft_minirt_error(E_EXTENSIO, 1);
		exit (1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1 || (read(fd, buffer, 1) == -1 && errno == EISDIR))
	{
		ft_minirt_error(filename, 1);
		perror(" ");
		close(fd);
		exit (1);
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
	if (fd < 0)
	{
		perror("Error\nScene");
		return (NULL);
	}
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
	char	**trimmed;

	fd = open_file(file_name);
	if (fd < 0)
		return (-1);
	data->fd = fd;
	ft_init_data_acl(data);
	arr_size = count_lines(fd);
	arr = extract_lines(file_name, arr_size);
	validate_scene(arr, arr_size);
	trimmed = remove_char(arr);
	fill_data(trimmed, data);
	return (1);
}

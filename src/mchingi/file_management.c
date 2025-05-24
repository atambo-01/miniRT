/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/24 15:00:02 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
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

int	open_file(char *file_name)
{
	int	fd;

	fd = -1;
	if (!ft_strrchr(file_name, '.'))
		return (-1);
	if (ft_strncmp(ft_strrchr(file_name, '.'), ".rt", 4) == 0)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
			perror("Error\nminiRT");
		return (fd);
	}	
	else
		ft_putstr_fd("Error\nminiRT: Wrong file extension\n", 2);
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

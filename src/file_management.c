/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:05 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/06 15:27:06 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	open_file(char *file_name)
{
	int fd;

	fd = 0;
	if (ft_strncmp(ft_strrchr(file_name, '.'), ".rt", 4) == 0)
		fd = open(file_name, O_RDONLY);
	else 
		ft_putstr_fd("Wrong file extension", 2);
	return(fd);
}

// void	file_management(char *file_name)
// {
// 	int fd;

// 	fd = open_file(file_name);

// }
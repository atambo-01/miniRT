/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:51:59 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:29:18 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int ft_check_file(int ac, char **av)
{
	int fd;
	char buffer[1];
	
	if (ac == 1)
	exit (ft_perror("miniRT: Need a file_path as param\n", 1));
	if (ac > 2)
	exit (ft_perror("miniRT: Too many params, only need one file_path\n", 1));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
		printf("miniRT: '%s': %s\n", av[1], strerror(errno));
        exit (1);
    }
	if (read(fd, buffer, 1) == -1 && errno == EISDIR)
    {
        printf("miniRT: '%s' is a directory, not a file\n", av[1]);
        close(fd);
        exit(1);
    }
	return (fd);
}
//void ft_read_file();

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:51:59 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:10:10 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int ft_check_file(int ac, char **av)
{
	int fd;
	
	if (ac == 1)
	exit (ft_perror("Need a file as input\n", 1));
	if (ac > 2)
	exit (ft_perror("Too many params, only need one file\n", 1));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
		printf("%s\n", strerror(errno));
        exit (1);
    }
	return (fd);
}
//void ft_read_file();

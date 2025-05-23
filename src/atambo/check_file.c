/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:51:59 by atambo            #+#    #+#             */
/*   Updated: 2025/05/23 16:17:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"

int	ft_check_file(int ac, char **av)
{
	int		fd;
	char	buffer[1];

	if (ac == 1)
		exit (ft_minirt_error(ERR_NEED_FILE, 1));
	if (ac > 2)
		exit (ft_minirt_error(ERR_PARAM, 1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || (read(fd, buffer, 1) == -1 && errno == EISDIR))
	{
		ft_minirt_error(av[1], 1);
		perror(" ");
		close(fd);
		exit (1);
	}
	return (fd);
}

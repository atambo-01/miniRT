/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:58 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:10:23 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = ft_check_file(ac, av);
	ft_init_data(&data, fd);
//	render_img();
	return (0);
}

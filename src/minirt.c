/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:58 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 00:21:47 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int check_file(int ac, char **av)
{
	if (ac == 1)
		exit (ft_perror("Need a file as input\n", 1);
	if (ac > 2)
		exit (ft_perror("To many params, only need one file\n", 1));
	if (open(av[1]))
		exit(ft_perror(strerror(errno), 1));
}


int main(int ac, char **av)
{
	t_data	data;

	check_file(ac, av);
	init_data(&data);
	render_img();
	return (0);
}
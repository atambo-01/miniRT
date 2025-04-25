/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 01:50:19 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				MINIRT_H
# define			MINIRT_H

# include			<stdlib.h>
# include			<unistd.h>
# include			<math.h>
# include			<stdio.h>
# include			<errno.h>
# include			<fcntl.h>
#include			<string.h>

# include			"../minilibx-linux/mlx.h"

# define ESC		65307
# define UP			65363
# define DOWN		65361
# define LEFT		65362
# define RIGHT		65364
# define W_WIDTH	1080
# define W_HEIGHT	720
# define IM_WIDTH	1080
# define IM_HEIGHT	720

typedef struct	s_data
{
	void*	mlx;
	void*	win;
	void*	img;
	void*	addr;
	int		line_len;
	int		bpp;
	int		endian;
	int		fd;
}				t_data;

int	ft_perror(char const *msg, int e);
int ft_check_file(int ac, char **av);
int ft_init_data(t_data *data, int fd);
int	key_hook(int keycode, t_data *data);
int	close_window(t_data *data);

#endif

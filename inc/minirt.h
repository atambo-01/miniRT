/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/04/25 04:37:17 by atambo           ###   ########.fr       */
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
# define IM_WIDTH	540
# define IM_HEIGHT	360

typedef struct	s_img
{
	void*	ptr;
	void*	addr;
	int		line_len;
	int		bpp;
	int		endian;
}				t_img;
typedef struct	s_data
{
	void*	mlx;
	void*	win;
	int		fd;
	t_img	img;
	t_img	s_img;
}				t_data;

// src/check_file.c
int 	ft_check_file(int ac, char **av);
// ft_perror.c
int		ft_perror(char const *msg, int e);
// src/init.c
int 	ft_init_data(t_data *data, int fd);
// src/input.c
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
// src/input_util.c
int		close_window(t_data *data);
// src/upscale_img.c
void	fill_color(t_data *data, int color);
void	fill_tiled(t_img *img, t_data *data);
void	upscale_img(t_data *data);
// src/util.c
void	pixel_put_img(t_img *img, int x, int y, int color);


#endif

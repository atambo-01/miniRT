/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/06 16:05:12 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#include <errno.h>
#include <stdbool.h>

// -----------------------------------------------------------

typedef struct s_img
{
	void	*init;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_img;


typedef struct s_mlx
{
	void	*init;
	void	*window;
}	t_mlx;


// --------------------------------------------------------------------/



// --------------------- FILE MANAGEMENT --------------------------------/
int	open_file(char *file_name);


// ----------------------- MLX UTILS -----------------------------------/
int		input_keys(int keysym, t_mlx *data);
void	ft_mlx_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_pixels(t_img *img, int x, int y, int size, int color);
void    draw_gradient(t_img *img, int width, int height);


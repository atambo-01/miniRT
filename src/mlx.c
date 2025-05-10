/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:07 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/08 17:02:15 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/miniRT.h"

int	input_keys(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->init, data->window);
		mlx_destroy_display(data->init);
		free(data->init);
		exit(1);
	}
	// printf("%d pressed!\n\n", keysym);
	return (0);
}

void	ft_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + pixel) = color;
}

void	ft_put_pixels(t_img *img, int x, int y, int size, int color)
{
	int	i = 0;
	int	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_mlx_put_pixel(img, x, y + j, color);
			j++;
		}
		i++;
	}
}

void    draw_gradient(t_img *img, int width, int height)
{
    int x = 0;
    int y = 0;
    
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            int pixel = y * img->line + x * (img->bpp / 8);
            int r = (x * 255) / width;  // Red increases with X
            int g = (y * 255) / height; // Green increases with Y
            int b = 100;                // Fixed blue
            int color = (r << 16) | (g << 8) | b;
            *(unsigned int *)(img->addr + pixel) = color;
            x++;
        }
        y++;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscale_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:24:21 by atambo            #+#    #+#             */
/*   Updated: 2025/05/06 18:10:52 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void fill_color(t_data *data, int color)
{
    t_img img;
    int x;
    int y;

    img.ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
    if (!img.ptr)
        exit(ft_perror("Failed to create image", 1));
    img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len, &img.endian);
    y = 0;
    while (y < W_HEIGHT)
    {
        x = 0;
        while (x < W_WIDTH)
        {
            ft_pixel_put_img(&img, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, img.ptr, 0, 0);
    mlx_destroy_image(data->mlx, img.ptr);
}

void fill_tiled(t_img *img, t_data *data)
{
    int x, y;
    int tile_size = 4; // Size of each chessboard square in pixels (adjust as needed)

    for (y = 0; y < IM_HEIGHT; y++)
    {
        for (x = 0; x < IM_WIDTH; x++)
        {
            // Calculate tile position
            int tile_x = x / tile_size;
            int tile_y = y / tile_size;
            // Alternate colors: black or white based on (tile_x + tile_y) parity
            int color = ((tile_x + tile_y) % 2 == 0) ? 0xFFFFFF : 0x000000;
            // Set pixel at (x, y) in the smaller image
			ft_pixel_put_img(img, x, y, color);
        }
    }
}

void ft_upscale_img(t_data *data)
{
    float scale_x = (float)IM_WIDTH / W_WIDTH;
    float scale_y = (float)IM_HEIGHT / W_HEIGHT;

    for (int y = 0; y < W_HEIGHT; y++)
    {
        for (int x = 0; x < W_WIDTH; x++)
        {
            float src_x = x * scale_x;
            float src_y = y * scale_y;
            int x0 = (int)src_x;
            int y0 = (int)src_y;
            int x1 = x0 + 1 < IM_WIDTH ? x0 + 1 : x0;
            int y1 = y0 + 1 < IM_HEIGHT ? y0 + 1 : y0;
            float fx = src_x - x0;
            float fy = src_y - y0;

            int *p00 = (int *)(data->img.addr + y0 * data->img.line_len + x0 * (data->img.bpp / 8));
            int *p10 = (int *)(data->img.addr + y0 * data->img.line_len + x1 * (data->img.bpp / 8));
            int *p01 = (int *)(data->img.addr + y1 * data->img.line_len + x0 * (data->img.bpp / 8));
            int *p11 = (int *)(data->img.addr + y1 * data->img.line_len + x1 * (data->img.bpp / 8));

            int r00 = (*p00 >> 16) & 0xFF, g00 = (*p00 >> 8) & 0xFF, b00 = *p00 & 0xFF;
            int r10 = (*p10 >> 16) & 0xFF, g10 = (*p10 >> 8) & 0xFF, b10 = *p10 & 0xFF;
            int r01 = (*p01 >> 16) & 0xFF, g01 = (*p01 >> 8) & 0xFF, b01 = *p01 & 0xFF;
            int r11 = (*p11 >> 16) & 0xFF, g11 = (*p11 >> 8) & 0xFF, b11 = *p11 & 0xFF;

            float r = (1 - fx) * (1 - fy) * r00 + fx * (1 - fy) * r10 +
                      (1 - fx) * fy * r01 + fx * fy * r11;
            float g = (1 - fx) * (1 - fy) * g00 + fx * (1 - fy) * g10 +
                      (1 - fx) * fy * g01 + fx * fy * g11;
            float b = (1 - fx) * (1 - fy) * b00 + fx * (1 - fy) * b10 +
                      (1 - fx) * fy * b01 + fx * fy * b11;

            float r_sum = r, g_sum = g, b_sum = b;
            int count = 1;
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x0 + dx;
                    int ny = y0 + dy;
                    if (nx >= 0 && nx < IM_WIDTH && ny >= 0 && ny < IM_HEIGHT)
                    {
                        int *p = (int *)(data->img.addr + ny * data->img.line_len + nx * (data->img.bpp / 8));
                        r_sum += (*p >> 16) & 0xFF;
                        g_sum += (*p >> 8) & 0xFF;
                        b_sum += *p & 0xFF;
                        count++;
                    }
                }
            }
            r = r_sum / count;
            g = g_sum / count;
            b = b_sum / count;

            int color = ((int)r << 16) | ((int)g << 8) | (int)b;
            ft_pixel_put_img(&data->s_img, x, y, color);
        }
    }
}
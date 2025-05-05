/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by mchingi           #+#    #+#             */
/*   Updated: 2025/05/02 15:30:35 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"

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


// -----------------------------------------------------------



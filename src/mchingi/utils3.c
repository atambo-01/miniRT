/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:08:11 by mchingi           #+#    #+#             */
/*   Updated: 2025/06/14 13:39:49 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include "../../inc/miniRT_atambo.h"
#include "../../inc/miniRT_mchingi.h"

int	ft_valid_double(char *token)
{
	int	j;
	int	has_decimal;

	j = 0;
	has_decimal = 0;
	if (!token[0])
		return (0);
	if (token[0] == '-' || token[0] == '+')
		j++;
	if (token[j] == 0)
		return (0);
	while (token[j])
	{
		if (token[j] == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (!ft_isdigit(token[j]))
			return (0);
		j++;
	}
	return (1);
}

int	fill_radius(t_obj *obj, char **data_line, int i)
{

	if (!obj)
		return (0);
	obj->radius = -1.0; 
	if (ft_valid_double(data_line[i]))
		obj->radius = ft_atof(data_line[i]) / 2;
	if (ft_strcmp(obj->type, "cy") == 0)
	{
		obj->len = -1.0;
		if (ft_valid_double(data_line[i + 1]))
			obj->len = ft_atof(data_line[i + 1]);
		if (ft_cmp_dbl(obj->len, "<=", 0))
			obj->radius = -1.0; 

	}
	if (ft_cmp_dbl(obj->radius, "<=", 0))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_RADLEN, 1);
		return (0);
	}
	return (1);
}

int	ft_fill_fov(t_cam *cam, char **data_line, int i)
{
	if (!cam)
		return (1);
	if (ft_valid_double(data_line[i]))
		cam->fov = ft_atof(data_line[i]);
	else
		cam->fov = -1.0;
	if (ft_cmp_dbl(cam->fov, "<", 0.0) || ft_cmp_dbl(cam->fov, ">", 180.0))
	{
		ft_minirt_error("Parsing error\n", 1);
		ft_perror(E_FOV, 1);
		return (1);
	}
	return (0);
}


int	check_coord_tokens(char **xyz)
{
	int	i;

	i = 0;
	if (!xyz)
		return (0);
	while (xyz[i])
	{
		if (!ft_valid_double(xyz[i++]))
			return (0);
	}
	return (1);
}

int	ft_check_filename(char *filename)
{
	char	*tmp;

	tmp = filename;
	if (ft_strrchr(filename, '/') != NULL)
	{
		tmp = ft_strrchr(filename, '/');
		tmp++;
	}
	if (tmp[0] == '.')
		tmp++;
	if (!(ft_strrchr(tmp, '.'))
		|| (ft_strlen((ft_strrchr(tmp, '.'))) != 3)
		|| (ft_strcmp(ft_strrchr(tmp, '.'), ".rt") != 0))
		return (1);
	return (0);
}

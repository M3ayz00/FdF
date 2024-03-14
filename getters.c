/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:45:15 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/14 03:51:53 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_3d_vector get_vector(t_map point)
{
	return ((t_3d_vector){point.x, point.y, point.z, point.color});
}


t_offset    get_offset(t_map_borders borders)
{
	t_offset	offset;
	int			height;
	int			width;

	width = abs(borders.max.x - borders.min.x);
	height = abs(borders.max.y - borders.min.y);
	offset.x = round((WIDTH - width) / 2);
	// offset.x -= (borders.max.x * get_scale(borders)) / 2;
	offset.y = round((HEIGHT - height) / 2);
	// offset.y -= (borders.max.y * get_scale(borders)) / 2;
	return (offset);
}

double	get_scale(t_map_borders borders)
{
	int	height;
	int	width;

	width = abs(borders.max.x - borders.min.x);
	height = abs(borders.max.y - borders.min.y);
	return (ft_min((WIDTH - WIDTH / 8) / width, (HEIGHT - HEIGHT / 8) / height));
}

t_map_borders   get_map_borders(t_map **map, double scale, t_fdf *fdf)
{
	int				i;
	int				j;
	t_3d_vector		point;
	
	fdf->map_borders.min = (t_2d_vector){0, 0};
	fdf->map_borders.max = (t_2d_vector){0, 0};
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(!map[i][++j].end)
		{
			point = isometric(apply_scale(get_vector(map[i][j]), scale), fdf);
			if (fdf->map_borders.min.x > floor(point.x))
				fdf->map_borders.min.x = floor(point.x);
			else if (fdf->map_borders.max.x < ceil(point.x))
				fdf->map_borders.max.x = ceil(point.x);
			if (fdf->map_borders.min.y > floor(point.y))
				fdf->map_borders.min.y = floor(point.y);
			else if (fdf->map_borders.max.y < ceil(point.y))
				fdf->map_borders.max.y = ceil(point.y);
		}
	}
	return (fdf->map_borders);
}


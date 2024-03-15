/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:45:15 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/14 17:22:35 by msaadidi         ###   ########.fr       */
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
	offset.y = round((HEIGHT - height) / 2);
	if (borders.min.x < 0)
		offset.x += abs((int)round(borders.min.x));
	if (borders.min.y < 0)
		offset.y += abs((int)round(borders.min.y));
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
	t_map_borders	borders;
	
	borders.min = (t_2d_vector){0, 0};
	borders.max = (t_2d_vector){0, 0};
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(!map[i][++j].end)
		{
			point = isometric(apply_scale(get_vector(map[i][j]), scale), fdf);
			if (borders.min.x > floor(point.x))
				borders.min.x = floor(point.x);
			else if (borders.max.x < ceil(point.x))
				borders.max.x = ceil(point.x);
			if (borders.min.y > floor(point.y))
				borders.min.y = floor(point.y);
			else if (borders.max.y < ceil(point.y))
				borders.max.y = ceil(point.y);
		}
	}
	return (borders);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:45:15 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/13 18:14:22 by msaadidi         ###   ########.fr       */
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
	if (borders.max.x - borders.min.x < 0)
		offset.x -= round(abs(borders.max.x - borders.min.x) / 2);
	if (borders.max.y - borders.min.y < 0)
		offset.y -= round(abs(borders.max.y - borders.min.y) / 2);
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

t_map_borders   get_map_borders(t_map **map)
{
	t_map_borders	dims;
	int				i;
	int				j;
	t_3d_vector		point;
	
	dims.min = (t_2d_vector){0, 0};
	dims.max = (t_2d_vector){0, 0};
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(!map[i][++j].end)
		{
			point = get_vector(map[i][j]);
			if (dims.min.x > floor(point.x))
				dims.min.x = floor(point.x);
			else if (dims.max.x < ceil(point.x))
				dims.max.x = ceil(point.x);
			if (dims.min.y > floor(point.y))
				dims.min.y = floor(point.y);
			else if (dims.max.y < ceil(point.y))
				dims.max.y = ceil(point.y);
		}
	}
	return (dims);
}


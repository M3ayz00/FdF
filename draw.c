/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:57:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/11 15:59:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw(t_map **map, t_fdf *fdf)
{
	int			i;
	int			j;
	t_3d_vector	point;
	double		scale;
	t_offset	offset;

	scale = get_scale(get_map_borders(map));
	printf("Scale : %f\n", scale);
	offset = get_offset(get_map_borders(map));
	printf("offset x : %d, offset y : %d\n", offset.x, offset.y);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (!map[i][++j].end)
		{
			point = scale_n_offset(get_vector(map[i][j]), scale, offset);
			if (!map[i][j + 1].end)
				draw_line(fdf, point, scale_n_offset(
						get_vector(map[i][j + 1]), scale, offset));
			if (map[i + 1])
				draw_line(fdf, point, scale_n_offset(
						get_vector(map[i + 1][j]), scale, offset));
		}
	}
}

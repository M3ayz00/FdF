/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:57:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/13 18:20:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw(t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	int			i;
	int			j;
	t_3d_vector	currentPoint;

	i = -1;
	while (fdf->map[++i])
	{
		j = -1;
		while (!fdf->map[i][++j].end)
		{
			currentPoint = scale_n_offset(get_vector(fdf->map[i][j]), fdf, trans);
			if (!fdf->map[i][j + 1].end)
				draw_line(fdf, currentPoint, scale_n_offset(
						get_vector(fdf->map[i][j + 1]), fdf, trans));
			if (fdf->map[i + 1])
				draw_line(fdf, currentPoint, scale_n_offset(
						get_vector(fdf->map[i + 1][j]), fdf, trans));
		}
	}
}

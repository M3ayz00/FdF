/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:57:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/21 21:13:24 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	clear_img(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			my_put_pixel(&fdf->img, x, y, 0x000000);
	}
}

void	draw(t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	int			i;
	int			j;
	t_3d_vector	current_point;

	clear_img(fdf);
	i = -1;
	while (fdf->map[++i])
	{
		j = -1;
		while (!fdf->map[i][++j].end)
		{
			current_point = scale_n_offset(
					get_vector(fdf->map[i][j]), fdf, trans);
			if (!fdf->map[i][j + 1].end)
				draw_line(fdf, current_point,
					scale_n_offset(
						get_vector(fdf->map[i][j + 1]), fdf, trans));
			if (fdf->map[i + 1])
				draw_line(fdf, current_point,
					scale_n_offset(
						get_vector(fdf->map[i + 1][j]), fdf, trans));
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:25:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 18:23:26 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    draw_line_lower_slope(t_data *data, t_3d_vector p0, t_3d_vector p1, t_line_plot plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	int P = 2 * plt.dy - plt.dx;
	int	x = p0.x;
	int	y = p0.y;
	while (x <= p1.x)
	{
		my_put_pixel(data, x, y, 0xFFFFFF);
		x++;
		if (P < 0)
			P = P + 2 * plt.dy;
		else
		{
			P = P + 2 * plt.dy - 2 * plt.dx;
			y++;
		}
	}
}

void    draw_line_higher_slope(t_data *data, t_3d_vector p0, t_3d_vector p1, t_line_plot plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	int P = 2 * plt.dx - plt.dy;
	int	x = p0.x;
	int	y = p0.y;
	while (y <= p1.y)
	{
		my_put_pixel(data, x, y, 0xFFFFFF);
		x++;
		if (P < 0)
			P = P + 2 * plt.dx;
		else
		{
			P = P + 2 * plt.dx - 2 * plt.dy;
			y++;
		}
	}
}

void	draw_line()
{
	
}
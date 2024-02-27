/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:25:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 15:44:27 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    draw_line_lower_slope(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int P = 2 * dx - dy;
	int	x = x1;
	int	y = y1;
	while (x <= x2)
	{
		my_put_pixel(data, x, y, 0xFFFFFF);
		x++;
		if (P < 0)
			P = P + 2 * dy;
		else
		{
			P = P + 2 * dy - 2 * dx;
			y++;
		}
	}
}

void    draw_line_higher_slope(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int P = 2 * dx - dy;
	int	x = x1;
	int	y = y1;
	while (y <= y2)
	{
		my_put_pixel(data, x, y, 0xFFFFFF);
		y++;
		if (P < 0)
			P = P + 2 * dx;
		else
		{
			P = P + 2 * dx - 2 * dy;
			x++;
		}
	}
}

void	draw_line()
{
	
}
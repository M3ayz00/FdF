/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:25:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/12 21:32:39 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if ((x < WIDTH && x >= 0) && (y < HEIGHT && y >= 0))
	{
		dst = fdf->addr + (y * fdf->line_length + x * (fdf->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void    draw_line_lower_slope(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1, t_draw_tools plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	plt.yi = 1;
	if (plt.dy < 0)
	{
		plt.dy *= -1;
		plt.yi = -1;
	}
	plt.P = 2 * plt.dy - plt.dx;
	plt.curr.x = p0.x;
	plt.curr.y = p0.y;
	while (plt.curr.x <= p1.x)
	{
		my_put_pixel(fdf, plt.curr.x, plt.curr.y, grad_col_pos(p0, plt.curr, p1));
		plt.curr.x++;
		if (plt.P < 0)
			plt.P = plt.P + 2 * plt.dy;
		else
		{
			plt.P = plt.P + 2 * plt.dy - 2 * plt.dx;
			plt.curr.y += plt.yi;
		}
	}
}

void    draw_line_higher_slope(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1, t_draw_tools plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	plt.xi = 1;
	if (plt.dx < 0)
	{
		plt.dx *= -1;
		plt.xi = -1;
	}
	plt.P = 2 * plt.dx - plt.dy;
	plt.curr.x = p0.x;
	plt.curr.y = p0.y;
	while (plt.curr.y <= p1.y)
	{
		my_put_pixel(fdf, plt.curr.x, plt.curr.y, grad_col_pos(p0, plt.curr, p1));
		plt.curr.y++;
		if (plt.P < 0)
			plt.P = plt.P + 2 * plt.dx;
		else
		{
			plt.P = plt.P + 2 * plt.dx - 2 * plt.dy;
			plt.curr.x += plt.xi;
		}
	}
}

void	draw_line(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1)
{
	t_draw_tools    plt;

    plt.dx = p1.x - p0.x;
    plt.dy = p1.y - p0.y;
    if (abs(plt.dx) > abs(plt.dy))
    {
        if (p1.x - p0.x > 0)
            draw_line_lower_slope(fdf, p0, p1, plt);
        else
            draw_line_lower_slope(fdf, p1, p0, plt);
    }
    else
    {
        if (p1.y - p0.y > 0)
            draw_line_higher_slope(fdf, p0, p1, plt);
        else
            draw_line_higher_slope(fdf, p1, p0, plt);
    }
}
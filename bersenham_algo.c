/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:25:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/10 19:04:10 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bpp / 8));
	*(unsigned int*)dst = color;
}


void    draw_line_lower_slope(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1, t_draw_tools plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	int P = 2 * plt.dy - plt.dx;
	int	x = p0.x;
	int	y = p0.y;
	while (x <= p1.x)
	{
		my_put_pixel(fdf, x, y, 0xFFFFFF);
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

void    draw_line_higher_slope(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1, t_draw_tools plt)
{
	plt.dx = p1.x - p0.x;
	plt.dy = p1.y - p0.y;
	int P = 2 * plt.dx - plt.dy;
	int	x = p0.x;
	int	y = p0.y;
	while (y <= p1.y)
	{
		my_put_pixel(fdf, x, y, 0xFFFFFF);
		y++;
		if (P < 0)
			P = P + 2 * plt.dx;
		else
		{
			P = P + 2 * plt.dx - 2 * plt.dy;
			x++;
		}
	}
}

void	draw_line(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1)
{
	 t_draw_tools    plt;

    plt.dx = abs(p1.x - p0.x);
    plt.dy = abs(p1.y - p0.x);
    if (plt.dx < plt.dy)
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
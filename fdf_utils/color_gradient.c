/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:14:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/24 01:39:37 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

double	get_position(t_3d_vector start, t_3d_vector curr, t_3d_vector end)
{
	double	full_len;
	double	part_len;

	full_len = hypot(end.x - start.x, end.y - start.y);
	part_len = hypot(curr.x - start.x, curr.y - start.y);
	if (full_len)
		return (part_len / full_len);
	return (1);
}

int	grad_color(int s_col, int e_col, double pos)
{
	t_color	s_rgbt;
	t_color	e_rgbt;
	t_color	color;

	s_rgbt = split_color(s_col);
	e_rgbt = split_color(e_col);
	color.t = s_rgbt.t * (1 - pos) + e_rgbt.t * pos;
	color.r = s_rgbt.r * (1 - pos) + e_rgbt.r * pos;
	color.g = s_rgbt.g * (1 - pos) + e_rgbt.g * pos;
	color.b = s_rgbt.b * (1 - pos) + e_rgbt.b * pos;
	return (merge_colors(color.t, color.r, color.g, color.b));
}

int	grad_col_pos(t_3d_vector start, t_3d_vector curr, t_3d_vector end)
{
	double	position;

	position = get_position(start, curr, end);
	return (grad_color(start.color, end.color, position));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:14:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/11 16:45:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int get_position(t_3d_vector start, t_3d_vector curr, t_3d_vector end)
{
    int full_len;
    int part_len;

    full_len = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    part_len = sqrt(pow(curr.x - start.x, 2) + pow(curr.y - start.y, 2));
    if(full_len)
        return (part_len / full_len);
    return (1);
}

int grad_color(int s_col, int e_col, int pos)
{
    t_color s_rbgt;
    t_color e_rgbt;
    t_color color;

    s_rbgt = split_color(s_col);
    e_rgbt = split_color(e_col);
    color.t = round(s_rbgt.t * (1 - pos) + e_rgbt.t * pos);
    color.r = round(s_rbgt.r * (1 - pos) + e_rgbt.r * pos);
    color.g = round(s_rbgt.g * (1 - pos) + e_rgbt.g * pos);
    color.b = round(s_rbgt.b * (1 - pos) + e_rgbt.b * pos);
    return (merge_colors(color.t, color.r, color.g, color.b));
}

int grad_col_pos(t_3d_vector start, t_3d_vector curr, t_3d_vector end)
{
    int position;

    position = get_position(start, curr, end);
    return (grad_color(start.color, end.color, position));
}
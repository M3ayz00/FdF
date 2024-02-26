/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:08:04 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/26 18:50:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int merge_colors(int a, int r, int g, int b)
{
    return (a << 24 | r << 16 | g << 8 | b);
}

t_color split_color(int argb)
{
    t_color color;
    
    color.a = (argb >> 24) & 0xFF;
    color.r = (argb >> 16) & 0xFF;
    color.g = (argb >> 8) & 0xFF;
    color.b = argb & 0xFF;
    if (!color.a)
        color.a = 0xFF;
}

int get_color_from_str(char *str)
{
    t_color color;
    if (str && str +2)
    {
        color = split_color(ft_atoi_base(str + 2, 16));
        return (merge_colors(color.a, color.r, color.g, color.b));
    }
    return (merge_colors(0xFF, 0xFF, 0xFF, 0xFF));
}

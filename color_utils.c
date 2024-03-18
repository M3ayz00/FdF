/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:08:04 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/18 20:56:22 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	merge_colors(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	split_color(int rgbt)
{
	t_color	color;

	color.t = rgbt >> 24 & 0xFF;
	color.r = rgbt >> 16 & 0xFF;
	color.g = rgbt >> 8 & 0xFF;
	color.b = rgbt & 0xFF;
	return (color);
}

int	get_color_from_str(char *str)
{
	t_color	color;

	if (str && str + 2)
	{
		color = split_color(ft_atoi_base(str + 2, 16));
		if (ft_strlen(str + 2) > 0 && ft_strlen(str + 2) < 7)
			color.t = 0x00;
		return (merge_colors(color.t, color.r, color.g, color.b));
	}
	return (merge_colors(0x00, 0xFF, 0xFF, 0xFF));
}

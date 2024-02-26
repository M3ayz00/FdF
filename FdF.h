/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:16:09 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/26 18:45:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	original_depth;
	int	color;
	int	end;
}	t_map;

typedef struct	s_color
{
	int	a;
	int	r;
	int	g;
	int	b;	
}	t_color;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void    draw_line_lower_slope(t_data *data, int x1, int y1, int x2, int y2);
void	my_put_pixel(t_data *data, int x, int y, int color);
int		get_color_from_str(char *str);


#endif
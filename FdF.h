/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:16:09 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/10 22:25:12 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define WIDTH	800
# define HEIGHT	600

typedef	struct s_draw_tools
{
	int	curr_x;
	int	curr_y;
	int	dx;
	int	dy;
	int	P;
	int	xi;
	int	yi;
}	t_draw_tools;

typedef	struct	s_2d_vector
{
	int	x;
	int	y;
}	t_2d_vector;

typedef	struct	s_3d_vector
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_3d_vector;

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	original_depth;
	int	color;
	int	end;
}	t_map;

typedef struct s_map_borders
{
	t_2d_vector min;
	t_2d_vector max;
}	t_map_borders;

typedef struct	s_color
{
	int	t;
	int	r;
	int	g;
	int	b;	
}	t_color;

typedef struct	s_fdf 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_fdf;

typedef	struct s_offset
{
	int	x;
	int	y;
}	t_offset;


void	draw_line(t_fdf *fdf, t_3d_vector p0, t_3d_vector p1);
void	my_put_pixel(t_fdf *data, int x, int y, int color);
int		get_color_from_str(char *str);
t_map	**get_map(char	*filename);
void    perror_and_exit(char *err);
void    free_strs(char **strs);
void    free_map_coors(char ***strs);
void    free_map_elems(t_map **map_elems);

double	get_scale(t_map_borders borders);
t_map_borders   get_map_borders(t_map **map);
t_offset    get_offset(t_map_borders borders);
t_3d_vector get_vector(t_map point);
t_3d_vector scale_n_offset(t_3d_vector point, double scale, t_offset offset);
void    draw(t_map **map, t_fdf *fdf);
t_3d_vector ft_offset(t_3d_vector point, t_offset offset);


#endif
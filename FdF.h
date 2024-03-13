/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:16:09 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/13 18:22:56 by msaadidi         ###   ########.fr       */
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

# define WIDTH	1024
# define HEIGHT	1024


typedef	struct	s_2d_vector
{
	int	x;
	int	y;
}	t_2d_vector;

typedef	struct	s_3d_vector
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_3d_vector;

typedef struct s_3d_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector	k;
}	t_3d_matrix;


typedef	struct s_draw_tools
{
	t_3d_vector curr;
	int	dx;
	int	dy;
	int	P;
	int	xi;
	int	yi;
}	t_draw_tools;

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
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

typedef	struct s_offset
{
	int	x;
	int	y;
}	t_offset;

typedef struct	s_fdf 
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	t_map			**map;
	t_map_borders	map_borders;
	t_offset		offset;
	double			scale;
	double			x_deg;
	double			y_deg;
	double			z_deg;
}				t_fdf;



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
t_3d_vector	scale_n_offset(t_3d_vector point, t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *));
void	draw(t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *));
t_3d_vector	apply_offset(t_3d_vector point, t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *));
t_3d_vector apply_scale(t_3d_vector point, double scale);
t_color split_color(int rgbt);
int merge_colors(int t, int r, int g, int b);
int grad_col_pos(t_3d_vector start, t_3d_vector curr, t_3d_vector end);
t_3d_vector isometric(t_3d_vector v , t_fdf *fdf);
void key_hooks(int keycode, void *param);


#endif
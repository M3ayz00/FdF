/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:59:08 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/26 18:59:13 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char    **get_map_lines(int fd)
{
	char	*line;
	char	*all_lines;
	char	**lines;
	all_lines = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	while (line)
	{
		all_lines = ft_strjoin2(all_lines, line);
		free(line);
		line = get_next_line(fd);
	}
	lines = ft_split(all_lines, '\n');
	close(fd);
	return (lines);
}

char	***get_map_coors(char	**map_lines)
{
	char	***coors;
	int		i;

	coors = (char ***)ft_calloc(ft_strs_len(map_lines) + 1, sizeof(char **));
	i = 0;
	while (map_lines[i])
	{
		coors[i] = ft_split(map_lines[i], ' ');
		i++;
	}
	return (coors);
}
t_map	**fill_map_elems(char ***map_strs, t_map **map_elems)
{
	int		i;
	int		j;
	char	**z_n_col;

	i = 0;
	while (map_strs[i])
	{
		j = 0;
		while (map_strs[i][j])
		{
			z_n_col = ft_split(map_strs[i][j], ',');
			map_elems[i][j] = (t_map){i, j, ft_atoi(z_n_col[0]), ft_atoi(z_n_col[0]), get_color_from_str(z_n_col[1]), 0};
			j++;
		}
		i++;
	}
	return(map_elems);
}

t_map	**map_strs_to_elems(char ***map_strs)
{
	t_map	**map_elems;
	int		i;
	
	map_elems = (t_map **)ft_calloc(ft_arr_strs_len(map_strs) + 1, sizeof(t_map *));
	i = 0;
	while(map_strs[i])
	{
		map_elems[i] = (t_map *)ft_calloc(ft_strs_len(map_strs[i]) + 1, sizeof(t_map));
		i++;
	}
	return (fill_map_elems(map_strs, map_elems));
}

t_map	**get_map(char	*filename)
{
	int fd = open(filename, O_RDONLY, 0444);
	return(map_strs_to_elems(get_map_coors(get_map_lines(fd))));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:33:43 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 21:15:12 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	perror_and_exit(char *err)
{
	perror(err);
	exit(1);
}

int	check_filename(t_fdf *fdf, char *filename)
{
	int		name_len;
	char	*tmp;

	fdf->filename = ft_strtrim(filename, " \t");
	if (!fdf->filename)
		return (free(fdf->filename), 1);
	tmp = fdf->filename;
	name_len = ft_strlen(tmp);
	tmp += name_len;
	if (name_len < 4 && ft_strncmp(tmp - 4, ".fdf", 4) != 0)
		return (1);
	return (0);
}

int	parse_args(int ac, char **av, t_fdf *fdf)
{
	if (ac != 2)
		return (ft_putendl_fd("Usage : ./fdf <mapfile>.", 2));
	else if (check_filename(fdf, av[1]))
		return (ft_putendl_fd("Invalid fdf file.", 2));
	return (0);
}

int	treat_errors(t_fdf *fdf)
{
	fdf->map = get_map(fdf->filename);
	if (!fdf->map)
		return (EXIT_FAILURE);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (EXIT_FAILURE);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "M3ayzoo's FdF");
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->mlx_win || !fdf->img.img)
		return (EXIT_FAILURE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img,
			&fdf->img.bpp, &fdf->img.line_length, &fdf->img.endian);
	if (!fdf->img.addr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

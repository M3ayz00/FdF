/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:53 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/17 23:45:50 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int ac, char **av)
{
    t_fdf  fdf;

    if (parse_args(ac, av, &fdf))
        return (EXIT_FAILURE);
    if (treat_errors(&fdf))
        return (EXIT_FAILURE);
    fdf.scale = get_scale(get_map_borders(fdf.map, 1, &fdf));
    fdf.offset = get_offset(get_map_borders(fdf.map, fdf.scale, &fdf));
    draw(&fdf, isometric);
    mlx_hook(fdf.mlx_win, 2, 1L<<0, key_hooks, &fdf);
    mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
    mlx_loop(fdf.mlx);
}

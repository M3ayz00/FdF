/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:53 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/15 16:40:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int ac, char **av)
{
    (void)ac;
    t_fdf  fdf;

    fdf.mlx = mlx_init();
    fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Hello World");
    fdf.img.img = mlx_new_image(fdf.mlx , WIDTH, HEIGHT);
    fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bpp, &fdf.img.line_length, &fdf.img.endian);
    fdf.map = get_map(av[1]);
    fdf.scale = get_scale(get_map_borders(fdf.map, 1, &fdf));
    fdf.offset = get_offset(get_map_borders(fdf.map, fdf.scale, &fdf));
    draw(&fdf, isometric);
    mlx_hook(fdf.mlx_win, 2, 1L<<0, key_hooks, &fdf);
    mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
    mlx_loop(fdf.mlx);
}


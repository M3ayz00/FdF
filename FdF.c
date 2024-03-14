/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:53 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/14 03:53:54 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int ac, char **av)
{
    (void)ac;
    t_fdf  fdf;

    fdf.mlx = mlx_init();
    fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Hello World");
    fdf.img = mlx_new_image(fdf.mlx , WIDTH, HEIGHT);
    fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.line_length, &fdf.endian);
    fdf.map = get_map(av[1]);
    fdf.scale = get_scale(get_map_borders(fdf.map, 1, &fdf));
    fdf.offset = get_offset(get_map_borders(fdf.map, fdf.scale, &fdf));
    draw(&fdf, isometric);
    mlx_loop_hook(fdf.mlx, key_hooks, &fdf);
    mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img, 0, 0);
    mlx_loop(fdf.mlx);
}

// int main(int ac, char **av)
// {
// if (ac != 2)
//     {
//         perror("Error");
//         return (1);
//     }
//     else
//     {
//         get_map(av[1]);
//         system("Leaks fdf");
//         return (0);
//     }
// }
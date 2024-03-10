/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:53 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/10 22:25:36 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int ac, char **av)
{
    (void)ac;
    void    *mlx;
    void    *mlx_win;
    t_fdf  fdf;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World");
    fdf.img = mlx_new_image(mlx , WIDTH, HEIGHT);
    fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.line_length, &fdf.endian);
    draw(get_map(av[1]),&fdf);
    mlx_put_image_to_window(mlx, mlx_win, fdf.img, 0, 0);
    mlx_loop(mlx);
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
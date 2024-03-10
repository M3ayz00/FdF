/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:51:53 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/10 19:12:53 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main()
{
    void    *mlx;
    void    *mlx_win;
    t_fdf  fdf;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
    fdf.img = mlx_new_image(mlx , 1920, 1080);
    fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.line_length, &fdf.endian);
    draw_line(&fdf, (t_3d_vector){150, 0, 0, 0xFFFFFF}, (t_3d_vector){150, 150, 0, 0xFFFFFF});
    draw_line(&fdf, (t_3d_vector){0, 150, 0, 0xFFFFFF}, (t_3d_vector){150, 150, 0, 0xFFFFFF});
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
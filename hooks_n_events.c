/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_n_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:02:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/16 21:52:51 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void    draw_mode(char mode, t_fdf *fdf)
{
    void *trans;
    if (mode == 'I')
        trans = isometric;
    else if (mode == 'U')
        trans = top_down;
    else if (mode == 'R')
        trans = right_view;
    else
        trans = rotate;
    draw(fdf, trans);
}

int key_hooks(int keycode, void *param)
{
    t_fdf   *fdf;
    
    fdf = (t_fdf *)param;
    printf("%d\n", keycode);
    if (keycode == KEY_I)
        draw_mode('I', fdf);
    else if (keycode == KEY_T)
        draw_mode('U', fdf);
    else if (keycode == KEY_R)
        draw_mode('R', fdf);
    else if (keycode == KEY_MULTP)
        fdf->depth += 1;
    else if (keycode == KEY_DIV)
        fdf->depth -= 1;
    else if (keycode == KEY_DOWN)
        fdf->offset.y -= 10;
    else if (keycode == KEY_UP)
        fdf->offset.y += 10;
    else if (keycode == KEY_RIGHT)
        fdf->offset.x += 10;
    else if (keycode == KEY_LEFT)
        fdf->offset.x -= 10;
    else if (keycode == KEY_S)
        fdf->x_deg -= 0.1;
    else if (keycode == KEY_W)
        fdf->x_deg += 0.1;
    else if (keycode == KEY_A)
        fdf->y_deg -= 0.1;
    else if (keycode == KEY_D)
        fdf->y_deg += 0.1;
    else if (keycode == KEY_ADD)
    {
        if (fdf->scale < 1000)   
            fdf->scale += 1;
    }
    else if (keycode == KEY_SUBSTRACT)
    {
        if (fdf->scale > 2) 
            fdf->scale -= 1;
    }
    draw_mode('N', fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_n_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:02:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/15 17:21:57 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int key_hooks(int keycode, void *param)
{
    t_fdf   *fdf;
    
    fdf = (t_fdf *)param;
    printf("%d\n", keycode);
    if (keycode == KEY_DOWN)
        fdf->offset.y -= 5;
    else if (keycode == KEY_UP)
        fdf->offset.y += 5;
    else if (keycode == KEY_RIGHT)
        fdf->offset.x += 5;
    else if (keycode == KEY_LEFT)
        fdf->offset.x -= 5;
    else if (keycode == KEY_ADD)
    {
        if (fdf->scale < 70)   
            fdf->scale += 0.1;
    }
    else if (keycode == KEY_SUBSTRACT)
    {
        if (fdf->scale > 2) 
            fdf->scale -= 0.1;
    }
    draw(fdf, isometric);
    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
    return (0);
}
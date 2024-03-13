/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_n_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:02:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/13 17:35:30 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int key_hooks(int keycode, void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    if (keycode == 262)
        fdf->x_deg += 0.1;
    if (keycode == 263)
        fdf->x_deg -= 0.1;
    if (keycode == 265)
        fdf->y_deg += 0.1;
    if (keycode == 264)
        fdf->y_deg += 0.1;
    draw(&fdf, isometric);
    return (0);
}
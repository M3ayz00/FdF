/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:02:49 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/24 01:23:06 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	draw_mode(char mode, t_fdf *fdf)
{
	void	*trans;

	if (mode == 'I')
		trans = isometric;
	else if (mode == 'U')
		trans = parallel;
	else
		trans = rotate;
	draw(fdf, trans);
}

void	key_hooks_2(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_DOWN)
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
	else if (keycode == KEY_MULTP)
		fdf->depth += 1;
	else if (keycode == KEY_DIV)
		fdf->depth -= 1;
}

int	key_hooks(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	key_hooks_2(keycode, fdf);
	if (keycode == KEY_I)
		draw_mode('I', fdf);
	else if (keycode == KEY_T)
		draw_mode('U', fdf);
	else if (keycode == KEY_R)
		draw_mode('R', fdf);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
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

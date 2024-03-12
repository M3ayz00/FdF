/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_n_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:13:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/12 21:28:56 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_3d_vector	ft_scale(t_3d_vector point, double scale)
{
	return ((t_3d_vector){
		point.x *= scale,
		point.y *= scale,
		point.z *= scale,
		point.color
	});
}

t_3d_vector	ft_offset(t_3d_vector point, t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	t_3d_vector	tmp;

	tmp = trans(point, fdf);
	return ((t_3d_vector){
		tmp.x += fdf->offset.x,
		tmp.y += fdf->offset.y,
		tmp.z,
		tmp.color
	});
}

t_3d_vector	scale_n_offset(t_3d_vector point, t_fdf *fdf, t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	return (ft_offset(ft_scale(point, fdf->scale), fdf, trans));
}

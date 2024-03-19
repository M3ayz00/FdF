/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_and_offsetting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:13:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 21:22:17 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_3d_vector	apply_scale(t_3d_vector point, double scale)
{
	return ((t_3d_vector){
		point.x *= scale,
		point.y *= scale,
		point.z *= scale,
		point.color
	});
}

t_3d_vector	apply_offset(t_3d_vector point, t_fdf *fdf,
	t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	point = trans(point, fdf);
	return ((t_3d_vector){
		point.x += fdf->offset.x,
		point.y += fdf->offset.y,
		point.z,
		point.color
	});
}

t_3d_vector	scale_n_offset(t_3d_vector point, t_fdf *fdf,
	t_3d_vector (*trans)(t_3d_vector, t_fdf *))
{
	return (apply_offset(apply_scale(point, fdf->scale), fdf, trans));
}

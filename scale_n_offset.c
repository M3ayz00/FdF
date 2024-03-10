/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_n_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:13:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/10 18:22:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_3d_vector ft_scale(t_3d_vector point, double scale)
{
    return ((t_3d_vector)
    {
        point.x *= scale,
        point.y *= scale,
        point.z *= scale,
        point.color
    });
}

t_3d_vector ft_offset(t_3d_vector point, t_offset offset)
{
    return ((t_3d_vector)
    {
        point.x += offset.x,
        point.y += offset.y,
        point.z,
        point.color
    });
}

t_3d_vector scale_n_offset(t_3d_vector point, double scale, t_offset offset)
{
    return (ft_offset(ft_scale(point, scale), offset));
}
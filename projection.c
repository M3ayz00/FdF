/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:09:09 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/12 22:03:16 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_3d_vector matrix_x_vector(t_3d_matrix m, t_3d_vector v)
{
    double *tmp;
    
    tmp = (double[3]){v.x, v.y, v.z};
    v.x = tmp[0] * m.i.x + tmp[1] * m.j.x + tmp[2] * m.k.x;
    v.y = tmp[0] * m.i.y + tmp[1] * m.j.y + tmp[2] * m.k.y;
    v.z = tmp[0] * m.i.z + tmp[1] * m.j.z + tmp[2] * m.k.z;
    return (v);
}

t_3d_matrix get_rot_matrix(char axis, double deg)
{
    if (axis == 'x')
        return ((t_3d_matrix){
            (t_3d_vector){1, 0, 0, 0},
            (t_3d_vector){0, cos(deg), -sin(deg), 0},
            (t_3d_vector){0, sin(deg), cos(deg), 0}
        });
    if (axis == 'y')
        return ((t_3d_matrix){
            (t_3d_vector){cos(deg), 0, sin(deg), 0},
            (t_3d_vector){0, 1, 0, 0},
            (t_3d_vector){-sin(deg), 0, cos(deg), 0}
        });
    if (axis == 'z')
        return ((t_3d_matrix){
            (t_3d_vector){cos(rad(deg)), -sin(rad(deg)), 0, 0},
            (t_3d_vector){sin(rad(deg)), cos(rad(deg)), 0, 0},
            (t_3d_vector){0, 0, 1, 0}
        });
    return ((t_3d_matrix){
        (t_3d_vector){1, 0, 0, 0},
        (t_3d_vector){0, 1, 0, 0},
        (t_3d_vector){0, 0, 1, 0}
    });
}

t_3d_vector isometric(t_3d_vector v, t_fdf *fdf)
{
    double z_deg = atan(sqrt(2));
    double x_deg = 90;
    v = matrix_x_vector(get_rot_matrix('z', z_deg), v);
    v = matrix_x_vector(get_rot_matrix('x', x_deg), v);
    fdf->z_deg = z_deg;
    fdf->x_deg = x_deg;
    fdf->y_deg = 0;
    return (v);
}
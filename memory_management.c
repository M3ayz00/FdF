/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:33:59 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 00:03:34 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_map_coors(char ***strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free_strs(strs[i]);
		i++;
	}
	free(strs);
}

void	free_map_elems(t_map **map_elems)
{
	int	i;

	i = 0;
	while (map_elems[i])
	{
		free(map_elems[i]);
		i++;
	}
	free(map_elems);
}

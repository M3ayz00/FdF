/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_longest_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:24:04 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/23 20:36:40 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_longest_line(char ***lines)
{
	size_t	i;
	size_t	longest;

	longest = 0;
	i = 1;
	if (lines && lines[0])
		longest = ft_strs_len(lines[0]);
	while (lines && lines[i])
	{
		if (longest < ft_strs_len(lines[i]))
			longest = ft_strs_len(lines[i]);
		i++;
	}
	return (longest);
}

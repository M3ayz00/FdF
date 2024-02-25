/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_strs_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:05:38 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/25 19:11:02 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arr_strs_len(char ***arr_strs)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while(arr_strs[i])
	{
		counter += ft_strs_len(arr_strs[i]);
		i++;
	}
	return (i);
}
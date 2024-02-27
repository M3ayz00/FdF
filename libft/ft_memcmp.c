/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:48:58 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 16:00:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( void *str1,  void *str2, size_t n)
{
	 unsigned char	*s1;
	 unsigned char	*s2;
	size_t				i;

	s1 = ( unsigned char *)str1;
	s2 = ( unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:57 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 16:00:23 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( char *str, int c)
{
	int	last_i;
	int	i;

	i = 0;
	last_i = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_i = i;
		i++;
	}
	if ((char)c == '\0')
		last_i = i;
	if (last_i >= 0)
		return ((char *)str + last_i);
	return (NULL);
}

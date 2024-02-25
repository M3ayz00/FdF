/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:49 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/24 18:31:30 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	t_len;
	size_t	i;
	size_t	j;

	if (!dest && size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	t_len = d_len + s_len;
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	j = d_len;
	while (src[i] && i < size - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (t_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:56:05 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 16:01:21 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr( char *haystack,  char *needle, size_t n)
{
	size_t	n_len;

	if (haystack == needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (haystack && *haystack && n-- >= n_len)
	{
		if (ft_memcmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

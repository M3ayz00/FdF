/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:52:36 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/12 20:57:58 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	str_len;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy((new_str + ft_strlen(s1)), s2, ft_strlen(s2));
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:48:36 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/14 21:00:49 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	subs = (char *)ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	ft_memcpy(subs, s + start, len);
	return (subs);
}

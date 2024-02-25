/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:25:50 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/12 21:16:37 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *set, char const *s)
{
	int	i;

	i = 0;
	while (s[i] && (ft_strchr(set, s[i])))
		i++;
	return (i);
}

static int	ft_end(const char *set, char const *s)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (j > 0 && (ft_strchr(set, s[j])))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	if (!s || !set)
		return (NULL);
	i = ft_start(set, s);
	j = ft_end(set, s);
	j++;
	if (i < j)
	{
		tmp = ft_calloc(j - i + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, s + i, j - i);
	}
	else
	{
		tmp = ft_calloc(1, sizeof(char));
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

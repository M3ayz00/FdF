/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:25:50 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/18 20:23:47 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char *set, char *s)
{
	int	i;

	i = 0;
	while (s[i] && (ft_strchr(set, s[i])))
		i++;
	return (i);
}

static int	ft_end(char *set, char *s)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (j > 0 && (ft_strchr(set, s[j])))
		j--;
	return (j);
}

char	*ft_strtrim(char *s, char *set)
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
		return (NULL);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:34:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 00:31:02 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word(char *s, char c, int j)
{
	char	*word;
	int		i;

	i = 0;
	while (s[j] && s[j] != c)
	{
		i++;
		j++;
	}
	word = (char *)ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	j -= i;
	i = 0;
	while (s[j] != c && s[j])
		word[i++] = s[j++];
	return (word);
}

static size_t	count_words(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_all(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strings = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i++])
			continue ;
		strings[j] = word(s, c, i);
		if (strings[j] == NULL)
			return (free_all(strings, j), NULL);
		i += ft_strlen(strings[j++]);
	}
	return (strings);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:05:20 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 00:09:43 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (!s || !f)
		return (NULL);
	mapped = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!mapped)
		return (NULL);
	i = -1;
	while (s[++i])
		mapped[i] = f(i, s[i]);
	return (mapped);
}

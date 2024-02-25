/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:51:15 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/12 18:50:31 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calcul(int n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		c++;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	num;
	long	nb;

	nb = n;
	num = calcul(nb);
	if (n < 0)
	{
		num++;
		nb = -nb;
	}
	str = (char *)ft_calloc(num + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (num--)
	{
		str[num] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

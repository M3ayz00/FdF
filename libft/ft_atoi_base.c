/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:28:23 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 14:54:53 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_index(char c, int base)
{
	char    *h;
	char    *H;
	int     i;
	
	h = "0123456789abcdef";
	H = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == h[i] || c == H[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(char *str, int base)
{
	int sign;
	int i;
	int result;
	
	i = 0;
	result = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while(get_index(str[i], base) != -1)
	{
		result = result * base + get_index(str[i],base);
		if (result < 0)
			return ((sign != -1) * -1);
		i++;
	}
	return (result * sign);
}
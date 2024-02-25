/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:06:16 by msaadidi          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:37 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*a;

	if (num_elements != 0 && SIZE_MAX / num_elements < element_size)
		return (NULL);
	a = malloc(num_elements * element_size);
	if (!a)
		return (NULL);
	if (num_elements == 0 || element_size == 0)
	{
		ft_memset(a, 0, 1);
		return (a);
	}
	ft_memset(a, 0, element_size * num_elements);
	return (a);
}

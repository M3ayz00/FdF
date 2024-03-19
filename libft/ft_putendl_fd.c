/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:32:32 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/19 00:27:58 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (EXIT_FAILURE);
	return (ft_putstr_fd(s, fd), ft_putstr_fd("\n", fd));
}

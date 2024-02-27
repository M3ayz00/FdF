/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:49:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/02/27 17:37:05 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
char	*read_file(int fd, char *container);
char	*gget_line(char *container);
char	*update_container(char *container);

#endif
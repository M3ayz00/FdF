/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:49:06 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/20 21:27:39 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new_str;
	size_t	str_len;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy((new_str + ft_strlen(s1)), s2, ft_strlen(s2));
	free(s1);
	return (new_str);
}

char	*update_container(char *container)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i])
	{
		free(container);
		return (NULL);
	}
	updated = (char *)ft_calloc(ft_strlen(container) - i + 1, sizeof(char));
	if (!updated)
	{
		free(container);
		return (NULL);
	}
	i++;
	while (container[i])
		updated[j++] = container[i++];
	free(container);
	return (updated);
}

char	*gget_line(char *container)
{
	char	*line;
	int		i;
	int		end;

	i = 0;
	if (!container[i])
		return (NULL);
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		end = 2;
	else
		end = 1;
	line = (char *)ft_calloc(i + end, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, container, i);
	if (*(container + i) == '\n')
		*(line + i) = '\n';
	return (line);
}

char	*read_file(int fd, char *container)
{
	char	*buffer;
	int		readed;

	if (!container)
		container = ft_calloc(1, 1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(container, '\n') && readed >= 1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(container);
			return (NULL);
		}
		buffer[readed] = 0;
		container = ft_strjoin2(container, buffer);
	}
	free(buffer);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = read_file(fd, container);
	if (!container)
		return (NULL);
	line = gget_line(container);
	container = update_container(container);
	return (line);
}

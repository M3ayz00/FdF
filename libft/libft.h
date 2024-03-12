/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:16 by msaadidi          #+#    #+#             */
/*   Updated: 2024/03/12 17:56:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
// # include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
# include "../FdF.h"

int     is_space(char c);
double     ft_min(double n1, double n2);
double rad(double deg);
int		ft_atoi( char *str);
int     ft_atoi_base(char *str, int base);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp( void *str1,  void *str2, size_t n);
int		ft_strncmp( char *s1,  char *s2, size_t n);
size_t	ft_strlen(char *str);
size_t	ft_strs_len(char **strs);
size_t	ft_arr_strs_len(char ***arr_strs);
size_t	ft_strlcpy(char *dest,  char *src, size_t size);
size_t	ft_strlcat(char *dest,  char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest,  void *src, size_t n);
void	*ft_memmove(void *dest,  void *src, size_t n);
void	*ft_memchr( void *s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr( char *str, int c);
char	*ft_strnstr( char *haystack,  char *needle, size_t n);
char	*ft_strdup( char *str);
char	*ft_substr(char  *s, unsigned int start, size_t len);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strtrim(char  *s1, char  *set);
char	**ft_split(char  *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char  *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
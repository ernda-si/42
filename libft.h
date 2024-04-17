/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:35:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/17 18:49:10 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_isalnum(char av);
int		ft_isdigit(char av);
int		ft_isprint(char av);
int		ft_atoi(char *str)	;
int		ft_isascii(int av);
int		ft_isalpha(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strnstr(char *str1, char *str2, int len);
char	*ft_strrchr(char *str, int c);
char	*ft_strchr(char *str, int c);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memset(void *ptr, int x, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
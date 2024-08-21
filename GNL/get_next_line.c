/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:03:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/21 16:03:28 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	hasnl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer[i])
		return(0);
	while (buffer[i] != '\n')
	{
		i++;
		if (buffer[i] == '\n')
			return(1);
	}
	return(0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = 0;
	printf("len1: %d\n",len1);
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (s3 == 0)
		return (NULL);
	while (++i < len1)	
		s3[i] = s1[i];
	while (j < len2)
		s3[i++] = s2[j++];
	s3[i + 1] = '\0';
	return (s3);
}

char	*cut_buff(char *buffer)
{
	char	*storage;
	int		i;
	int		len;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (!buffer[i])
			break;
		i++;
	}
	len = ft_strlen(buffer + i);
	storage = (char *) malloc(sizeof(char) * len + 1);
	while (len-- && i++)
		storage[i] = buffer[i];
	storage[i] = '\0';
	return(buffer);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0 || !buffer[0])
	{
		line = ft_strjoin(line, buffer);
		printf("buffer: %s\n", buffer);
		printf("line: %s\n", line);
		if (!line)
			return(NULL);
		while (line && line[i] && hasnl(buffer))
		{
			printf("buffer after nl check: %s\n", buffer);
			if (line[i] == '\n')
				break;
			i++;
		}
	}
	cut_buff(buffer);
	printf("newbuff: %s\n", buffer);
	return(line);
}

int	main(void)
{
	int	fd;
	// int	i;
	// i = 0;
	fd = open("test.txt", O_RDONLY);
	// while (i++ < 3)
	printf("GNL: %s\n", get_next_line(fd));
	close(fd);
}
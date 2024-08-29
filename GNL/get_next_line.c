/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:03:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/29 15:21:36 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read)
	{
		if (buffer[0] == 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
		if (cut_buff(buffer))
			break ;
	}
	return (line);
}

/* int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	i = 1;
	fd = open("test.txt", O_RDONLY);

	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)))
	{
		printf("GNL[%d]: %s", i++, line);
		free(line);
	}
	printf("\n");
	close(fd);
} */
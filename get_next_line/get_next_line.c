/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:40:00 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/12/03 14:38:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_clean_line(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (ft_substr(buffer, 0, i + 1));
}

char	*get_clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_strdup(buffer + i));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	char		*clean_line;
	ssize_t		end;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	end = 1;
	while (end > 0 && !ft_strchr(line, '\n'))
	{
		end = read(fd, line, BUFFER_SIZE);
		line[end] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	clean_line = get_clean_line(buffer);
	buffer = get_clean_buffer(buffer);
	return (clean_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY | O_CREAT);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	printf("%s", line);
}

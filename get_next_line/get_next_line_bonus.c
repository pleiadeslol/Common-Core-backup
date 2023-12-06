/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:00 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/12/06 16:36:52 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_clean_line(char *buffer)
{
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (ft_substr(buffer, 0, i + 1));
}

static char	*get_clean_buffer(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!*buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = ft_strdup(buffer + i);
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[BUFFER_SIZE];
	char		*clean_line;
	ssize_t		end;

	end = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	while (end > 0 && !ft_strchr(line, '\n'))
	{
		end = read(fd, line, BUFFER_SIZE);
		if (end < 0)
			return (free(line), free(buffer[fd]), NULL);
		line[end] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], line);
	}
	clean_line = get_clean_line(buffer[fd]);
	buffer[fd] = get_clean_buffer(buffer[fd]);
	free(line);
	return (clean_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:40:00 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/12/01 14:31:21 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	ssize_t		end;

	line = (char *)malloc(BUFFER_SIZE + 1);
	end = 1;
	while (end > 0 && !ft_strchr(line, '\n'))
	{
		end = read(fd, line, BUFFER_SIZE);
		line[end] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY | O_CREAT);
	line = get_next_line(fd);
	printf("->> %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("->> %s\n", line);
	free(line);
}

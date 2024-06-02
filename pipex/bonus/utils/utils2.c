/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:17:46 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 18:19:25 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../get_next_line/get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)src);
	if (n == 0)
		return (len);
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && s2 != 0)
	{
		i = 0;
		j = ft_strlen((char *)s1);
		while (s1[i] && ft_strchr(s2, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(s2, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	free((void *)s1);
	return (str);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exec_child(t_args *args, int **pipe_fd, int i, char **envp)
{
	if (i == 0 && args->fd1 != -1)
		first_cmd(args->fd1, pipe_fd[i][1]);
	else if (i == args->count - 1)
		last_cmd(args->fd2, pipe_fd[i - 1][0]);
	else
		middle_cmd(pipe_fd[i - 1][0], pipe_fd[i][1]);
	close_pipe(args, pipe_fd);
	close(args->fd1);
	close(args->fd2);
	if (execve(args->path[i], args->cmd[i], envp) < 0)
	{
		free_pipex(args);
		exit(1);
	}
}

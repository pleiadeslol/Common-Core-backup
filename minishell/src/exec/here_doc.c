/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:44:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/30 05:27:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	heredoc_sig(void)
{
	reset_signals();
	signal(SIGQUIT, SIG_IGN);
}

int	here_doc(t_redir *redir, char **env)
{
	char	*line;
	int		pipe_fd[2];

	heredoc_sig();
	if (pipe(pipe_fd) < 0)
		return (-1);
	while (1)
	{
		write (1, "> ", 2);
		line = get_next_line(0);
		if ((line && ft_strncmp(line, "\0", 2) == 0))
		{
			write(1, "\n", 1);
			break ;
		}
		if (line)
			line[ft_strlen(line) - 1] = '\0';
		if (!line || ft_strcmp(line, redir->heredoc) == 0)
			break ;
		if (redir->expansion == 1)
			expand_2(&line, env);
		(write(pipe_fd[1], line, ft_strlen(line)), write(pipe_fd[1], "\n", 1));
		free(line);
	}
	return (free(line), close(pipe_fd[1]), pipe_fd[0]);
}

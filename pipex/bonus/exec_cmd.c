/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:22:43 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/09 21:09:29 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_args *args, char **envp)
{
	int		pipe_fd[args->count - 1][2];
	int		i;
	int		j;
	pid_t	id;

	// i = 0;
	// pipe_fd = malloc(sizeof(int *) * (args->count - 1));
	// while (i < args->count)
	// {
	// 	pipe_fd[i] = malloc(sizeof(int) * 2);
	// 	i++;
	// }
	i = 0;
	while (i < args->count)
	{
		j = 0;
		if (i < args->count - 1)
		{
			if (pipe(pipe_fd[i]) == -1)
				exit(1);
		}
		id = fork();
		if (id == 0)
		{
			if (i == 0)
			{
				dup2(args->fd1, STDIN_FILENO);
				close(args->fd1);
				dup2(pipe_fd[i][1], STDOUT_FILENO);
			}
			else if (i == args->count - 1)
			{
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				dup2(args->fd2, STDOUT_FILENO);
				close(args->fd2);
			}
			else
			{
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				dup2(pipe_fd[i][1], STDOUT_FILENO);
			}
			while (j < args->count - 1)
			{
				close(pipe_fd[j][0]);
				close(pipe_fd[j][1]);
				j++;
			}
			close(args->fd1);
			close(args->fd2);
			if (execve(args->path[i], args->cmd[i], envp) < 0)
				exit(1);
		}
		i++;
	}
	i = 0;
	while (i < args->count - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
	close(args->fd1);
	close(args->fd2);
	while (wait(NULL) > 0)
		;
}

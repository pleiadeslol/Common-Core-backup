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
	int	pipe_fd[2];
	pid_t	id;
	int		prev_id;
	int i;

	i = 0;
	prev_id = -1;
	while (i < args->count)
	{
		if ( i < args->count - 1)
		{
			if (pipe(pipe_fd) == -1)
				exit (1);
		}
		id = fork();
		if (id == 0)
		{
			if (i == 0)
			{
				dup2(args->fd1, STDIN_FILENO);
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(args->fd1);
			}
			else if (i == args->count - 1)
			{
				dup2(prev_id, STDIN_FILENO);
				dup2(args->fd2, STDOUT_FILENO);
				close(args->fd2);
			}
			else
			{
				dup2(prev_id, STDIN_FILENO);
				dup2(pipe_fd[1], STDOUT_FILENO);
			}
			if (prev_id != -1)
				close(prev_id);
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			execve(args->path[i], args->cmd[i], envp);
		}
		else
		{
			if (prev_id != -1)
				close(prev_id);
			if (i < args->count - 1)
				close(pipe_fd[1]);
			prev_id = pipe_fd[0];
		}
		i++;
	}
	close(args->fd1);
	close(args->fd2);
	while (wait(NULL) > 0)
		;
}

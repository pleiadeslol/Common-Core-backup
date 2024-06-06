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
#include "ft_eprintf/ft_eprintf.h"

static void	exec_child1(t_args *args, int pipe_fd[2], char **envp)
{
	if (args->fd1 != -1)
	{
		dup2(args->fd1, 0);
		close(pipe_fd[0]);
		close(args->fd1);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (execve(args->path1, args->cmd1, envp) < 0)
		{
			free_pipex(args);
			exit(1);
		}
	}
}

static void	exec_child2(t_args *args, int pipe_fd[2], char **envp)
{
	dup2(args->fd2, 1);
	close(pipe_fd[1]);
	close(args->fd2);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	if (execve(args->path2, args->cmd2, envp) < 0)
	{
		free_pipex(args);
		exit(1);
	}
}

void	exec_cmd(t_args *args, char **envp)
{
	pid_t	id1;
	pid_t	id2;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		free_pipex(args);
		exit(1);
	}
	id1 = fork();
	if (id1 == 0)
		exec_child1(args, pipe_fd, envp);
	else
	{
		id2 = fork();
		if (id2 == 0)
			exec_child2(args, pipe_fd, envp);
	}
	close(args->fd1);
	close(args->fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (wait(NULL) > 0)
		;
}

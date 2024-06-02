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

void	first_cmd(int fd1, int pipe)
{
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	dup2(pipe, STDOUT_FILENO);
}

void	last_cmd(int fd2, int pipe)
{
	dup2(pipe, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
}

void	middle_cmd(int pipe1, int pipe2)
{
	dup2(pipe1, STDIN_FILENO);
	dup2(pipe2, STDOUT_FILENO);
}

void	close_pipe(t_args *args, int **pipe_fd)
{
	int	i;

	i = 0;
	while (i < args->count - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}

void	exec_cmd(t_args *args, char **envp)
{
	int		**pipe_fd;
	int		i;
	pid_t	id;

	pipe_fd = malloc(sizeof(int *) * (args->count - 1));
	create_pipe(args, pipe_fd);
	i = 0;
	while (i < args->count)
	{
		id = fork();
		if (id == 0)
			exec_child(args, pipe_fd, i, envp);
		i++;
	}
	close_pipe(args, pipe_fd);
	close(args->fd1);
	close(args->fd2);
	while (wait(NULL) > 0)
		;
}

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

void	exec_cmd(t_args *args)
{
	pid_t	id;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(1);
	id = fork();
	if (id == 0)
	{
		dup2(args->fd1, 0);
		close(pipe_fd[0]);
		close(args->fd1);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execv(args->path1, args->cmd1);
	}
	else
	{
		dup2(args->fd2, 1);
		close(pipe_fd[1]);
		close(args->fd2);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		execv(args->path2, args->cmd2);
	}
}

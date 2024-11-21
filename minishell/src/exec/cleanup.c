/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:39 by root              #+#    #+#             */
/*   Updated: 2024/11/20 20:39:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	cleanup_exec_data(t_data *data, int status_code)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->count)
	{
		if (i < data->count - 1)
			if (data->pipe_fd && data->pipe_fd[i])
				free(data->pipe_fd[i]);
		if (data->path[i])
			free(data->path[i]);
		if (data->cmds && data->cmds[i])
		{
			j = 0;
			while (data->cmds[i][j])
				free(data->cmds[i][j++]);
			free(data->cmds[i]);
		}
		i++;
	}
	(free(data->cmds), free(data->path));
	(free(data->pipe_fd), free(data->pid), free(data));
	set_status(status_code);
	return (status_code);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count - 1)
	{
		if (data->pipe_fd[i])
		{
			close(data->pipe_fd[i][0]);
			close(data->pipe_fd[i][1]);
		}
		i++;
	}
}

void	cleanup_exec(t_data *data)
{
	int	i;
	int	status;

	status = 0;
	close_pipes(data);
	g_global->running = 1;
	i = 0;
	while (i < data->count)
	{
		if (data->pid[i] > 0)
			waitpid(data->pid[i], &status, 0);
		i++;
	}
	cleanup_exec_data(data, WEXITSTATUS(status));
	g_global->running = 0;
}

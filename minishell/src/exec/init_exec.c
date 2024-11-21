/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:53 by root              #+#    #+#             */
/*   Updated: 2024/11/20 20:26:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_data	*init_execdata(t_cmd *cmd)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	data->count = ft_lstsize(cmd);
	data->cmds = malloc(sizeof(char **) * (data->count + 1));
	data->path = malloc(sizeof(char *) * (data->count + 1));
	data->pid = malloc(sizeof(int) * (data->count + 1));
	ft_bzero(data->pid, sizeof(int) * (data->count + 1));
	data->pipe_fd = malloc(sizeof(int *) * (data->count - 1));
	if (!data->cmds || !data->path || !data->pid || !data->pipe_fd)
	{
		(free(data->cmds), free(data->pid));
		(free(data->path), free(data->pipe_fd));
		return (NULL);
	}
	i = 0;
	while (i < data->count + 1)
	{
		data->path[i] = NULL;
		data->cmds[i] = NULL;
		data->pid[i] = 0;
		i++;
	}
	return (data);
}

int	init_pipes(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->count - 1)
	{
		(*data)->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (pipe((*data)->pipe_fd[i]) == -1 || !(*data)->pipe_fd[i])
		{
			while (--i >= 0)
				free((*data)->pipe_fd[i]);
			free((*data)->pipe_fd);
			free((*data)->cmds);
			free((*data)->pid);
			free((*data)->path);
			return (1);
		}
		i++;
	}
	return (0);
}

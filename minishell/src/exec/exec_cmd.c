/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:37 by root              #+#    #+#             */
/*   Updated: 2024/11/29 05:19:47 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*get_pid(void)
{
	int		fd;
	long	len;
	ssize_t	end;
	char	pid[42];
	char	*str;

	fd = open("/proc/self/stat", O_RDONLY);
	end = read(fd, pid, sizeof(pid) - 1);
	if (end < 0)
		return (NULL);
	str = ft_strchr(pid, ' ');
	len = str - pid + 1;
	str = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(str, pid, len);
	close (fd);
	return (str);
}

void	redirect_pipe(int i, t_data *data)
{
	if (i == 0)
		dup2(data->pipe_fd[i][1], STDOUT_FILENO);
	else if (i == data->count - 1)
		dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(data->pipe_fd[i][1], STDOUT_FILENO);
	}
}

int	error_managment(t_data *data, int i)
{
	if (ft_strchr(data->path[i], '/'))
		printf("minishell: %s: Is a directory\n", data->path[i]);
	else if (!ft_strcmp(data->path[i], "."))
	{
		printf("minishell: .: filename argument required\n");
		return (2);
	}
	else if (ft_strchr(data->path[i], '.')
		&& (data->path[i][1] == '.' || data->path[i][0] == '.'))
		printf("minishell: %s: command not found\n", data->path[i]);
	else
		perror("minishell");
	return (127);
}

void	exec_simplecmd(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i)
{
	reset_signals();
	if (data->count > 1)
		redirect_pipe(i, data);
	close_pipes(data);
	update_env(pEnv, "_", data->path[i]);
	if (cmd->redir->type)
		redirect_fd(cmd);
	if (cmd->cmd && ft_strcmp(cmd->cmd, "") != 0)
	{
		if (execve(data->path[i], data->cmds[i], (*pEnv)->envp) < 0)
		{
			cleanup_exec_data(data, error_managment(data, i));
			exit (ft_atoi(g_global->status));
		}
	}
	else
		exit (0);
}

void	exec_pipe(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i)
{
	if (cmd->redir->type)
		if (handle_redirections(&cmd, (*pEnv)->envp) == -1)
			return ;
	if (cmd->cmd && (ft_strcmp(cmd->cmd, "bash") == 0
			|| ft_strcmp(cmd->cmd, "./minishell")))
		update_shlvl(pEnv);
	if (!g_global->here_doc)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			if (cmd->isbuiltin == 1)
				exec_pipebuiltin(cmd, data, pEnv, i);
			else
				exec_simplecmd(cmd, data, pEnv, i);
		}
	}
}

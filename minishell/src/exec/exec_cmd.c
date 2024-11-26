/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:37 by root              #+#    #+#             */
/*   Updated: 2024/11/21 18:47:17 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
			free(data->path);
			exit (1);
		}
	}
	else
		exit (0);
}

void	exec_pipe(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i)
{
	if (cmd->redir->type)
		if (handle_redirections(&cmd, (*pEnv)->envp) == 1)
			return ;
	if (cmd->cmd && (ft_strcmp(cmd->cmd, "bash") == 0
			|| ft_strcmp(cmd->cmd, "./minishell")))
		update_shlvl(pEnv);
	if (cmd->isbuiltin == 1 && data->count != 1)
		exec_pipebuiltin(cmd, data, pEnv, i);
	else
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			exec_simplecmd(cmd, data, pEnv, i);
	}
}

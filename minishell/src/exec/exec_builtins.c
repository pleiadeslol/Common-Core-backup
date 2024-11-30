/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:41 by root              #+#    #+#             */
/*   Updated: 2024/11/30 02:39:45 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	exec_simplebuiltin(t_cmd *cmd, t_pathAndEnv **pEnv, t_data *data)
{
	int	stdin_copy;
	int	stdout_copy;
	int	status;

	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	if (cmd->redir->type)
		if (handle_redirections(&cmd, (*pEnv)->envp) == -1)
			return ;
	update_env(pEnv, "_", "/usr/bin/env");
	if (cmd->redir->type && ft_strcmp(cmd->cmd, "exit"))
		redirect_fd(cmd);
	exec_builtins(cmd, *pEnv, 0);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	status = ft_atoi(g_global->status);
	cleanup_exec_data(data, status);
}

void	exec_pipebuiltin(t_cmd *cmd, t_data *data,
			t_pathAndEnv **pEnv, int i)
{
	reset_signals();
	redirect_pipe(i, data);
	close_pipes(data);
	update_env(pEnv, "_", "/usr/bin/env");
	if (cmd->redir->type && ft_strcmp(cmd->cmd, "exit"))
		redirect_fd(cmd);
	exec_builtins(cmd, *pEnv, 1);
	exit(ft_atoi(g_global->status));
}

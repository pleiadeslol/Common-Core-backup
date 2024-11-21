/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:11:41 by root              #+#    #+#             */
/*   Updated: 2024/11/21 15:08:16 by root             ###   ########.fr       */
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
		if (handle_redirections(&cmd, (*pEnv)->envp) == 1)
			return ;
	update_env(pEnv, "_", "/usr/bin/env");
	if (cmd->redir->type)
		redirect_fd(cmd);
	exec_builtins(cmd, *pEnv);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	status = ft_atoi(g_global->status);
	cleanup_exec_data(data, status);
}

void	exec_pipebuiltin(t_cmd *cmd, t_data *data,
			t_pathAndEnv **pEnv, int i)
{
	int	stdin_copy;
	int	stdout_copy;

	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	if (data->count != 1)
		redirect_pipe(i, data);
	update_env(pEnv, "_", "/usr/bin/env");
	if (cmd->redir->type)
		redirect_fd(cmd);
	exec_builtins(cmd, *pEnv);
	dup2(stdin_copy, STDIN_FILENO);
	dup2(stdout_copy, STDOUT_FILENO);
	close(stdin_copy);
	close(stdout_copy);
}

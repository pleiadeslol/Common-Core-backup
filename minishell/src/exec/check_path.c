/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:17:04 by root              #+#    #+#             */
/*   Updated: 2024/12/01 22:32:32 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_execpath(t_cmd *cmd, t_data **data, t_pathAndEnv *pEnv)
{
	int	i;
	int	status;

	i = 0;
	cmd->wrong_cmd = false;
	while (cmd && cmd->next)
	{
		if (!cmd->isbuiltin && (cmd->cmd && ft_strcmp(cmd->cmd, "") != 0))
		{
			if (check_path(cmd->cmd, &(*data)->path[i], pEnv) != 0)
				cmd->wrong_cmd = true;
			(*data)->cmds[i] = get_cmd(cmd);
		}
		cmd = cmd->next;
		i++;
	}
	if (cmd && cmd->cmd && ft_strcmp(cmd->cmd, "") != 0 && !cmd->isbuiltin)
	{
		status = check_path(cmd->cmd, &(*data)->path[(*data)->count - 1], pEnv);
		if (status == 126 || status == 127)
			return (cleanup_exec_data(*data, status));
		(*data)->cmds[(*data)->count - 1] = get_cmd(cmd);
	}
	return (0);
}

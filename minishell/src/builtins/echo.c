/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:44:03 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/14 00:55:34 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_ech_n(t_cmd *cmd)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(cmd->args, ' ');
	while (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
		i++;
	while (args[i])
	{
		write (STDOUT_FILENO, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write (STDOUT_FILENO, " ", 1);
		i++;
	}
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_echo(t_cmd *cmd)
{
	if (cmd->args == NULL)
		write (STDOUT_FILENO, "\n", 1);
	else if (ft_strncmp(cmd->args, "-n", 2) == 0)
		ft_ech_n(cmd);
	else if (ft_strncmp(cmd->args, "$?", 2) == 0)
	{
		write (STDERR_FILENO, g_global->status, ft_strlen(g_global->status));
		write (STDOUT_FILENO, "\n", 1);
	}
	else
	{
		write (STDOUT_FILENO, cmd->args, ft_strlen(cmd->args));
		write (STDOUT_FILENO, "\n", 1);
	}
	set_status(0);
}

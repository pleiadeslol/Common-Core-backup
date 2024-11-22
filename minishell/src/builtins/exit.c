/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:11:25 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/09 17:34:29 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_exit(t_cmd *cmd)
{
	int	num;

	if (!cmd->args && g_global->status)
	{
		printf("exit\n");
		exit (ft_atoi(g_global->status));
	}
	else if (ft_isdigit(cmd->args[0]))
	{
		num = ft_atoi(cmd->args);
		if (num <= 0 || num >= 255)
			num = 0;
		printf("exit\n");
		exit (num);
	}
	else
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", cmd->args);
		exit (2);
	}
}

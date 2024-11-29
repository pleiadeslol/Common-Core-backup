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

void	ft_exit(t_cmd *cmd, int flag)
{
	if (!cmd->args_node && g_global->status)
		handle_exit_with_status(flag);
	else if ((cmd->args_node->word[0] == '+'
			|| cmd->args_node->word[0] == '-'
			|| ft_isdigit(cmd->args_node->word[0])))
		handle_single_numeric_arg(cmd, flag);
	else
	{
		print_exit_error(cmd->args_node->word, flag);
		exit(2);
	}
}

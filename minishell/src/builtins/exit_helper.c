/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:38:31 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/29 00:43:55 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_valid_numeric_arg(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_exit_error(char *str, int flag)
{
	if (flag == 0)
		printf("exit\n");
	printf("minishell: exit: %s: numeric argument required\n", str);
}

int	normalize_exit_code(int num)
{
	if (num < 0)
		return ((256 + num) % 256);
	else if (num > 255)
		return (num % 256);
	return (num);
}

void	handle_exit_with_status(int flag)
{
	if (flag == 0)
		printf("exit\n");
	exit(ft_atoi(g_global->status));
}

void	handle_single_numeric_arg(t_cmd *cmd, int flag)
{
	int	num;

	if (!is_valid_numeric_arg(cmd->args_node->word))
	{
		print_exit_error(cmd->args_node->word, flag);
		exit(2);
	}
	if (cmd->args_node->next)
	{
		if (flag == 0)
			printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		set_status(1);
		return ;
	}
	num = normalize_exit_code(ft_atoi(cmd->args_node->word));
	if (flag == 0)
		printf("exit\n");
	exit(num);
}

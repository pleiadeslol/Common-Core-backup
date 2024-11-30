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

bool	check_n_arg(char *str);

void	ft_ech_n(t_cmd *cmd)
{
	t_args	*args;

	args = cmd->args_node;
	while (args && ft_strncmp(args->word, "-n", 2) == 0
		&& check_n_arg(args->word))
		args = args->next;
	while (args)
	{
		write (STDOUT_FILENO, args->word, ft_strlen(args->word));
		if (args->next)
			write (STDOUT_FILENO, " ", 1);
		args = args->next;
	}
}

bool	check_n_arg(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

static void	print_arg(char *str, int is_last)
{
	if (ft_strncmp(str, "$?", 2) == 0)
		write(STDERR_FILENO, g_global->status, ft_strlen(g_global->status));
	else if (ft_strncmp(str, "$$", 2) == 0)
		write(STDERR_FILENO, g_global->pid, ft_strlen(g_global->pid));
	else
		write(STDOUT_FILENO, str, ft_strlen(str));
	if (!is_last)
		write(STDOUT_FILENO, " ", 1);
}

static void	ft_ech_normal(t_cmd *cmd)
{
	t_args	*tmp;

	while (cmd->args_node)
	{
		if (!cmd->args_node->word)
		{
			tmp = cmd->args_node;
			cmd->args_node = cmd->args_node->next;
			free(tmp->word);
			free(tmp);
		}
		else
		{
			print_arg(cmd->args_node->word, cmd->args_node->next == NULL);
			tmp = cmd->args_node;
			cmd->args_node = cmd->args_node->next;
			free(tmp->word);
			free(tmp);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_echo(t_cmd *cmd)
{
	if (cmd->args_node == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (cmd->args_node->word
		&& ft_strncmp(cmd->args_node->word, "-n", 2) == 0
		&& check_n_arg(cmd->args_node->word))
		ft_ech_n(cmd);
	else
		ft_ech_normal(cmd);
	set_status(0);
}

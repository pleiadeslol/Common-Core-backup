/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:54:01 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/17 05:54:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl_fd("", 1);
		rl_replace_line("", 0);
		if (!g_global->running)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
	set_status(sig + 128);
}

void	handle_signals(void)
{
	struct sigaction	act_int;

	ft_bzero(&act_int, sizeof(act_int));
	act_int.sa_handler = handle_sigint;
	sigaction(SIGINT, &act_int, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_signals(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	handle_exit(char **line, t_pathAndEnv	**p_env)
{
	int	status;

	if (!*line)
	{
		printf("exit\n");
		if (g_global->status)
		{
			status = ft_atoi(g_global->status);
			free(g_global->status);
		}
		else
			status = 0;
		ft_clear_path_env(p_env);
		exit (status);
	}
}

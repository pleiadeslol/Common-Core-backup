/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:24:40 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/30 05:24:56 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT && g_global->running == 1)
	{
		printf("Quit (core dumped)\n");
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	set_status(sig + 128);
}

void	handle_sig_quit(void)
{
	struct sigaction	act_quit;

	ft_bzero(&act_quit, sizeof(act_quit));
	act_quit.sa_handler = handle_sigquit;
	sigaction(SIGQUIT, &act_quit, NULL);
}

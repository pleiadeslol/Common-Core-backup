/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:53:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/09 17:56:08 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	if (ac == 6 && ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		args = here_args(av, envp);
		here_check(args, envp);
		here_doc(args);
	}
	else
	{
		args = set_args(ac, av, envp);
		check_args(args, envp);
	}
	exec_cmd(args, envp);
	free_pipex(args);
}

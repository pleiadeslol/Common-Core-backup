/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:53:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 01:47:29 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	int i = 0;
	char *home;
	char *p;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", 4) == 0)
		{
			p = ft_strchr(envp[i], '=');
			if (p)
				p++;
			break;
		}
		i++;
	}
	args = set_args(ac, av, p);
	check_args(args);
	exec_cmd(args);
}

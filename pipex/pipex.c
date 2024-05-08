/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:53:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/08 21:04:17 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	args = set_args(ac, av, envp);
	check_args(args, envp);
	exec_cmd(args);
}

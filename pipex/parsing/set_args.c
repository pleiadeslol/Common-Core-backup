/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:24:15 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 01:47:12 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_args	*set_args(int ac, char **av, char *p)
{
	t_args	*args;

	if (ac != 5)
	{
		write (2, "Error\n 4 arguments needed\n", 27);
		exit(1);
	}
	else
	{
		args = malloc(sizeof(t_args));
		args->file1 = av[1];
		args->cmd1 = ft_split(av[2], ' ');
		args->cmd2 = ft_split(av[3], ' ');
		args->file2 = av[4];
	}
	int i = 0;
	while (args->cmd1[i])
	{
		if (ft_strncmp(args->cmd1[i], "~", 1) == 0)
			args->cmd1[i] = p;
		i++;
	}
	i = 0;
	while (args->cmd2[i])
	{
		if (ft_strncmp(args->cmd2[i], "~", 1) == 0)
			args->cmd2[i] = p;
		i++;
	}
	return (args);
}

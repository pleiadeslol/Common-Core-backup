/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:56:40 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/21 23:56:40 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_args	*set_args(int ac, char **av)
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
		args->cmd1 = av[2];
		args->cmd2 = av[3];
		args->file2 = av[4];
	}
	return (args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:24:15 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 18:13:16 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_args(t_args *args, int ac, char **av)
{
	int	i;

	i = 0;
	args->count = ac - 3;
	args->cmd = malloc(sizeof(char **) * (args->count + 1));
	args->path = malloc(sizeof(char *) * (args->count + 1));
	args->file1 = av[1];
	while (i < args->count)
	{
		args->cmd[i] = ft_split(av[i + 2], ' ');
		i++;
	}
	args->cmd[args->count] = NULL;
	args->file2 = av[ac - 1];
}

t_args	*set_args(int ac, char **av, char **envp)
{
	t_args	*args;
	int		count;
	int		i;

	i = 0;
	if (ac < 5)
	{
		write (2, "Error\nMore than 4 arguments needed\n", 35);
		exit(1);
	}
	else
	{
		args = malloc(sizeof(t_args));
		parse_args(args, ac, av);
	}
	count = ac - 3;
	while (count)
	{
		replace_home(args->cmd[i], envp);
		i++;
		count--;
	}
	return (args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:11:09 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/07 01:45:14 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_args	*set_args(int ac, char **av)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (ac == 5 || ac == 6)
	{
		args->n_philo = ft_atoi(av[1]);
		args->time_to_die = ft_atoi(av[2]);
		args->time_to_eat = ft_atoi(av[3]);
		args->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			args->nb_philo_eat = ft_atoi(av[5]);
	}
	else
	{
		printf("more arguments needed\n");
		exit (1);
	}
	if (args->n_philo < 1)
	{
		printf("number of philosophers need to be more than 1\n");
		exit (1);
	}
	return(args);
}


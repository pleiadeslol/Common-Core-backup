/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:56:57 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/21 21:32:54 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_args	*parse_data(int ac, char **av)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->t_start = get_tstart();
	args->n_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nb_philo_eat = ft_atoi(av[5]);
	if (args->n_philo < 1 || args->n_philo > 200)
	{
		printf("Error: number of philosophers needs to be between 1 and 200\n");
		exit(EXIT_FAILURE);
	}
	else if (args->time_to_die < 60 || args->time_to_eat < 60 ||
			args->time_to_sleep < 60)
	{
		printf("Error: time needs to be more than 60 ms\n");
		exit(EXIT_FAILURE);
	}
	return (args);
}


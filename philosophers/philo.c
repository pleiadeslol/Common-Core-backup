/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/24 17:38:12 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	int		status;

	status = check_args(ac, av);
	if (status == 0)
		return (EXIT_FAILURE);
	args = init_args(ac, av);
	if (!args)
		return (EXIT_FAILURE);
	status = create_forks(args);
	if (status == 0)
		return (EXIT_FAILURE);
	status = init_philo(args);
	if (!status)
		return (EXIT_FAILURE);
	status = run_philo(args);
	if (!status)
		return (EXIT_FAILURE);
	clean_main(args);
}

void	clean_main(t_args *args)
{
	int	i;

	i = 0;
	if (args)
	{
		pthread_mutex_destroy(&args->state[DEATH]);
		pthread_mutex_destroy(&args->state[EAT]);
		pthread_mutex_destroy(&args->state[PRINT]);
		while (i < args->n_philo)
		{
			pthread_mutex_destroy(&args->forks[i]);
			i++;
		}
		free(args->forks);
		free(args->philo);
		free(args);
	}
}

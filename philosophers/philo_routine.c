/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:42:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/08/31 01:28:08 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_args	*args;
	int		i;

	args = (t_args *)data;
	i = 0;
	while (i < args->n_philo)
	{
		if (i%2 == 0)
		{
			pthread_mutex_lock(&args->forks[i]);
			printf("Philo %d has taken a fork\n", i);
			pthread_mutex_lock(&args->forks[(i + 1) % args->n_philo]);
			printf("Philo %d has taken a fork\n", i);
			printf("Philo %d is eating\n", i);
			usleep(args->time_to_eat * 1000);
			pthread_mutex_unlock(&args->forks[i]);
			pthread_mutex_unlock(&args->forks[(i + 1) % args->n_philo]);
			printf("Philo %d is sleeping\n", i);
			usleep(args->time_to_sleep * 1000);
			printf("Philo %d is thinking\n", i);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:42:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/25 20:48:17 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	routine_end(t_args *args)
{
	bool	end;

	pthread_mutex_lock(&args->state[DEATH]);
	end = args->end;
	pthread_mutex_unlock(&args->state[DEATH]);
	return (end);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(10, philo->args);
	while (!routine_end(philo->args))
	{
		take_fork(philo);
		eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

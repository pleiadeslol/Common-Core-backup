/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:42:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/22 02:53:55 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	stop_run(t_args *args)
{
	bool	ended;

	ended = args->end;
	return (ended);
}

void	*philo_routine(void *data)
{
	t_args	*args;
	t_philo	*philo;
	int		i;

	args = (t_args *)data;
	i = 0;
	philo = args->philo;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while(1)
	{
		take_fork(philo);
		eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%llu %d has taken a fork\n", get_tstart() - philo->args->t_start, philo->id);
	pthread_mutex_lock(philo->l_fork);
	printf("%llu %d has taken a fork\n", get_tstart() - philo->args->t_start, philo->id);
}

void	eat(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	printf("%llu %d is eating\n", get_tstart() - philo->args->t_start, philo->id);
	philo->last_meal = get_tstart();
	philo->meals_eaten++;
	ft_usleep(args->time_to_eat);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	printf("%llu %d is sleeping\n", get_tstart() - philo->args->t_start, philo->id);
	ft_usleep(args->time_to_sleep);
}

void	think(t_philo *philo)
{
	printf("%llu %d is thinking\n", get_tstart() - philo->args->t_start, philo->id);
}

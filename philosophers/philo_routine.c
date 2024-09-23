/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:42:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:35:47 by rzarhoun         ###   ########.fr       */
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
		ft_usleep(1, philo->args);
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

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state(philo->args, philo->id, "has taken a fork");
	if (philo->args->n_philo == 1)
	{
		ft_usleep(philo->args->time_to_die + 1, philo->args);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_state(philo->args, philo->id, "has taken a fork");
}

void	eat(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	print_state(args, philo->id, "is eating");
	pthread_mutex_lock(&args->state[EAT]);
	philo->last_meal = get_time(args);
	philo->meals_eaten++;
	pthread_mutex_unlock(&args->state[EAT]);
	ft_usleep(args->time_to_eat, args);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	print_state(args, philo->id, "is sleeping");
	ft_usleep(args->time_to_sleep, args);
}

void	think(t_philo *philo)
{
	print_state(philo->args, philo->id, "is thinking");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:35:35 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/08/31 01:22:23 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_args *args)
{
	t_philo	**philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo *));
	if (!philo)
		return (NULL);
	while (i < args->n_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return (NULL);
		philo[i]->id = i;
		philo[i]->fork = malloc(sizeof(pthread_mutex_t) * args->n_philo);
		if (!philo[i]->fork)
			return (NULL);
		philo[i]->fork[i] = args->forks[i];
		i++;
	}
	return (philo);
}

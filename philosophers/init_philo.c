/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:35:35 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 02:46:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_args *args)
{
	int		i;

	i = 0;
	args->philo = malloc(args->n_philo * sizeof(t_philo));
	if (!args->philo)
		return (0);
	while (i < args->n_philo)
	{
		args->philo[i].id = i;
		args->philo[i].meals_eaten = 0;
		args->philo[i].args = args;
		args->philo[i].last_meal = args->t_start;
		args->philo[i].l_fork = &args->forks[i];
		if (i == 0)
			args->philo[i].r_fork = &args->forks[args->n_philo - 1];
		else
			args->philo[i].r_fork = &args->forks[i - 1];
		i++;
	}
	return (1);
}

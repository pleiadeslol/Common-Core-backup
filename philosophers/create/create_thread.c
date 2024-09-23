/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:55:41 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:48:41 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	run_philo(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_create(&args->philo[i].thread, NULL,
				philo_routine, &args->philo[i]))
			return (0);
		i++;
	}
	monitor(args);
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(args->philo[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}

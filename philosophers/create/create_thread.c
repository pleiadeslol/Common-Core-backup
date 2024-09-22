/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:55:41 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/22 02:50:58 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	run_philo(t_args *args)
{
	pthread_t	*philo_id;
	int			i;

	i = 0;
	philo_id = malloc(sizeof(pthread_t) * (args->n_philo + 1));
	if (!philo_id)
		return (0);
	while (i < args->n_philo)
	{
		if (pthread_create(&philo_id[i], NULL, philo_routine, args))
			return (0);
		i++;
	}
	monitor(args);
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(philo_id[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

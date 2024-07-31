/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:55:41 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/07/22 15:22:42 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*create_thread(t_args *args)
{
	pthread_t	*philo_id;
	int			i;

	i = 0;
	philo_id = malloc(sizeof(pthread_t) * (args->n_philo + 1));
	if (!philo_id)
		return (NULL);
	while (i < args->n_philo)
	{
		if (pthread_create(&philo_id[i], NULL, philo_routine, args))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(&philo_id[i], NULL))
			return (NULL);
		i++;
	}
	return (philo_id);
}

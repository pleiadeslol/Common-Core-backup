/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:39:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/07/22 15:20:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*create_forks(t_args *args)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * (args->n_philo + 1));
	if (!fork)
		return (NULL);
	while (i < args->n_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			retrun (NULL);
		i++;
	}
	return (fork);
}

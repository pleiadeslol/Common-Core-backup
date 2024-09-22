/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:39:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/22 00:47:49 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_forks(t_args *args)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * (args->n_philo + 1));
	if (!fork)
		return (0);
	while (i < args->n_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (0);
		i++;
	}
	args->forks = fork;
	return (1);
}

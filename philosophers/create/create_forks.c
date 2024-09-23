/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:39:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 02:55:05 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_forks(t_args *args)
{
	int				i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * (args->n_philo + 1));
	if (!args->forks)
		return (0);
	while (i < args->n_philo)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

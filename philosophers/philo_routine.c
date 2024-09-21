/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:42:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/21 21:58:09 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *data)
{
	t_args	*args;
	t_philo	*philo;
	int		i;

	args = (t_args *)data;
	i = 0;
	philo = args->philo;
	if (philo->id % 2 == 0)
		usleep(5000);
	while(1)
	{
		take_fork(philo[i]);
		// eat(args);
		// put_fork(args);
		// philo_sleep(args);
		// think(args);
	}
}

void	take_fork(t_philo philo)
{
	
}

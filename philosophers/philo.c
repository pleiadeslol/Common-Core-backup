/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/14 10:12:50 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	pthread_t	*philo_id;
	t_philo	*philo;

	args = set_args(ac, av);
	if (!args)
		return (1);
	printf("%d\n", args->time_to_sleep);
	philo = malloc(sizeof(t_philo));
	philo->fork = create_mutex(args);
	philo_id = create_thread(args);
}

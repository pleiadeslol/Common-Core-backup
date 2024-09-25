/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 02:36:44 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/25 20:43:22 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_args *args)
{
	bool	run;

	run = true;
	while (run)
	{
		pthread_mutex_lock(&args->state[EAT]);
		if (check_death(args) || check_eat_goal(args))
			run = false;
		pthread_mutex_unlock(&args->state[EAT]);
		ft_usleep(1, args);
	}
}

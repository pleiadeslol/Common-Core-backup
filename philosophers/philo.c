/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/08/22 08:49:33 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args			*args;
	pthread_t		*philo_id;
	t_philo			**philo;
	
	check_args(ac, av);
	args = parse_data(ac, av);
	if (!args)
		exit(EXIT_FAILURE);
	args->forks = create_forks(args);
	if (!args->forks)
		exit(EXIT_FAILURE);
	philo = init_philo(args);
	philo_id = create_thread(args);
	if (!philo_id)
		exit(EXIT_FAILURE);
}

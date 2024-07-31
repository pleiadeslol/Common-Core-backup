/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:35:35 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:53 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_args *args, pthread_t *philo_id)
{
	t_philo	**philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo *));
	if (!philo)
		return (NULL);
	while (i < args->n_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return (NULL);
		i++;
	}
	i = 0;
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 03:18:33 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/10 04:25:55 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_routine
{
	char	*str;
	pthread_mutex_t mutex;
}	t_routine;

static void	*philo_routine(void *l)
{
	t_routine	*j;

	j = (t_routine *)l;
	pthread_mutex_lock(&j->mutex);
	printf("%s\n", j->str);
	pthread_mutex_unlock(&j->mutex);
}

pthread_t	*create_thread(t_args *args)
{
	pthread_t	*philo_id;
	int			i;
	t_routine	*j;
	pthread_mutex_t	mutex;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	j = malloc(sizeof(t_routine));
	j->str = "hello";
	j->mutex = mutex;
	philo_id = malloc(sizeof(pthread_t) * args->n_philo);
	if (!philo_id)
		return (NULL);
	while (i < args->n_philo)
	{
		pthread_create(&philo_id[i], NULL, philo_routine, j);
		i++;
	}
	i = 0;
	while (i < args->n_philo)
	{
		pthread_join(philo_id[i], NULL);
		i++;
	}
	return(philo_id);
}

pthread_mutex_t	*create_mutex(t_args *args)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	while (i < args->n_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

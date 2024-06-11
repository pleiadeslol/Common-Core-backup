/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:21 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/10 11:32:24 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_args
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_philo_eat;
}	t_args;

typedef struct	s_philo
{
	pthread_mutex_t	*fork;
}	t_philo;

t_args			*set_args(int ac, char **av);
int				ft_atoi(const char *str);
pthread_t		*create_thread(t_args *args);
pthread_mutex_t	*create_mutex(t_args *args);

#endif

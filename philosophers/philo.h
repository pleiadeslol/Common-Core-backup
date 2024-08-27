/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:21 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/08/27 21:04:41 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef	struct	s_philo t_philo;

typedef struct	s_args
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_philo_eat;
	pthread_mutex_t	*forks;
	t_philo	*philo;
}	t_args;

typedef struct	s_philo
{
	pthread_mutex_t*	fork;
	int				*id;
}	t_philo;

enum	e_state
{
	FORK,
	EATING,
	THINKING,
	SLEEPING,
	DYING
};

void	check_args(int ac, char **av);
int		ft_isdigit(int c);
t_args	*parse_data(int ac, char **av);
int		ft_atoi(const char *str);
pthread_mutex_t	*create_forks(t_args *args);
pthread_t	*create_thread(t_args *args);
void	*philo_routine(void *data);
t_philo	**init_philo(t_args *args);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:21 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:34:50 by rzarhoun         ###   ########.fr       */
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
# include <stdbool.h>

# define ARGS_MUTEX 3

enum	e_state
{
	DEATH,
	EAT,
	PRINT
};
typedef struct s_philo	t_philo;

typedef struct s_args
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo_eat;
	bool			end;
	long long		t_start;
	pthread_mutex_t	state[ARGS_MUTEX];
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_args;

typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	int					id;
	int					meals_eaten;
	long long			last_meal;
	t_args				*args;
}	t_philo;

void		check_args(int ac, char **av);
int			ft_isdigit(int c);
t_args		*parse_data(int ac, char **av);
int			ft_atoi(const char *str);
int			create_forks(t_args *args);
int			run_philo(t_args *args);
void		*philo_routine(void *data);
int			init_philo(t_args *args);
void		take_fork(t_philo *philo);
long long	get_tstart(void);
long long	get_time(t_args *args);
void		ft_usleep(size_t ms, t_args *args);
void		print_state(t_args *args, int id, char *state);
void		eat(t_philo *philo);
void		put_fork(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		think(t_philo *philo);
void		monitor(t_args *args);
bool		check_death(t_args *args);
bool		check_eat_goal(t_args *args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:52:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:44:14 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807 / 10)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

bool	check_death(t_args *args)
{
	long long	current_time;
	int			i;

	current_time = get_time(args);
	i = 0;
	if (current_time == -1)
		return (true);
	while (i < args->n_philo)
	{
		if (current_time - args->philo[i].last_meal > args->time_to_die)
		{
			print_state(args, args->philo[i].id, "died");
			pthread_mutex_lock(&args->state[DEATH]);
			args->end = true;
			pthread_mutex_unlock(&args->state[DEATH]);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_eat_goal(t_args *args)
{
	int	i;

	i = 0;
	if (args->nb_philo_eat == -1)
		return (false);
	while (i < args->n_philo)
	{
		if (args->philo[i].meals_eaten < args->nb_philo_eat)
			return (false);
		i++;
	}
	pthread_mutex_lock(&args->state[DEATH]);
	args->end = true;
	pthread_mutex_unlock(&args->state[DEATH]);
	return (true);
}

void	print_state(t_args *args, int id, char *state)
{
	long long	t;

	t = get_time(args) - args->t_start;
	if (t == -1)
		return ;
	pthread_mutex_lock(&args->state[PRINT]);
	printf("%llu %d %s\n", t, id + 1, state);
	pthread_mutex_unlock(&args->state[PRINT]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:52:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/22 02:50:14 by rzarhoun         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	get_tstart()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_sec / 1000);
}

void	ft_usleep(size_t ms)
{
	long long	start;

	start = get_tstart();
	if (start == -1)
		return ;
	while((get_tstart() - start) < (long long)ms)
		usleep(500);
}

bool	check_death(t_args *args)
{
	long long	current_time;
	int			i;

	current_time = get_tstart();
	i = 0;
	if (current_time == -1)
		return (true);
	while (i < args->n_philo)
	{
		if (current_time - args->philo[i].last_meal > args->time_to_die)
		{
			printf("%llu %d died\n", get_tstart() - args->t_start, args->philo->id);
			args->end = true;
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
	args->end = true;
	return (true);
}

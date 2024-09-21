/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:52:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/21 21:36:14 by rzarhoun         ###   ########.fr       */
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
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_sec / 1000);
}

long long time_diff_ms(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000LL + 
           (end->tv_usec - start->tv_usec) / 1000LL;
}

int	die_flag(t_args	*args)
{
	struct timeval	start;
	struct timeval	time;
	long long	check;

	gettimeofday(&start, NULL);
	// time = get_last_meal(args->philo);
	check = time_diff_ms(&start, &time);
	if (check >= args->time_to_die)
		return (0);
	return (1);
}

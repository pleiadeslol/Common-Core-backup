/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:36:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:46:06 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_tstart(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long	get_time(t_args *args)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		pthread_mutex_lock(&args->state[DEATH]);
		args->end = true;
		pthread_mutex_unlock(&args->state[DEATH]);
		return (-1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(size_t ms, t_args *args)
{
	long long	start;

	start = get_time(args);
	if (start == -1)
		return ;
	while ((get_time(args) - start) < (long long)ms)
		usleep(500);
}

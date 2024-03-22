/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:22:43 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/22 00:46:19 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_stack *a)
{
	int	tmp;

	tmp = INT_MIN;
	while (a != NULL)
	{
		if (a->value > tmp)
			tmp = a->value;
		a = a->next;
	}
	return (tmp);
}

int	find_min(t_stack *a)
{
	int	tmp;

	tmp = INT_MAX;
	while (a != NULL)
	{
		if (a->value < tmp)
			tmp = a->value;
		a = a->next;
	}
	return (tmp);
}

int	find_index(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (a->next != NULL)
	{
		if (a->value == n)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	pb_four(t_stack **a, t_stack **b, int i)
{
	if (i == 0)
		pb(a, b);
	else if (i == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (i == 2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (i == 3)
	{
		rra(a);
		pb(a, b);
	}
}

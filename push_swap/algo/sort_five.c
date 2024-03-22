/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:44:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/22 00:40:45 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pb_five(t_stack **a, t_stack **b, int i)
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
		rra(a);
		pb(a, b);
	}
	else if (i == 4)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	i;

	min = find_min(*a);
	i = find_index(*a, min);
	pb_five(a, b, i);
	min = find_min(*a);
	i = find_index(*a, min);
	pb_four(a, b, i);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

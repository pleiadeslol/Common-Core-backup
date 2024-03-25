/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:34:49 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/25 05:01:28 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_stack **a, t_stack **b, int *array_sorted,
		int proxime)
{
	set_index(*a, array_sorted);
	push_b(a, b, 0, proxime);
	push_a(a, b);
}

void	push_a(t_stack **a, t_stack **b)
{
	int	max_index;

	max_index = 0;
	while (*b)
	{
		max_index = ft_lstsize(*b) - 1;
		while (max_index != (*b)->index)
		{
			if (find_index(*b, find_max(*b)) < ft_lstsize(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	push_b(t_stack **a, t_stack **b, int i, int proxime)
{
	int	end;
	int	y;

	end = ft_lstsize(*a);
	y = 0;
	while (y < end)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
			y++;
		}
		else if ((*a)->index <= i + proxime)
		{
			pb(a, b);
			y++;
			i++;
		}
		else
			check_index(a, i, proxime);
	}
}

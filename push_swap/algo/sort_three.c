/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:21:17 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 22:42:28 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	int		max;
	int		i;

	max = find_max(*a);
	i = find_index(*a, max);
	if (i == 0)
		ra(a);
	else if (i == 1)
		rra(a);
	if ((*a)->value > (*a)->next->value)
			sa(a);
}

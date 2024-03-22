/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:40:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/22 00:42:15 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	i;

	min = find_min(*a);
	i = find_index(*a, min);
	pb_four(a, b, i);
	sort_three(a);
	pa(a, b);
}

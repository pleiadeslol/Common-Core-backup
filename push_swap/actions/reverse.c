/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:49:20 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 06:50:47 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	ft_reverse_rotate(&a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	ft_reverse_rotate(&b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(&a);
	ft_reverse_rotate(&b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:46:10 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 06:48:59 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	ft_rotate(&a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ft_rotate(&b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(&a);
	ft_rotate(&b);
	write(1, "rr\n", 3);
}

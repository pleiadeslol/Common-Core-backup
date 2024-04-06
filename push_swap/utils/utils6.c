/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:32:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/05 23:35:58 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a_b(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}

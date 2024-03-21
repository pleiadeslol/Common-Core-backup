/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 05:54:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 06:35:50 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa, sb and ss (sa and sb)
void	ft_swap(t_stack **s)
{
	t_stack	*current;
	int		tmp;

	current = *s;
	if (current && current->next)
	{
		tmp = current->value;
		current->value = current->next->value;
		current->next->value = tmp;
	}
}
// pa and pb
void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, current);
}
//ra, rb and rr (ra and rb)
void	ft_rotate(t_stack **s)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *s;
	if (current && current->next)
	{
		*s = (*s)->next;
		tmp = *s;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = current;
		current->next = NULL;
	}
}
//rra, rrb and rrr (rra and rrb)
void	ft_reverse_rotate(t_stack **s)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *s;
	tmp = NULL;
	if (current && current->next)
	{
		while (current->next)
		{
			tmp = current;
			current = current->next;
		}
		tmp->next = NULL;
		current->next = *s;
		*s = current;
	}
}
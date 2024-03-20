/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:30:27 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/11 23:30:27 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
	struct s_stack *previous;
}   t_stack;

// parsing functions
int check_param(int ac);
int check_type(char **av);
int check_double(char **av);
int	handle_errors(int ac, char **av);
// utils functions
int ft_strcmp(const char *s1, const char *s2);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif
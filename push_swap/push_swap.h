/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:17:44 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 02:17:44 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

// parsing functions
int		check_limit(char **av);
int		check_type(char **av);
int		check_double(char **av);
int		handle_errors(char **av);
t_stack	*init_stack(char **av);
// utils functions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	**handle_av(char **av);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	free_av(char **av);
int		find_max(t_stack *a);
int		find_min(t_stack *a);
int		find_index(t_stack *a, int n);
void	pb_four(t_stack **a, t_stack **b, int i);
void    split_a(t_stack **a, t_stack **b);
// sorting functions
void	ft_swap(t_stack **s);
void	ft_push(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **s);
void	ft_reverse_rotate(t_stack **s);
//rules functions
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// algo functions
int		check_sorted(t_stack *a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_one_h(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);

#endif
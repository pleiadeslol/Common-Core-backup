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

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

// parsing functions
int		check_param(int ac);
int		check_limit(char **av);
int		check_type(char **av);
int		check_double(char **av);
int		handle_errors(int ac, char **av);
// utils functions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	**handle_av(int ac, char **av);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	free_av(char **av);

#endif
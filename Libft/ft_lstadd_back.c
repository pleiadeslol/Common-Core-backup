/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:19:09 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/07 18:11:25 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/**#include <stdio.h>

int main()
{
    t_list *root = NULL;

    // Create and add nodes to the list
    for (int i = 1; i <= 5; i++)
    {
        t_list *new = malloc(sizeof(t_list));
        new->content = i;
        ft_lstadd_back(&root, new);
    }

    // Print the list
    printf("List contents:\n");
    t_list *tmp = root;
    while (tmp != NULL)
    {
        printf("%d ", tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
    return 0;
}**/

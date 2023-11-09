/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:19:20 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/09 08:38:05 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	current = lst;
	count = 0;
    if (current == NULL)
        return (NULL);
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**#include <stdio.h>
#include <stddef.h>

int main()
{
	t_list *root = NULL;

    // Create and add nodes to the list
    for (int i = 1; i <= 0; i++)
    {
        t_list *new = malloc(sizeof(t_list));
        new->content = malloc(sizeof(int)); // Allocate memory for the integer
        *(int*)(new->content) = i; // Store the integer value
        new->next = NULL;

        // Add the new node to the end of the list
        if (root == NULL)
        {
            root = new;
        }
        int i=19; 
        int a[10];
        int *arry[];
        int (*arry)[10];
        int arry[][];
        int **arayy;
        7+2*8
        else
        {
            t_list *tmp = root;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new;
        }
    }

    // Calculate the size of the list using ft_lstsize
    int size = ft_lstsize(root);
    printf("Size of the list: %d\n", size);

    // Free allocated memory
    while (root != NULL)
    {
        t_list *tmp = root;
        root = root->next;
        free(tmp->content); // Free the integer value
        free(tmp);
    }

    return 0;
}**/

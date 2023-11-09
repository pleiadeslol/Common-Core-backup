/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:24:20 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/09 22:25:08 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return ;
	while (current)
	{
		if (f)
			f(current->content);
		current = current->next;
	}
}

/**#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	incrementBy(void *content) {
	int *value = (int *)content;
	int incrementValue = 2;
	*value += incrementValue;
}

int	main(void) {
	t_list *head = NULL;
	for (int i = 1; i <= 5; i++) {
		t_list *newNode = (t_list *)malloc(sizeof(t_list));
		int *value = (int *)malloc(sizeof(int));
		*value = i;
		newNode->content = value;
		newNode->next = head;
		head = newNode;
	}

	void (*incrementFunction)(void *) = incrementBy;

	printf("Original List: ");
	t_list *current = head;
	while (current) {
		int *value = (int *)(current->content);
		printf("%d ", *value);
		current = current->next;
	}
	printf("\n");

	ft_lstiter(head, incrementFunction);

	printf("Modified List: ");
	current = head;
	while (current) {
		int *value = (int *)(current->content);
		printf("%d ", *value);
		current = current->next;
	}
	printf("\n");

	while (head) {
		t_list *temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}

	return (0);
}**/
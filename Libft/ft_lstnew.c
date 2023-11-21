/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:34:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/21 01:32:40 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
#include <stdio.h>

void ft_printlst(void *content)
{
	printf("%d\n", *((int *)content));
}
int main()
{
	int *arr = malloc(sizeof(int *) * 4);
	int i = 0;
	while(i < 4)
	{
		arr[i] = i + 1;
		i++;
	}
	t_list *lst = ft_lstnew(&arr[0]);
	t_list *lst1 = ft_lstnew(&arr[1]);
	t_list *lst2 = ft_lstnew(&arr[2]);
	lst->next = lst1;
	lst1->next = lst2;
	ft_lstiter(lst, ft_printlst);
	printf("---------------------\n");
	lst->next = lst2;
	ft_lstdelone(lst1, free);
	ft_lstiter(lst, ft_printlst);
	return 0;
}
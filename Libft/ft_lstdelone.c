/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:09:12 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/09 10:00:26 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

/**void del_str(void *str) {
	if (str != NULL) {
		free(str);
	}
}

#include <stdio.h>
#include <string.h>

int	main(void) {
	t_list *node = (t_list *)malloc(sizeof(t_list));
	char *data = (char *)malloc(10);
	strcpy(data, "example");
	node->content = data;
	node->next = NULL;

	ft_lstdelone(node, del_str);

	if (node == NULL) {
		printf("Node deleted successfully.\n");
	}

  return (0);
}**/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:34:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/07 00:03:13 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list)malloc(sizeof(struct));
	if (tmp == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

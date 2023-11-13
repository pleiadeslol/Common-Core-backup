/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:46:25 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 20:51:14 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printvoid(void *p)
{
    if (p == 0)
        ft_putstr("0x00");
}

#include <stdio.h>

int main()
{
    void *p = 0;
    ft_printvoid(p);
    printf("\n%p\n", &p);
    return 0;
}
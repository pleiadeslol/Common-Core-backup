/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:41:12 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/24 17:15:42 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char c, va_list args, int *ptr)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), ptr);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), ptr);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), ptr);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 'x', ptr);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 'X', ptr);
	else if (c == 'c')
		ft_putchar((char)va_arg(args, int), ptr);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, unsigned long), ptr);
	else if (c == '%')
		ft_putchar('%', ptr);
	else
		*ptr = -1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	if (!str)
		return (-1);
	length = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("csdiupxX%", str[i + 1]))
		{
			check_flags(str[i + 1], args, &length);
			if (length == -1)
				return (length);
			i++;
		}
		else
		{
			ft_putchar(str[i], &length);
		}
		i++;
	}
	return (length);
}

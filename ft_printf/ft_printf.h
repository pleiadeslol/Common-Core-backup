/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:32 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/21 23:36:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int ft_printf(const char *, ...);
void    ft_putchar(char c);
void    ft_putstr(char *str);

#endif
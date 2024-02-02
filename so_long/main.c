/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/01 15:46:39 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

int main(int ac, char **av)
{
    int fd;

    //first let's check if the map is a .ber file
    if (!check_ber(av[1]))
    {
        printf("Map isn't a .ber file\n");
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (0);
    }
    char **str = malloc(sizeof(char *));
    int i = 0;
    while ((str[i] = get_next_line(fd)))
        i++;
    if (!check_len(str))
    {
        printf("Map isn't rectangular\n");
        return (0);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:47:50 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/02 15:31:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[100];
	int age;
	double average;
} student;

int	main()
{
	char	*src = "hello";
	char	dest[50];
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("src = %s\n", src);
	printf("dest = %s\n", dest);
	char	*dest_ptr = ft_memcpy(dest, src, strlen(src) + 1);
	printf("dest_ptr = %p\n", dest_ptr);
	printf("dest = %p\n", dest);
	double	src_array[3] = {1.1, 2.2, 3.3};
	double	dest_array[3];
	ft_memcpy(dest_array, src_array, sizeof(src_array));
	for (int i = 0; i < 3; i++)
		printf("dest_array[%d] = %f\n", i, dest_array[i]);
	student student1;
	strcpy(student1.name, "Roumaissae");
	student1.age = 19;
	student1.average = 99.7;
	student student2;
	ft_memcpy(&student2, &student1, sizeof(student));
	printf("Name = %s\n", student2.name);
	printf("Age = %d\n", student2.age);
	printf("Average = %f\n", student2.average);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:53:59 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/18 15:54:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*
int	ft_add_one(int nb)
{
	nb = nb + 1;
	return (nb);
}
*/

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};
	int i = 0;
	printf("Tableau initial: 12345");
	int *result = ft_map(tab, 5, &ft_add_one);
	printf("\nTableau obtenu avec ft_add_one: ");
	while (i < 5)
	{
		printf("%d", result[i]);
		i++;
	}
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:43:14 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/23 14:43:21 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	length;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = (int *)malloc(sizeof(int) * length);
	if (!(*range))
		return (-1);
	i = 0;
	while (i < length)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (length);
}

/*int main(void)
{
    int len;
    int *range;
    len = ft_ultimate_range(&range, 1, 5);
    printf("Nombre d'indices attendu: %d\n", len);
    printf("Tableau obtenu: %d, %d, %d, %d\n", range[0], 
	range[1], range[2], range[3]);
    return (0);
}*/

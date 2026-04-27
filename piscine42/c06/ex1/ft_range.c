/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:17:00 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/18 16:17:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	tab = (int *)malloc(sizeof(int) * len);
	while (tab[i] < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*int main(void)
{
    int *range;

    range = ft_range(0, 5);
    printf("ft_range(0, 5) Resultat attendu: 0, 1, 2, 3, 4\n");
    printf("Resultat obtenu: %d, %d, %d, %d, %d\n", range[0], 
	range[1], range[2], range[3], range[4]);
    range = ft_range(-1, 2);
    printf("ft_range(-1, 2) Resultat attendu: -1, 0, 1\n");
    printf("Resultat obtenu: %d, %d, %d\n", range[0], range[1], range[2]);
}
*/
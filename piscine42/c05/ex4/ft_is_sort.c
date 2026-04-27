/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:38:46 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/18 14:38:49 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
/*
int ft_strcmp(int s1, int s2)
{
    return (s1 - s2);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	crois;
	int	decrois;

	i = 0;
	crois = 1;
	decrois = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			crois = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			decrois = 0;
		i++;
	}
	if (crois == 1 || decrois == 1)
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	tab[8] = {1, 2, 3, 4, 5};

	printf("%d\n", ft_is_sort(tab, 5, ft_strcmp));
	return (0);
}
*/
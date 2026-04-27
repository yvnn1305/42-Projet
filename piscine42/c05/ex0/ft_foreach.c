/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 03:05:55 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/11 13:16:50 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

/*
int	ft_addone(int nb)
{
	nb = nb + 1;
	return (nb);
}
*/
void	ft_foreach(int *tab, int length, int (*f)(int))
{
	int	i;
	i = 0;
	while (i <= length - 1)
	{
		tab[i] = f(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};
	ft_foreach(tab, 5, &ft_addone);
	for (int i = 0; i < 5; i++)
		printf("%d", tab[i]);
	return 0;
}*/

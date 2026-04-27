/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:47:46 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/13 10:24:37 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &"0123456789"[tab[i]], 1);
		i++;
	}
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (1)
	{
		ft_print(tab, n);
		i = n - 1;
		while (i <= 9 && tab[i] == 10 - n + i)
			i--;
		tab[i]++;
		if (i < 0)
			return ;
		i++;
		while (i < n)
		{
			tab[i] = tab[i - 1] + 1;
			i++;
		}
	}
}

int	main(void)
{
	ft_print_combn(3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:02:20 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/08 17:09:26 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	fill_tab(int col, int lig, int i, int j)
{
	if ((i == 0 && j == 0)
		|| (i == 0 && j == col - 1)
		|| (i == lig - 1 && j == 0)
		|| (i == lig - 1 && j == col - 1))
		ft_putchar('o');
	else if (i == 0 || i == lig - 1)
		ft_putchar('-');
	else if (j == 0 || j == col - 1)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int col, int lig)
{
	long int	i;
	long int	j;

	if (lig < 0 || col < 0)
	{
		write(1, "Veuillez entrer une valeur superieure ou egale a 0.\n", 52);
		return ;
	}
	if (lig > 2147483647 || col > 2147483647)
	{
		return ;
	}
	i = 0;
	while (i < lig)
	{
		j = 0;
		while (j < col)
		{
			fill_tab(col, lig, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

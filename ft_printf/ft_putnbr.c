/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/06 15:03:09 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		add;

	add = 1;
	n = (long)nb;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		add += 1;
	}
	if (n > 9)
		add += ft_putnbr(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (add);
}

int	ft_putunsig(unsigned int n)
{
	int	add;

	add = 1;
	if (n >= 10)
		add += ft_putunsig(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (add);
}

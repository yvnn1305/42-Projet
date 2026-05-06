/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/06 15:02:50 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	write_hexa(unsigned long nb, char c)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (c == 'x')
	{
		if (nb > 15)
			write_hexa(nb / 16, c);
		write(1, &lower[nb % 16], 1);
	}
	else if (c == 'X')
	{
		if (nb > 15)
			write_hexa(nb / 16, c);
		write(1, &upper[nb % 16], 1);
	}
}

int	ft_printptr(void *adress)
{
	long	n;

	if (!adress)
	{
		write(1, "0x0", 3);
		return (3);
	}
	n = count_hex((unsigned long)adress) + 2;
	write(1, "0x", 2);
	write_hexa((unsigned long)adress, 'x');
	return (n);
}

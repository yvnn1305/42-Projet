/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/03 16:57:33 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}

int	count_hex(unsigned long nb)
{
	unsigned long	len;
	long			n;

	len = 0;
	n = nb;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	write_hexa(unsigned long c1, char c)
{
	if (c == 'x')
	{
		if (c1 > 15)
			write_hexa(c1 / 16, c);
		write(1, &"0123456789abcdef"[c1 % 16], 1);
	}
	else if (c == 'X')
	{
		if (c1 > 15)
			write_hexa(c1 / 16, c);
		write(1, &"0123456789ABCDEF"[c1 % 16], 1);
	}
}

int	hexa(unsigned long c1, char c)
{
	unsigned long	len;

	len = count_hex(c1);
	write_hexa(c1, c);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/06 15:03:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	char	*ch;
	int		count;

	if (c == 'x')
		ch = "0123456789abcdef";
	else
		ch = "0123456789ABCDEF";
	count = 1;
	if (n >= 16)
		count += ft_puthexa(n / 16, c);
	write(1, &ch[n % 16], 1);
	return (count);
}

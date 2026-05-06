/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/06 15:02:20 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	result(va_list *ap, char c)
{
	void	*ptr;

	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 'p')
	{
		ptr = va_arg(*ap, void *);
		return (ft_printptr(ptr));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putunsig(va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(*ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += result(&ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int main(void)
{
	ft_printf(" %p %p ", (void *)0, (void *)0);
	printf("\n");
	printf(" %p %p ", (void *)0, (void *)0);
}*/
/*
int	main(void)
{
//	int	a = 5;
//	int	*p = &a;
//	int ret1 = printf("LIB : %p\n", 0);
	int ret2 = ft_printf("FT : %p %p\n", 0, 0);
//	printf("LIB len: %d\n", ret1);
	printf("FT len: %d\n", ret2);
}*/
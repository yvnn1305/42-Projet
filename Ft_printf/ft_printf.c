/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:57:51 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/03 16:57:52 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	result(va_list ap, char c)
{
	int	d;

	d = 0;
	if (c == 'c')
		d = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		d = ft_putstr_count(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		d = write_int(va_arg(ap, int));
	else if (c == 'u')
		d = write_unsint(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		d = hexa(va_arg(ap, unsigned long), c);
	else if (c == 'p')
		d = ft_printptr(va_arg(ap, void *));
	else if (c == '%')
		d = ft_putchar('%');
	return (d);
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
			len += result(ap, format[i + 1]);
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

int	main(void)
{
//	int a = 5;
//	int *p = &a;
	printf("--- FT - c ---\n");
	printf("%c\n", 'a');
	printf("---LIB---\n");
	ft_printf("%c\n\n\n", 'a');
	printf("----------\n\n");


	printf("--- FT - s ---\n");
	printf("%s\n", "0");
	printf("---LIB---\n");
	ft_printf("%s\n\n\n", 0);
	printf("----------\n\n");


	printf("--- FT - p ---\n");
	printf("%p\n", NULL);
	printf("---LIB---\n");
	ft_printf("%p\n\n\n", NULL);
	printf("----------\n\n");


	printf("--- FT - d ---\n");
	printf("%d\n", (int)-2147483648);
	printf("---LIB---\n");
	ft_printf("%d\n\n\n", (int)-2147483648);
	printf("----------\n\n");


	printf("--- FT - i ---\n");
	printf("%i\n", 123446);
	printf("---LIB---\n");
	ft_printf("%i\n\n\n", 123446);
	printf("----------\n\n");


	printf("--- FT - u ---\n");
	printf("%u\n", -1225256);
	printf("---LIB---\n");
	ft_printf("%u\n\n\n", -1225256);
	printf("----------\n\n");


	printf("--- FT - x ---\n");
	printf("%x\n", 255);
	printf("---LIB---\n");
	ft_printf("%x\n\n\n", 255);
	printf("----------\n\n");


	printf("--- FT - X ---\n");
	printf("%X\n", 255);
	printf("---LIB---\n");
	ft_printf("%X\n\n\n", 255);
	printf("----------\n\n");


	printf("--- FT - %% ---\n");
	printf("%%%%\n");
	printf("---LIB---\n");
	ft_printf("%%%%\n\n\n");



}

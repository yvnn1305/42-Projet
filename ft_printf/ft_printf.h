/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:58:01 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/06 15:01:08 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	result(va_list *ap, char c);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_printptr(void *adress);
int	ft_putnbr(int nb);
int	ft_putunsig(unsigned int n);
int	ft_puthexa(unsigned int n, char c);

#endif
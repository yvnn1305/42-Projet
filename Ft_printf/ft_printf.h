/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:58:01 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/03 16:58:02 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *format, ...);
int				result(va_list ap, char c);
int				ft_putchar(char c);
int				ft_putstr_count(char *str);
int				count_int(int nb);
int				count_unsint(unsigned int nb);
void			ft_putnbr(int nb);
int				write_int(int nb);
int				ft_printptr(void *adress);
void			write_hexa(unsigned long c1, char c);
int				hexa(unsigned long c1, char c);
int				count_hex(unsigned long nb);
int				write_unsint(unsigned int nb);
void			ft_putnbr_u(unsigned int nb);
size_t	        ft_strlen(const char *str);

#endif

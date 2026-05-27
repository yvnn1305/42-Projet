/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:13:25 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/27 20:42:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

// ============ PARSING ===============
int		is_valid_tokens(char *token);
char	**parse(int argc, char **argv);
char	**join_arrays(char **tab1, char **tab2);
int		tokens_check(char **tab);

// ============= PRINTF ===============
int	ft_printf(const char *format, ...);
int	result(va_list *ap, char c);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_printptr(void *adress);
int	ft_putnbr(int nb);
int	ft_putunsig(unsigned int n);
int	ft_puthexa(unsigned int n, char c);

// ============= UTILS ================
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		tab_len(char **tab);

#endif
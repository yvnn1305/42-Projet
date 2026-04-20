/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:52:43 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/18 23:42:05 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	printf("Test 1: %zu\n", ft_strlen("Hello"));        // 5
	printf("Test 2: %zu\n", ft_strlen(""));             // 0
	printf("Test 3: %zu\n", ft_strlen("42 Network"));   // 10
	printf("Test 4: %zu\n", ft_strlen("A"));            // 1

	return (0);
}*/
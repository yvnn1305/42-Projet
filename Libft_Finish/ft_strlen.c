/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:25:52 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:25:53 by yakombo-         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:56:14 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/14 23:25:21 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
/*
int	main(void)
{
	char	d1[20] = "Helloworld";
	char	d2[20] = "Hel3loworld";

	printf("FT  : %d\n", ft_memcmp(d1, d2, 5));
	printf("LIB  : %d\n", memcmp(d1, d2, 5));
	return (0);
}*/

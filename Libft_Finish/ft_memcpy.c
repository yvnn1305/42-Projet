/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:22:15 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:22:16 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dep;
	unsigned char	*fin;

	i = 0;
	dep = (unsigned char *)src;
	fin = (unsigned char *)dst;
	while (i < n)
	{
		fin[i] = dep[i];
		i++;
	}
	return (fin);
}
/*
int	main(void)
{
	char	s1[] = "hello world";
	char	s2[] = "hello world";

	char	d1[20];
	char	d2[20];

	ft_memcpy(d1, s1, 11);
	memcpy(d2, s2, 11);

	d1[11] = '\0';
	d2[11] = '\0';

	printf("==== Cas normal ====\n");
	printf("FT : %s\n", d1);
	printf("LIB : %s\n", d2);

	if (strcmp(d1, d2) == 0)
		printf("OK memcpy\n");
	else
		printf("KO memcpy\n");

	return (0);
}*/

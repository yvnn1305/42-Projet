/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:25:05 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/12 18:47:36 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	s1[] = "helloworld";
	char	s2[] = "helloworld";

	char	d1[20];
	char	d2[20];

	ft_strlcpy(d1, s1, 5);
	strlcpy(d2, s2, 5);

	printf("==== TEST ====\n");
	printf("FT : %s\n", d1);
	printf("LIB : %s\n\n", d2);
	printf("==== TAILLE SRC ====\n");
	printf("FT : %zu\n", ft_strlcpy(d1, s1, 5));
	printf("LIB : %zu", ft_strlcpy(d2, s2, 5));

	return (0);
}*/
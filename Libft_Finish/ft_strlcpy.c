/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:25:39 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:25:40 by yakombo-         ###   ########.fr       */
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

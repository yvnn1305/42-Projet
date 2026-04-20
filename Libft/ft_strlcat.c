/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 01:27:58 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/14 23:27:27 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	while (src[j] && i < dstsize - dst_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
int	main(void)
{
	char	d1[20] = "Hello";
	char	d2[20] = "Hello";

	printf("Valeur retournee par la fonction : 
	 %zu\n", ft_strlcat(d1, " World", 20));
	printf("Valeur retournee par la fonction originale : 
	 %zu\n", strlcat(d2, " World", 20));

	printf("FT  : %s\n", d1);
	printf("LIB  : %s\n", d2);
	return (0);
}*/
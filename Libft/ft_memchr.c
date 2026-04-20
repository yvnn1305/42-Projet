/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:07:18 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/14 23:26:46 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	d1[20] = "HelHelo";
	char	d2[20] = "HelHelo";
	void	*p = ft_memchr(d1, 'e', 2);
	void	*q = memchr(d2, 'e', 2);

	if (p)
		printf("Caractere retournee par la fonction : %c\n", *(char *)p);
	else
		printf("NULL\n");
	if (q)
		printf("Caractere retournee 
		 par la fonction originale : %c\n", *(char *)q);
	else
		printf("NULL\n");
	return (0);
}*/
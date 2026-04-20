/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:03:18 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/12 18:54:14 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_back(unsigned char *d, unsigned char *s, size_t len)
{
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s)
		return (dst);
	if (d > s)
		ft_memmove_back(d, s, len);
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*
void	test(char *label, char *s1, char *s2, size_t len, int d, int s)
{
	printf("\n---- %s ----\n\n", label);

	ft_memmove(s1 + d, s1 + s, len);
	memmove(s2 + d, s2 + s, len);

	printf("FT  : %s\n", s1);
	printf("LIB  : %s\n\n\n", s2);
}

int	main(void)
{
	char a1[] = "abcdef";
	char a2[] = "abcdef";

	char b1[] = "abcdef";
	char b2[] = "abcdef";

	char c1[] = "abcdef";
	char c2[] = "abcdef";

	char d1[] = "abcdef";
	char d2[] = "abcdef";

	char e1[] = "abcdef";
	char e2[] = "abcdef";

	// 1. Chevauchage a droite
	test("Overlap droite", a1, a2, 4, 2, 0);

	// 2. Chevauchage a gauche
	test("Overlap gauche", b1, b2, 4, 0, 2);

	// 3. Same
	test("Same", c1, c2, 4, 0, 0);

	// 4. Petit decalage
	test("Petit decalage", d1, d2, 2, 3, 0);

	// 5. Gros decalage
	test("Gros decalage", e1, e2, 2, 3, 1);

	return (0);
}*/

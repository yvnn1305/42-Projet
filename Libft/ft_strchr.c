/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 02:07:11 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/14 22:02:54 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	d1[20] = "Hello";
	char	d2[20] = "Hello";

	printf("Chaine retournee par la fonction : %s\n", ft_strchr(d1, 'e'));
	printf("Chaine retournee par la fonction originale : %s\n", strchr(d2, 'e'));
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 02:18:42 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/14 23:26:05 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s) - 1;
	if (c == '\0')
	{
		return ((char *)&s[ft_strlen(s)]);
	}
	while (s[i] && i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	d1[20] = "Helleo";
	char	d2[20] = "Helleo";

	printf("Chaine retournee par la fonction : %s\n", ft_strrchr(d1, '\0'));
	printf("Chaine retournee par la fonction
	 originale : %s\n", strrchr(d2, '\0'));
	return (0);
}*/
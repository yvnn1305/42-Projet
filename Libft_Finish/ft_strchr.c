/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:24:07 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:24:15 by yakombo-         ###   ########.fr       */
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

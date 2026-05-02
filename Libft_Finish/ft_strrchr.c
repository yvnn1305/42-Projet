/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:27:24 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:27:25 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
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

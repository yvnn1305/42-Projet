/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:27:24 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/02 20:28:50 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	if (!s)
		return (NULL);
	last = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	if (last == -1)
		return (NULL);
	return ((char *)&s[last]);
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

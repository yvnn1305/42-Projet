/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:24:40 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:24:43 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = 0;
	if (!s1)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	*src = "Hello 42!";
	char	*dup;

	dup = ft_strdup(src);
	if (!dup)
	{
		printf("Allocation echoue\n");
		return (1);
	}

	printf("Source : %s\n", src);
	printf("Destination: %s\n", dup);

	free(dup);
	return (0);
}*/

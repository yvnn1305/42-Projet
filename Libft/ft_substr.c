/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:10:46 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/21 14:47:02 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = start;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
/*
int	main(int argc, char **argv)
{
	char	*result;

	if (argc == 2)
	{
		result = ft_substr(argv[1], 6, 5);
		printf("La chaine renvoye par la fonction: %s.", result);
		free (result);
	}
	printf("\n");
	return (0);
}*/

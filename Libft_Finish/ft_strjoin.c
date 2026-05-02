/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:25:09 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:25:10 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		total_len;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
		res[j++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
/*
int	main(int argc, char **argv)
{
	char	*result;

	result = ft_strjoin(argv[1], argv[2]);
	if (argc == 3)
		printf("%s", result);
	free (result);
	return (0);
}*/

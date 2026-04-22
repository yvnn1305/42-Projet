/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:06:18 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/22 21:46:10 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char const *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i2;
	size_t	j;
	size_t	k;
	char	*res;

	res = malloc(sizeof(char) * 1000);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	i2 = 0;
	k = ft_strlen((char const *)s1) - 1;
	printf("Caractere pointe par k : %c\n", s1[k]);
	while (s1[i] && is_sep((char const *)s1, set[i]))
		i++;
	while (s1[k])
	{
		i2 = 0;
		if (is_sep((char const *)s1, set[i2]))
		{
		k--;
		i2++;
		}
	}
	printf("Caractere pointe par k apres boucle : %c\n", s1[k]);
	while (s1[i] && i < k)
	{
		res[j++] = s1[i++];
	}
	return (res);
}

int	main(void)
{
	char	*result;
	char	*s1 = "abcJe m'appelle Yannabcabcn";
	char	*s2 = "abc";

	result = ft_strtrim(s1, s2);
	printf("%s\n", result);
	free (result);
}

char	*trimmed(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != set[i])
			res[i] = s1[i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	size_t	start;
	char	*res;

	i = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (set[j] == s1[i])
				i++;
		}
	}
}
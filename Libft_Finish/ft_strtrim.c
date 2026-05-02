/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:27:50 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:27:51 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char const *charset, char c)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_sep(set, s1[i]))
		i++;
	while (j > i && is_sep(set, s1[j - 1]))
		j--;
	len = j - i;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1 + i, len);
	res[len] = '\0';
	return (res);
}

/*int	main(void)
{
	char	*result;
	char	*s1 = "xxx   tripouille   xxx";
	char	*s2 = " x";

	result = ft_strtrim(s1, s2);
	printf("%s\n", result);
	free (result);
}*/

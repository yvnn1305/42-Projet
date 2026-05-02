/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:26:03 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:26:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	my_toupper(unsigned int index, char c)
{
	if (index % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;
	}
	return (c);	
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	char	*tab = "abcdefghijklmnopqrstuvwxyz";
	char	*res;
	res = ft_strmapi(tab, my_toupper);
	printf("%s\n", res);
}*/

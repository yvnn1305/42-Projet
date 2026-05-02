/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:22:39 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:22:42 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)pointer;
	i = 0;
	while (i < count)
	{
		str[i] = value;
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	char	res[10] = {0};
	char	res2[10] = {0};
	if (argc == 2 && argv[1][1] == '\0')
	{
		printf("%s\n", (char *)ft_memset(res, argv[1][0], 7));
		printf("%s", (char *)memset(res2, argv[1][0], 7));
	}
	write(1, "\n", 1);
}*/

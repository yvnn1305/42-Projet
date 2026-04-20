/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:10:01 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/12 15:44:10 by yannkombo-l      ###   ########.fr       */
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

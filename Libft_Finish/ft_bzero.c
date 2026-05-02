/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:18:24 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:18:25 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*
int	main(void)
{
	char	res[40];
	char	res2[40];
	int		i;

	ft_memset(res, 'A', 39);
	ft_memset(res2, 'B', 39);
	res[39] = '\0';
	res2[39] = '\0';
	ft_bzero(res, 10);
	bzero(res2, 10);
	i = 0;
	while (i < 10)
	{
		printf("res[%d]=%d | res2[%d]=%d\n", i, res[i], i, res2[i]);
		i++;
	}
	while (i < 40)
	{
		printf("res[%d]=%c | res2[%d]=%c\n", i, res[i], i, res2[i]);
		i++;
	}
	return (0);
}*/

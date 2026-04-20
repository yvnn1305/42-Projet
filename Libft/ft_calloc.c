/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:16:04 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/18 23:30:11 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	total;
	char	*res;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	res = malloc(sizeof(*res) * total);
	if (!res)
		return (NULL);
	while (i < total)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	int	*result;
	int	i = 0;
	result = ft_calloc(6, sizeof(int));
	if (!result)
		return (1);
	while (i < 6)
	{
		printf("%d ", result[i]);
		i++;
	}
	free(result);
	return (0);
}*/
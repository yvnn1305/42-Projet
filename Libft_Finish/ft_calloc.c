/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:18:50 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:18:51 by yakombo-         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:18:08 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:18:11 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char *tests[] = {
		"42",
		"   42",
		"\t\n  42",
		"+42",
		"-42",
		"---42",
		"++42",
		"+-42",
		"-+42",
		"42abc",
		"abc42",
		"",
		"   ",
		"0",
		"-0",
		"2147483647",
		"-2147483648",
		"2147483648",
		"-2147483649",
		NULL
	};

	int	i = 0;

	while (tests[i])
	{
		printf("Input : \"%s\"\n", tests[i]);
		printf("FT    : %d\n", ft_atoi(tests[i]));
		printf("LIB   : %d\n", atoi(tests[i]));
		printf("--------------------------\n");
		i++;
	}
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:33:27 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/16 11:57:33 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] < 127))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[20] = "Piscine42";
	printf("%d\n", ft_str_is_printable(str));
	return (0);
}*/	

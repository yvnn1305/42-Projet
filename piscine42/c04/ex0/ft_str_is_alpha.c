/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:55:57 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/09 20:17:23 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/*
int		main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
	!ft_str_is_alpha("Ecole")?"OK":"Fail",
		ft_str_is_alpha("ABCDEFGHIJKLMNOPQRST")?"OK":"Fail",
		!ft_str_is_alpha("1")?"OK":"Fail",
		!ft_str_is_alpha(" ")?"OK":"Fail",
		!ft_str_is_alpha("\\")?"OK":"Fail",
		!ft_str_is_alpha("\n")?"OK":"Fail");
}*/

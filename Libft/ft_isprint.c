/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannkombo-larra <yannkombo-larra@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:01:39 by yannkombo-l       #+#    #+#             */
/*   Updated: 2026/04/18 23:38:02 by yannkombo-l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", ft_isprint(argv[1][0]));
	printf("\n");
}*/

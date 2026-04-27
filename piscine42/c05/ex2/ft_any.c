/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:54:29 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/18 15:54:31 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
/*
int	f(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else
		return (0);
}
*/

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*tab[] = {"r3", "r0", "0", NULL};
	printf("%d\n", ft_any(tab, &f));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 18:04:31 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/09 15:44:13 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 40;
	printf("a avant: %d, b avant: %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a apres: %d, b apres: %d\n", a, b);
	return (0);
}*/

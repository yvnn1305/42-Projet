/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:57:10 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/24 11:57:13 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fill_result(char *result, long n, char *base, int base_len);
void	reverse_str(char *str, int start);
int		ft_strlenbase(char *base);
int		char_in_base(char c, char *base);
int		is_valid(char *base);

int	atoi_base(char *nbr, char *base_from)
{
	int	digits;

	int (i) = 0;
	int (result) = 0;
	int (sign) = 1;
	if (!is_valid(base_from))
		return (0);
	while (((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		|| nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nbr[i])
	{
		digits = char_in_base(nbr[i], base_from);
		if (digits == -1)
			break ;
		result = result * ft_strlenbase(base_from) + digits;
		i++;
	}
	return (result * sign);
}

char	*itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	long	n;

	if (!is_valid(base))
		return (NULL);
	base_len = ft_strlenbase(base);
	n = nbr;
	result = malloc(50);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
		fill_result(result + 1, n, base, base_len);
		reverse_str(result, 1);
	}
	else
	{
		fill_result(result, n, base, base_len);
		reverse_str(result, 0);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	if (!is_valid(base_from) || !is_valid(base_to))
		return (NULL);
	num = atoi_base(nbr, base_from);
	result = itoa_base(num, base_to);
	return (result);
}

/*int	main(void)
{
	printf("\n=== itoa_base ===\n");
	printf("42 -> base2 = %s\n", itoa_base(42, "01"));
	printf("-42 -> base2 = %s\n", itoa_base(-42, "01"));
	printf("42 -> base16 = %s\n", itoa_base(42, "0123456789ABCDEF"));
}*/

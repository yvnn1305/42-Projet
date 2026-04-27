/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:02:05 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/24 12:02:07 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlenbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	reverse_str(char *str, int start)
{
	int		end;
	char	temp;

	end = 0;
	while (str[end])
		end++;
	end--;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

void	fill_result(char *result, long n, char *base, int base_len)
{
	int	i;

	i = 0;
	if (n == 0)
		result[i++] = base[0];
	while (n > 0)
	{
		result[i++] = base[n % base_len];
		n = n / base_len;
	}
	result[i] = '\0';
}

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	j = 0;
	while (base[j])
	{
		i = j + 1;
		while (base[i])
		{
			if (base[j] == base[i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

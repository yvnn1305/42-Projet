/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:13:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/27 20:13:31 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Check si les inputs recus sont valides 
//	(que des chiffres, et avec si il y a un '-' en position 0).
int	is_valid_tokens(char *token)
{
	int	i;

	i = 0;
	if (!token[0])
		return (1);
	while (token[i])
	{
		if (i == 0 && (!((token[i] >= '0'
						&& token[i] <= '9') || token[i] == '-')))
			return (1);
		if (i == 0 && token[i] == '-'
			&& (token[i + 1] >= '0' && token[i + 1] <= '9'))
		{
			i++;
			continue ;
		}
		if (!(token[i] >= '0' && token[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// Check si des doublons sont presents, si oui on retourne 1.
int	is_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Teste les 2 fonctions pour s'assurer que les inputs sont au bon format.
int	tokens_check(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (is_valid_tokens(tab[i]) == 1)
			return (1);
		i++;
	}
	if (is_double(tab) == 1)
		return (1);
	return (0);
}
/*int	main(void)
{
	char	*tab[] = {"3", "1", "2", "5364", NULL};
	printf("resultat: %d", tokens_check(tab));
}*/
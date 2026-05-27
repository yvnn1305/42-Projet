/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:13:36 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/27 20:23:43 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Objectif: Concatener deux tableaux de pointeurs afin d'obtenir a la fin 
// tous les input dans un seul et meme tableau de pointeurs.
char	**join_arrays(char **tab1, char **tab2)
{
	int		len;
	int		i;
	int		j;
	char	**res;

	if (!tab1)
		return (tab2);
	else if (!tab2)
		return (tab1);
	len = tab_len(tab1) + tab_len(tab2) + 1;
	res = malloc(sizeof(char *) * len);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (tab1[i])
		res[j++] = tab1[i++];
	i = 0;
	while (tab2[i])
		res[j++] = tab2[i++];
	res[j] = NULL;
	return (res);
}

// Objectif: Checker si il s'agit d'une chaine de caracteres ou d'un chiffre,
// dans les 2 cas on concatene.
char	**parse(int argc, char **argv)
{
	int		i;
	char	**result;
	char	**split;
	char	*tmp[2];

	i = 1;
	result = NULL;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			split = ft_split(argv[i], ' ');
			result = join_arrays(result, split);
		}
		else
		{
			tmp[0] = argv[i];
			tmp[1] = NULL;
			result = join_arrays(result, tmp);
		}
		i++;
	}
	return (result);
}
/*
int	main(int argc, char **argv)
{
	int		i;
	char	**res;

	i = 0;
	if (argc < 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	res = parse(argc, argv);
	if (!res)
		return (1);
	while (res[i])
	{
		printf("%s", res[i]);
		printf("\n");
		i++;
	}
	return (0);
}*/

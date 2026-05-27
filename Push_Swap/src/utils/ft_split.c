/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:13:43 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/27 20:13:44 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c1, char c2)
{
	return (c1 == c2);
}

static int	count_mots(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], c) == 0
			&& (i == 0 || is_sep(str[i - 1], c) != 0))
			count++;
		i++;
	}
	return (count);
}

static char	*copy_word(char *str, char c, int *i)
{
	int		j;
	char	*word;

	j = *i;
	while (str[j] && is_sep(str[j], c) == 0)
		j++;
	word = malloc(sizeof(char) * (j - *i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (str[*i] && is_sep(str[*i], c) == 0)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

static void	free_tab(char **tab, int k)
{
	while (k > 0)
		free(tab[--k]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_mots((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c) != 0)
			i++;
		if (!s[i])
			break ;
		tab[k] = copy_word((char *)s, c, &i);
		if (!tab[k++])
			return (free_tab(tab, k), NULL);
	}
	tab[k] = 0;
	return (tab);
}

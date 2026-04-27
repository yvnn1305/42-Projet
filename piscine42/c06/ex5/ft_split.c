/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:19:04 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/23 17:19:08 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_lettre(char *str, char *charset, int i)
{
	int	count;

	count = 0;
	while (str[i] && is_sep(charset, str[i]) == 0)
	{
		count++;
		i++;
	}
	return (count);
}

int	count_mots(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_sep(charset, str[i]) == 0
			&& (i == 0 || is_sep(charset, str[i - 1]) == 1))
			count++;
		i++;
	}
	return (count);
}

char	*copy_word(char *str, char *charset, int *i)
{
	int		j;
	int		len;
	char	*word;

	len = count_lettre(str, charset,*i);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (str[*i] && is_sep(charset, str[*i]) == 0)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	int		j;
	char	**tab;

	i = 0;
	k = 0;
	if (!str || !charset)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_mots(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_sep(charset, str[i]) == 1)
			i++;
		if (str[i])
			tab[k++] = copy_word(str, charset, &i);
	}
	tab[k] = 0;
	return (tab);
}

/*int    main(void)
{    int    i = 0;
    char    **tab;
    tab = ft_split("-;\n--;", "-;\n");
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}*/
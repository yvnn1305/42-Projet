/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:20:44 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 14:09:35 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	parse_clues(char *str, int clues[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		clues[j] = str[i] - '0';
		i += 2;
		j++;
	}
}
// The function convert the input string into the clues array.
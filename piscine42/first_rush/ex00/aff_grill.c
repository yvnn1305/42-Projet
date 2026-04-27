/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_grill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:18:29 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 14:39:17 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	aff_grill(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
//		This function will display the result of the puzzle by
//		looking what is stored in the grid
//
// 		We go through the grid line by line using two loops.
//		The first loop goes through the rows (i)
//		The second loop goes through the columns (j)
//
//		Each number in the grid is converted to a character
//		by adding '0' so it can be printed.
//
//		A space is printed between numbers except for the 
//		last number of the line.
//		After printing a row, we print a new line to go to the next line.

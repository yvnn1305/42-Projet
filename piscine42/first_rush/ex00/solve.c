/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:15:22 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/17 15:50:18 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
// Initialize the grid by setting all cells to "0"
// This represents an empty puzzle before the solver fills it.

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	value;

	if (pos == 16)
		return (verif(grid, clues));
	row = pos / 4;
	col = pos % 4;
	value = 1;
	while (value <= 4)
	{
		if (check_row(grid, row, value)
			&& check_col(grid, col, value))
		{
			grid[row][col] = value;
			if (solve(grid, clues, pos + 1))
				:return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
//	Solve the puzzle using backtracking.
//	For each position, try values from 1 to 4,
//	If the value resptects the row and the column rules, move to the next
//	cell. If the no value works, go back and try another one.

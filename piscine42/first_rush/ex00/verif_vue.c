/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_vue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:10:25 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 14:10:38 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_up(int grid[4][4], int clues[16], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 0;
	max = 0;
	visible = 0;
	while (row < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible == clues[col]);
}
//	Check how many buildings are visible from the top side, we go through
// 	the row and count a building when it is taller than all the previous ones.

int	check_down(int grid[4][4], int clues[16], int col)
{
	int	row;
	int	max;
	int	visible;

	row = 3;
	max = 0;
	visible = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible == clues[4 + col]);
}
//	Same logic as check_up but from the bottom side, We start from,
//	the last row and count visible buildings.

int	check_left(int grid[4][4], int clues[16], int row)
{
	int	col;
	int	max;
	int	visible;

	col = 0;
	max = 0;
	visible = 0;
	while (col < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible == clues[8 + row]);
}
//	Same logic as check_bottom but from the left side, We start from,
//	the first column and count visible buildings.

int	check_right(int grid[4][4], int clues[16], int row)
{
	int	col;
	int	max;
	int	visible;

	col = 3;
	max = 0;
	visible = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible == clues[12 + row]);
}
//	Same logic as check_left but from the right side, We start from,
//	the last column and count visible buildings.

int	verif(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_left(grid, clues, i))
			return (0);
		if (!check_right(grid, clues, i))
			return (0);
		if (!check_up(grid, clues, i))
			return (0);
		if (!check_down(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}
//	This function is just the central tower of all our checker
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:45:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 14:25:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_row(int grid[4][4], int row, int value)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == value)
			return (0);
		col++;
	}
	return (1);
}

int	check_col(int grid[4][4], int col, int value)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == value)
			return (0);
		row++;
	}
	return (1);
}
//	Those functions are here for check if we found the number we are trying,
// 	to put in cell 2 times.
//	We create temporally row or col only for "swim" inside the row or the,
//	column.
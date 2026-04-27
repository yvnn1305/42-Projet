/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:35:30 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 15:48:35 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (1);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (1);
		if (i % 2 == 1 && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

// This function will check the input,
// if there is the good numbers of characters,
// and if the space and numbers are on their good index.

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || check_error(argv[1]))
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	parse_clues(argv[1], clues);
	init_grid(grid);
	if (solve(grid, clues, 0))
		aff_grill(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
//		Here the first condition will check if the number of arguments is 2,
//		if there's not the program will return "Error",
//		and if check_error detects an error in the input.

//		This function is the "Brain" of the program, 
//		he will call the function we need for resolve the puzzle.

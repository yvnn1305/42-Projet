/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:22:20 by yakombo-          #+#    #+#             */
/*   Updated: 2026/03/15 14:39:04 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>

int		check_error(char *str);
int		check_row(int grid[4][4], int row, int value);
int		check_col(int grid[4][4], int col, int value);
int		verif(int grid[4][4], int clues[16]);
int		solve(int grid[4][4], int clues[16], int pos);

void	parse_clues(char *str, int clues[16]);
void	init_grid(int grid[4][4]);
void	aff_grill(int grid[4][4]);
#endif

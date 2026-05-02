/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:22:53 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:22:54 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);

	ft_putchar_fd('H', fd);
	ft_putchar_fd('i', fd);
	ft_putchar_fd('\n', fd);
	close (fd);
}*/

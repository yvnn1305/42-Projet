/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:23:42 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 20:23:43 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);

	ft_putstr_fd("Hello\nJe m'appelle Yann\n", fd);
	close (fd);
}*/

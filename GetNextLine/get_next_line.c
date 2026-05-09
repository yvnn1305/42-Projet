/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:41:57 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/08 22:57:49 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line()
{
	
}

char	*get_next_line(int fd)
{
	char		stock[BUFFER_SIZE + 1];
	ssize_t		bytes;
	static char	*stash;
	char		*n1;

	bytes = read(fd, stock, BUFFER_SIZE);
	stock[bytes] = '\0';
	while (bytes > 0)
	{
		if (ft_strchr(stock, '\n') == NULL)
		{
			stash = malloc(sizeof(char) * ft_strlen(stock));
				ft_memcpy(stash, stock, bytes);
		}
		else
		{
			n1 = ft_strchr(stock, '\n');
		}
		stock[bytes] = '\0';
		bytes = read(fd, stock, BUFFER_SIZE);
	}
}

char	*get_stash(char const *s, ssize_t bytes)
{
	static char	*stash;
	
	stash = 
}
/*char *get_next_line(int fd)
{
	char	buf[7];
	read(fd, buf, 6);
	printf("%s\n", buf);
	return (0);
}*/

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY, 0644);
	if (fd < 0)
		return (1);
	get_next_line(fd);
}
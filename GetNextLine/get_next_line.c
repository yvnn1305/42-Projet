/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:41:57 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/15 22:21:59 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_stash(char *stash, char *buf, ssize_t bytes, int fd)
{
	char	*tmp;

	stash = stash_append(stash, buf, bytes);
	if (!stash)
		return (NULL);
	while (bytes > 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
	}
	free(buf);
	return (stash);
}

char	*get_line(char *stash, int fd)
{
	char	*buf;
	ssize_t	bytes;

	if (stash && ft_strchr(stash, '\n'))
		return (stash);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	stash = ft_update_stash(stash, buf, bytes, fd);
	return (stash);
}

char	*stash_split(char *stash)
{
	char	*res;
	int		len;

	len = ft_strchr(stash, '\n') - stash + 1;
	res = malloc(sizeof(char) * (len + 1));
	ft_memcpy(res, stash, len);
	res[len] = '\0';
	return (res);
}

char	*stash_trim(char *stash)
{
	char	*tmp;
	char	*after_newl;
	char	*new_stash;
	int		stash_len;

	tmp = stash;
	after_newl = ft_strchr(stash, '\n') + 1;
	stash_len = ft_strlen(after_newl);
	if (stash_len == 0)
	{
		free(tmp);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (stash_len + 1));
	ft_memcpy(new_stash, after_newl, stash_len);
	new_stash[stash_len] = '\0';
	free(tmp);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	stash = get_line(stash, fd);
	if (!stash || !ft_strchr(stash, '\n'))
	{
		line = stash;
		stash = NULL;
		return (line);
	}
	line = stash_split(stash);
	stash = stash_trim(stash);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY, 0644);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/

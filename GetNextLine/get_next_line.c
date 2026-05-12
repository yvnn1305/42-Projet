/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:41:57 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/10 17:36:36 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_update_stash(char *stash, char *buf, ssize_t bytes, int fd)
{
	char	*tmp;
	
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * (bytes + 1));
		if (!stash)
			return (NULL);
		ft_memcpy(stash, buf, bytes);
		stash[bytes] = '\0';
	}
	while (bytes > 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
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

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);	
	printf("bytes: %zd\n", bytes);
	stash = ft_update_stash(stash, buf, bytes, fd);
	printf("stash: %s\n", stash);
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
	printf("res: %s\n", res);
	return (res);
}

char	*stash_trim(char *stash)
{
	char	*tmp;
	char	*stash_trim;
	char	*new_stash;
	int		stash_len;

	tmp = stash;
	stash_trim = ft_strchr(stash, '\n') + 1;
	stash_len = ft_strlen(stash_trim);
	new_stash = malloc(sizeof(char) * (stash_len + 1));
	ft_memcpy(new_stash, stash_trim, stash_len);
	new_stash[stash_len] = '\0';
	free(tmp);
	printf("new_stash: %s\n", new_stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

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
	printf("line: %s\n", line);
	return (line);
}

int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY, 0644);
	if (fd < 0)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
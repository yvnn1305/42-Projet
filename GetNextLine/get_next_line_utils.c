/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:59:41 by yakombo-          #+#    #+#             */
/*   Updated: 2026/05/15 22:20:47 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	if (!dest && !srcs)
		return (0);
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dest);
}

char	*stash_append(char *stash, char *buf, ssize_t bytes)
{
	char	*tmp;
	char	*new_stash;

	buf[bytes] = '\0';
	if (stash == NULL)
	{
		if (bytes == 0)
			return (NULL);
		new_stash = malloc(sizeof(char) * (bytes + 1));
		if (!new_stash)
			return (NULL);
		ft_memcpy(new_stash, buf, bytes);
		new_stash[bytes] = '\0';
		return (new_stash);
	}
	tmp = stash;
	new_stash = ft_strjoin(stash, buf);
	free(tmp);
	return (new_stash);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
		res[j++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/21 06:24:36 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
		temp[i++] = 0;
	s = temp;
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		copied;
	const char	*s_begin = src;

	copied = 0;
	if ((dst == 0) || (src == 0))
		return (0);
	while ((*src != 0) && (copied < (dstsize - 1)) && (dstsize != 0))
	{
		*dst = *src;
		copied++;
		src++;
		dst++;
	}
	if (dstsize != 0)
		*dst = 0;
	while (*src != 0)
		src++;
	return (src - s_begin);
}

static char	*read_data(int fd, char **line, int *readed)
{
	char	*endl;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	char	*last_part;

	ft_bzero(buffer, (BUFFER_SIZE + 1));
	last_part = 0;
	while ((*readed) > 0)
	{
		tmp = *line;
		*line = ft_strjoin_with_free(tmp, buffer);
		endl = ft_strchr(*line, 10);
		if (endl)
		{
			tmp = ft_strndup(*line, (endl - (*line)));
			if (ft_strlen(endl) > 1)
				last_part = ft_strdup(endl + 1);
			free(*line);
			*line = tmp;
			return (last_part);
		}
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		*readed = read(fd, buffer, BUFFER_SIZE);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	file[BUFFER_SIZE + 1] = {0};
	int			readed;
	size_t		len;
	char		*left_data;

	readed = 1;
	len = 0;
	left_data = 0;
	if ((fd < 0) || (!line) || (BUFFER_SIZE < 1) || (read(fd, file, 0) < 0))
		return (-1);
	*line = 0;
	len = ft_strlen(file);
	if (len)
		*line = ft_strndup(file, len);
	ft_bzero(file, (BUFFER_SIZE + 1));
	left_data = read_data(fd, line, &readed);
	if (left_data)
		ft_strlcpy(file, left_data, (BUFFER_SIZE + 1));
	free(left_data);
	if (readed > 1)
		return (1);
	return (readed);
}

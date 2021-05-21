/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/20 23:57:37 by jkasongo         ###   ########.fr       */
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

static char	*read_data(int fd, char **line, int *readed)
{
	char	*endl;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	buffer[0] = 0;
	tmp = 0;
	while ((*readed) > 0)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buffer);
		free(tmp);
		endl = ft_strchr(*line, 10);
		if (endl)
		{
			tmp = ft_strndup(*line, (endl - *line));
			free(*line);
			*line = tmp;
			return (ft_strdup(endl + 1));
		}
		ft_bzero(buffer, BUFFER_SIZE);
		*readed = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = 0;
	}
	return (0);
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

int	get_next_line(int fd, char **line)
{
	static char	file[BUFFER_SIZE + 1];
	int			readed;
	int			check;
	char		*tmp;

	readed = 1;
	if ((fd < 0) || (!line) || (BUFFER_SIZE < 1) || (read(fd, file, 0) < 0))
		return (-1);
	*line = 0;
	if (file[0] != 0)
		*line = ft_strdup(file);
	tmp = read_data(fd, line, &readed);
	if (!tmp)
		ft_bzero(file, BUFFER_SIZE);
	else
		check = ft_strlcpy(file, tmp, (BUFFER_SIZE + 1));
	free(tmp);
	if (readed > 1)
		return (1);
	return (readed);
}

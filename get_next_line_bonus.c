/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/20 19:41:38 by jkasongo         ###   ########.fr       */
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

int	get_next_line(int fd, char **line)
{
	static char	*file[MAX_FD];
	int			readed;

	readed = 1;
	if ((fd < 0) || (!line) || (BUFFER_SIZE < 1) || (read(fd, file, 0) < 0))
		return (-1);
	*line = 0;
	if (file[fd])
		*line = file[fd];
	file[fd] = read_data(fd, line, &readed);
	if (readed > 1)
		return (1);
	return (readed);
}
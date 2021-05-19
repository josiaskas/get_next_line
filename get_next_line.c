/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/19 15:55:02 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = 0;
	if (!s)
		return (0);
	while (*s != 0)
	{
		if (*s == c)
			found = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (found);
}

static int	read_data(int fd, char *line, char *lst_part)
{
	int		readed;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	char	*endl;

	readed = 1;
	while (readed > 0)
	{
		tmp = line;
		endl = ft_strrchr(tmp, '\n');
		if (endl)
		{
			line = ft_strndup(tmp, (endl - tmp));
			free(lst_part);
			lst_part = ft_strdup(endl + 1);
			if (!line || !lst_part)


			break ;
		}
		line = ft_strjoin(tmp, buffer);
		if (line == 0)
			return (-1);
		free(tmp);
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE + 1] = 0;
	}
	return (readed);
}

int	get_next_line(int fd, char **line)
{
	static char	*file[MAX_FD] = {0};
	char		*lst_part;
	char		*tmp;
	int			check;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE < 1))
		return (-1);
	if (file[fd])
	{
		lst_part = ft_strdup(file[fd]);
		*line = lst_part;
		check = read_data(fd, *line, lst_part);
	}
	else
		lst_part = 0;
	check = read_data(fd, *line, lst_part);
	free(lst_part);
}

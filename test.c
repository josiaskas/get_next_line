/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:30:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/20 16:11:56 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		ret;
	char	*line;

	fd = STDIN_FILENO;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			fd = STDIN_FILENO;
	}
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
	}
	close(fd);
	return (0);
}

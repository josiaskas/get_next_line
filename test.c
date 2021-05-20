/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:30:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/20 15:00:12 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*line[400];

	fd = STDIN_FILENO;
	i = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			fd = STDIN_FILENO;
	}
	while (get_next_line(fd, line) > 0)
	{
		printf("%s\n", *line);
	}
	printf("fin");
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 23:35:07 by charmstr          #+#    #+#             */
/*   Updated: 2021/05/21 06:04:54 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 32
#include "./get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		res;

	line = NULL;
	if ((fd = open("get_next_line.c", O_RDONLY)) == -1)
	{
		printf("failed to open the fd\n");
		return (0);
	}
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (res == 0)
		free(line);
	return (0);
}

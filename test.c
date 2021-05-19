/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:40:20 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 19:55:39 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		err;
	char	**line;

	fd = STDIN_FILENO;
	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
	}
	err = get_next_line(fd, line);
	return (0);
}

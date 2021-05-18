/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:26:13 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 15:41:43 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_chunk
{
	char			*string;
	struct s_chunk	*next;
}	t_chunk;

t_chunk *make_chunk(char *string);
t_chunk	*last_chunk(t_chunk *chunk);
void	add_chunk(t_chunk **first, t_chunk *new_chunk);
char	*ft_strrchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
int		get_next_line(int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:26:01 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 15:17:38 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_chunk	*make_chunk(char *string)
{
	t_chunk	*chunk;

	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	chunk->string = string;
	chunk->next = 0;
	return (chunk);
}

void	add_chunk(t_chunk **first, t_chunk *new_chunk)
{
	t_chunk *chunk;

	if (*first)
	{
		chunk = ft_lstlast(*first);
		chunk->next = &*new_chunk;
	}
	else
		*first = new_chunk;
}

t_chunk	*last_chunk(t_chunk *chunk)
{
	while (chunk)
	{
		if (chunk->next == 0)
			return (chunk);
		chunk = chunk->next;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char *found;

	found = 0;
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

char	*ft_strndup(const char *s1, size_t n)
{
	char *heap_p;
	char *p;

	heap_p = malloc(n + 1);
	if (!heap_p)
		return (0);
	p = heap_p;
	while ((*s1 != 0) && (n--))
		*p++ = *s1++;
	*p = '\0';
	return (heap_p);
}

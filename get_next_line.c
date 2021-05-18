/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 15:41:52 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static char	*make_line(t_chunk *chunk, size_t max_size)
{
	char	*line;

	if (!chunk)
		return (0);
	line = malloc(max_size + 1);
	if (!line)
		return (0);
	ft_bzero(line, (max_size + 1));
	while (chunk)
	{
		ft_strcat(line, chunk->string);
		free(chunk->string);
		chunk = chunk->next;
	}
	return (line);
}

static size_t	read_data(int fd, t_chunk **first, size_t *nbr)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*endl;
	size_t	byte_readed;
	t_chunk	*chunk;

	while (byte_readed = read(fd, &buffer, BUFFER_SIZE))
	{
		buffer[byte_readed] = 0;
		endl = ft_strrchr(&buffer, '\n');
		if (endl != 0)
		{
			chunk = make_chunk(ft_strndup(buffer, (endl - buffer)));
			nbr += (size_t)(endl - buffer);
			add_chunk(first, chunk);
			break ;
		}
		chunk = make_chunk(ft_strndup(buffer, byte_readed));
		nbr += byte_readed;
		add_chunk(first, chunk);
	}
	return (byte_readed);
}

int	get_next_line(int fd, char **line)
{
	t_chunk	**first_chunk;
	size_t	nbr_byte_line;
	size_t	reading;
	t_chunk	*tmp;

	first_chunk = 0;
	reading = read_data(fd, first_chunk, &nbr_byte_line);
	*line = make_line(*first_chunk, nbr_byte_line);
	while (*first_chunk)
	{
		tmp = (*first_chunk)->next;
		free(*first_chunk);
		*first_chunk = tmp;
	}
	if ((reading == -1) || (reading == 0))
		return ((int)reading);
	else
		return (1);
}

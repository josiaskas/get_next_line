/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:25:51 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 19:45:58 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
		temp[i++] = 0;
	s = temp;
}

char	*ft_strcat(char *dest, char *src)
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

static char	*make_line(t_list *chunk, size_t max_size)
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
		ft_strcat(line, chunk->content);
		free(chunk->content);
		chunk = chunk->next;
	}
	return (line);
}

static long	read_data(int fd, t_list **first, size_t *nbr)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*endl;
	long	byte_readed;
	t_list	*chunk;

	while ((byte_readed = read(fd, &buffer, BUFFER_SIZE)))
	{
		buffer[byte_readed] = 0;
		endl = ft_strrchr(&buffer[0], '\n');
		if (endl != 0)
		{
			chunk = ft_lstnew(ft_strndup(&buffer[0], (endl - buffer)));
			if (!chunk)
				return (-1);
			nbr += (size_t)(endl - buffer);
			ft_lstadd_back(first, chunk);
			break ;
		}
		chunk = ft_lstnew(ft_strndup(&buffer[0], byte_readed));
		if (!chunk)
			return (-1);
		nbr += byte_readed;
		ft_lstadd_back(first, chunk);
	}
	return (byte_readed);
}

int	get_next_line(int fd, char **line)
{
	t_list	**first_chunk;
	size_t	nbr_byte_line;
	int		reading;
	t_list	*tmp;

	first_chunk = 0;
	reading = read_data(fd, first_chunk, &nbr_byte_line);
	if (reading == -1)
	{
		*line = NULL;
		return (-1);
	}
	*line = make_line(*first_chunk, nbr_byte_line);
	while (*first_chunk)
	{
		tmp = (*first_chunk)->next;
		free(*first_chunk);
		*first_chunk = tmp;
	}
	if (reading == 0)
		return (reading);
	return (1);
}

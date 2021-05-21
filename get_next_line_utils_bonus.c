/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:26:01 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/21 05:56:59 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if ((s < d) && (d < (s + len)))
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*heap_p;
	char	*p;

	heap_p = malloc(n + 1);
	if (!heap_p)
		return (0);
	p = heap_p;
	while ((*s1 != 0) && (n--))
		*p++ = *s1++;
	*p = '\0';
	return (heap_p);
}

char	*ft_strdup(const char *s1)
{
	char	*heap_p;
	char	*p;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	heap_p = malloc(len + 1);
	if (!heap_p)
		return (0);
	p = heap_p;
	while (*s1 != 0)
		*p++ = *s1++;
	*p = '\0';
	return (heap_p);
}

char	*ft_strjoin_with_free(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*heap_p;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	heap_p = malloc(len1 + len2 + 1);
	if (!heap_p)
		return (0);
	ft_memmove(heap_p, s1, len1);
	ft_memmove((heap_p + len1), s2, len2);
	heap_p[len1 + len2] = 0;
	free(s1);
	return (heap_p);
}

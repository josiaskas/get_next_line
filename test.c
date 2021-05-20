#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#define MAX_FD 65535

//utils libft
char *ft_strndup(const char *s1, size_t n);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);

int get_next_line(int fd, char **line);

#endif
#include <fcntl.h>
#include <stdio.h>

static void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;

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

char *ft_strdup(const char *s1)
{
	char *heap_p;
	char *p;
	size_t len;

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

char *ft_strndup(const char *s1, size_t n)
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

static size_t ft_strlen(const char *s)
{
	size_t i;

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

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;
	char *heap_p;

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
	return (heap_p);
}

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
void	ft_bzero(void *s, size_t n)
{
	size_t i;
	unsigned char *temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
		temp[i++] = 0;
	s = temp;
}

static char	*read_data(int fd, char **line, int *readed)
{
	char	*endl;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	buffer[0] = 0;
	tmp = 0;
	while ((*readed) > 0)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buffer);
		free(tmp);
		if ((endl = ft_strchr(*line, 10)))
		{
			tmp = ft_strndup(*line, (endl - *line));
			free(*line);
			*line = tmp;
			return (ft_strdup(endl + 1));
		}
		ft_bzero(buffer, BUFFER_SIZE);
		*readed = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*file[MAX_FD];
	int			readed;

	readed = 1;
	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE < 1))
		return (-1);
	*line = 0;
	if (file[fd])
		*line = file[fd];
	file[fd] = read_data(fd, line, &readed);
	return (readed);
}

int main(int argc, char *argv[])
{
	int fd;
	int i;
	char *line[400];

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
	close(fd);
	return (0);
}

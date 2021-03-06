/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:26:13 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/21 05:57:34 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 151
# endif

# define MAX_FD 65535

//utils libft
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_with_free(char *s1, char const *s2);

int		get_next_line(int fd, char **line);

#endif

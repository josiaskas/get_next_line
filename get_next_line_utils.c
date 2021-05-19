/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:26:01 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/18 19:31:28 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list *link;

	link = (t_list *)malloc(sizeof(t_list));
	if (!link)
		return (0);
	link->content = content;
	link->next = 0;
	return (link);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *link;

	if (*alst)
	{
		link = ft_lstlast(*alst);
		link->next = &*new;
	}
	else
		*alst = new;
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

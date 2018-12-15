/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:26:37 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/29 19:26:42 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_skip_char(char const **as, char c)
{
	while (**as == c)
		++(*as);
}

static int	ft_word_len(char const *s, char c)
{
	int		word_len;

	word_len = 0;
	while (*s && *s != c)
	{
		++word_len;
		++s;
	}
	return (word_len);
}

static void	del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

t_list		*ft_strsplit_lst(char const *s, char c)
{
	t_list	*new_begin;
	t_list	*last;
	int		word_len;

	ft_skip_char(&s, c);
	if (!(word_len = ft_word_len(s, c)))
		return (NULL);
	if (!(new_begin = ft_lstnew(ft_strsub(s, 0, word_len), word_len + 1)))
		return (NULL);
	s += word_len;
	ft_skip_char(&s, c);
	last = new_begin;
	while ((word_len = ft_word_len(s, c)))
	{
		if (!(last->next = ft_lstnew(ft_strsub(s, 0, word_len), word_len + 1)))
		{
			ft_lstdel(&new_begin, &del);
			return (NULL);
		}
		last = last->next;
		s += word_len;
		ft_skip_char(&s, c);
	}
	return (new_begin);
}

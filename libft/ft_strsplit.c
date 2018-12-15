/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:31:36 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/10 13:31:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		word_count;

	while (*s == c)
		++s;
	word_count = 0;
	while (*s)
	{
		++word_count;
		while (*s && *s != c)
			++s;
		while (*s == c)
			++s;
	}
	return (word_count);
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

static void	ft_free_str_array(char **p)
{
	while (*p)
		free(*(p++));
	free(p);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		word_count;
	int		i;
	int		word_len;

	word_count = ft_word_count(s, c);
	new = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (new)
	{
		i = 0;
		while (i < word_count)
		{
			while (*s == c)
				++s;
			word_len = ft_word_len(s, c);
			if ((new[i++] = ft_strsub(s, 0, word_len)) == NULL)
			{
				ft_free_str_array(new);
				return (NULL);
			}
			s += word_len;
		}
		new[i] = NULL;
	}
	return (new);
}
